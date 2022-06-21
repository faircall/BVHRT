#include <SDL.h>
#include "render.h"
#include "g_common.h"

#ifndef SIM_H
#define SIM_H

// why can't I include sdl_platform.h?



typedef struct {
    Tri *tris;
    unsigned int triCount;
} World;

World init_world(unsigned int triCount);
World update_world(World currentWorldState, float dt);

#endif
