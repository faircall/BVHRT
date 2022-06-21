#ifndef _G_MATH_H_
#define _G_MATH_H_

#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} Vec3;

Vec3 vec3_scale(float l, Vec3 in);

Vec3 vec3_add(Vec3 a, Vec3 b);

Vec3 vec3_sub(Vec3 a, Vec3 b);

float vec3_magnitude(Vec3 in);

Vec3 vec3_normalize(Vec3 in);

Vec3 vec3_cross(Vec3 a, Vec3 b);

float vec3_dot(Vec3 a, Vec3 b);

#endif
