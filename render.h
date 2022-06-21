
#ifndef RENDER_H
#define RENDER_H
#include "g_common.h"
#include <SDL.H>
#include "sdl_platform.h"
#include "sim.h"




typedef struct {
    Vec3 origin;
    Vec3 direction;
    float t;
} Ray;



void drawWorld(SDLPlatform platform, World world);

#endif
