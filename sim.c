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
	Vec3 r0 = {(float)(rand()%10)/5.0f, (float)(rand()%10)/5.0f, (float)(rand()%10)/5.0f};
	Vec3 r1 = {(float)(rand()%10)/5.0f, (float)(rand()%10)/5.0f, (float)(rand()%10)/5.0f};
	Vec3 r2 = {(float)(rand()%10)/5.0f, (float)(rand()%10)/5.0f, (float)(rand()%10)/5.0f};
	Vec3 fives = {2.0f, 2.0f, 0.0f};
	Vec3 v0 = vec3_sub(vec3_scale(2.0f, r0), fives);
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
