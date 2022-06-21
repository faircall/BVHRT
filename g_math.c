#include "g_math.h"


Vec3 vec3_scale(float l, Vec3 in)
{
    Vec3 result = {.x = in.x * l, .y = in.y * l, .z = in.z * l};
    return result;
}

Vec3 vec3_add(Vec3 a, Vec3 b)
{
    Vec3 result = {.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z};
    return result;
}

Vec3 vec3_sub(Vec3 a, Vec3 b)
{
    // computes a - b
    Vec3 result = {.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z};
    return result;
}

float vec3_magnitude(Vec3 in)
{
    return sqrt(in.x*in.x + in.y*in.y + in.z*in.z);
}

Vec3 vec3_normalize(Vec3 in)
{
    float mag = vec3_magnitude(in);
    if (mag == 0) {
	return in;
    }
    float invMag = 1.0f / mag;
    Vec3 result = vec3_scale(invMag, in);
    return result;
}

float vec3_dot(Vec3 a, Vec3 b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vec3 vec3_cross(Vec3 a, Vec3 b)
{
    Vec3 result;
    result.x = a.y*b.z - a.z*b.y;
    result.y = a.z*b.x - a.x*b.z;
    result.z = a.x*b.y - a.y*b.x;
    return result;
}
