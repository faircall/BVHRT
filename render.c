#include "render.h"

Ray intersect_tri(Ray ray, Tri tri)
{
    
    Ray result;
    
    result.origin = ray.origin;
    result.direction = ray.direction;
    result.t = 1e30f;

    float epsilon = 0.0001f;
    
    // get two edges of the triangle to take
    // cross product with incoming ray
    // to detect angle between them
    
    Vec3 edge1 = vec3_sub(tri.v1,tri.v0);
    Vec3 edge2 = vec3_sub(tri.v2,tri.v0);

    Vec3 h = vec3_cross(ray.direction, edge2);
    float a = vec3_dot(edge1, h);

    if (a > (-1.0f*epsilon) && a < epsilon) {
	// basically parallel up to fp error
	return result;
    }

    float f = 1.0f / a;
    Vec3 s = vec3_sub(ray.origin, tri.v0);
    float u = f * vec3_dot(s, h);

    if (u < 0.0f || u > 1.0f) {
	return result;
    }

    Vec3 q = vec3_cross(s, edge1);
    float v = f * vec3_dot(ray.direction, q);
    if ((v < 0.0f) || ((v + u) > 1.0f)) {
	return result;
    }

    float t = f * vec3_dot(edge2, q);
    if (t > epsilon) {	
	result.t = t;
    }
    return result;
}

void drawWorld(SDLPlatform platform, World world)
{
    SDL_SetRenderDrawColor(platform.renderer, 0xff, 0x00, 0x00, 0x00);
    SDL_RenderClear(platform.renderer);
    // update our framebuffer, then copy it

    // temp code to be pulled into a function

    // think carefully about these, common source of confusion
    Vec3 cameraPos = {.x = 0.0f, .y = 0.0f, .z = -100.0f};
    Vec3 p0 = {.x = -1.0f, .y = 1.0f, .z = -90.0f};
    Vec3 p1 = {.x = 1.0f, .y = 1.0f, .z = -90.0f};
    Vec3 p2 = {.x = -1.0f, .y = -1.0f, .z = -90.0f};
    
    Vec3 h = vec3_sub(p1, p0);
    Vec3 v = vec3_sub(p2, p0);
    Ray ray;
    unsigned int triCounter = 0;
    for (unsigned int i = 0; i < platform.screenWidth; i++) {
	for (unsigned int j = 0; j < platform.screenHeight; j++) {
	    // could this be precomputed?
	    Vec3 pixelPos = vec3_add(p0, vec3_add(vec3_scale((float)i / (float)platform.screenWidth, h), vec3_scale((float)j / (float)platform.screenHeight, v)));
	    
	    
	    ray.origin = cameraPos;
	    ray.direction = vec3_normalize(vec3_sub(pixelPos, ray.origin));
	    ray.t = 1e30f;
	    platform.frameBuffer[i + (j*platform.screenWidth)] = 0xff00ff00;
	    for (unsigned int k = 0; k < world.triCount; k++) {
		// test intersection
		Ray rayResult = intersect_tri(ray, world.tris[k]);
		if (rayResult.t < ray.t) {
		    //triCounter++;
		    //printf("tri counter is %d\n", triCounter);
		    // color the framebuffer
		    platform.frameBuffer[i + (j*platform.screenWidth)] = 0xffff0000;
		} 
		
	    }

	    
	}
    }
    printf("intersected %d\n triangles this pass\n", triCounter);

    SDL_UpdateTexture(platform.frameTexture, NULL, platform.frameBuffer, 4 * platform.screenWidth);

    SDL_RenderCopy(platform.renderer, platform.frameTexture, NULL, NULL);
    
    SDL_RenderPresent(platform.renderer);
}

