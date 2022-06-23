#include "sim.h"
#include "g_math.h"
#include <stdlib.h>

World update_world(World currentWorldState, float dt)
{

    World result = currentWorldState;

    return result;
}

World init_world(unsigned int triCount)
{
    World result;
    
    result.triCount = triCount;
    result.tris = (Tri*)malloc(triCount * sizeof(Tri));

    for (int i = 0; i < triCount; i++) {
	Tri current;
	Vec3 r0 = {(float)rand()/(float)RAND_MAX, (float)rand()/(float)RAND_MAX, (float)rand()/(float)RAND_MAX}; 
	Vec3 r1 = {(float)rand()/(float)RAND_MAX, (float)rand()/(float)RAND_MAX, (float)rand()/(float)RAND_MAX}; 
	Vec3 r2 = {(float)rand()/(float)RAND_MAX, (float)rand()/(float)RAND_MAX, (float)rand()/(float)RAND_MAX}; 
	Vec3 fives = {5.0f, 5.0f, 5.0f};
	
	Vec3 v0 = vec3_sub(vec3_scale(9.0f, r0), fives);
	Vec3 v1 = vec3_add(v0, r1);
	Vec3 v2 = vec3_add(v0, r2);

	
	Vec3 centroid = {.x = (v0.x + v1.x + v2.x) / 3.0f,
	    .y = (v0.y + v1.y + v2.y) / 3.0f,
	    .z = (v0.z + v1.z + v2.z) / 3.0f};

	current.v0 = v0;
	current.v1 = v1;
	current.v2 = v2;
	current.centroid = centroid;


	result.tris[i] = current;
    }

    return result;
}

World hardcode_world()
{
    World result;

    result.triCount = 4;
    result.tris = (Tri*)malloc(result.triCount * sizeof(Tri));


    // first 
    Vec3 v0 = {.x = -5.0f, .y = 10.0f, .z = 0.0f};
    Vec3 v1 = {.x = -10.0f, .y = 0.5f, .z = 0.0f};
    Vec3 v2 = {.x = -0.5f, .y = 0.5f, .z = 0.0f};
    Vec3 centroid = vec3_scale(0.333f, vec3_add(v0, vec3_add(v1, v2)));

    Tri current;
    current.v0 = v0;
    current.v1 = v1;
    current.v2 = v2;
    current.centroid = centroid;

    result.tris[0] = current;

    // second

    v0 = (Vec3){.x = 0.0f, .y = 10.0f, .z = 0.0f};
    v1 = (Vec3){.x = 5.5f, .y = 0.5f, .z = 0.0f};
    v2 = (Vec3){.x = -5.0f, .y = 0.5f, .z = 0.0f};
    centroid = vec3_scale(0.333f, vec3_add(v0, vec3_add(v1, v2)));
    current.v0 = v0;
    current.v1 = v1;
    current.v2 = v2;
    current.centroid = centroid;
    result.tris[1] = current;
    

    // third

    v0 = (Vec3){.x = 1.0f, .y = -0.5f, .z = 0.0f};
    v1 = (Vec3){.x = 0.5f, .y = -1.0f, .z = 0.0f};
    v2 = (Vec3){.x = 1.5f, .y = -1.0f, .z = 0.0f};
    centroid = vec3_scale(0.333f, vec3_add(v0, vec3_add(v1, v2)));
    current.v0 = v0;
    current.v1 = v1;
    current.v2 = v2;
    current.centroid = centroid;
    result.tris[2] = current;

    // fourth

    v0 = (Vec3){.x = 1.0f, .y = 1.0f, .z = 0.0f};
    v1 = (Vec3){.x = 0.5f, .y = 0.5f, .z = 0.0f};
    v2 = (Vec3){.x = 1.5f, .y = 0.5f, .z = 0.0f};
    centroid = vec3_scale(0.333f, vec3_add(v0, vec3_add(v1, v2)));
    current.v0 = v0;
    current.v1 = v1;
    current.v2 = v2;
    current.centroid = centroid;
    result.tris[3] = current;

    return result;    
}
