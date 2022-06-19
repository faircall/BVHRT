#include "sim.h"

World update_world(World currentWorldState, float dt)
{

    World result = currentWorldState;

    return result;
}

World init_world(void)
{
    World result;
    SDL_Rect testRect = {.x = 200, .y = 200, .w = 50, .h = 50};
    result.test = testRect;

    return result;
}
