#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL.h>
#include "sdl_platform.h"
#include "render.h"
#include "sim.h"


int main()
{
    int screenWidth = 1280;
    int screenHeight = 720;
    
    SDLPlatform platform = init_sdl(SDL_INIT_EVERYTHING, screenWidth, screenHeight, "bvh ray");

    int loopResult = main_loop(platform);

    
    if (loopResult) {
	printf("some error occured in the game loop\n");
	return loopResult;
    }
    
    
    return 0;
}

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

int main_loop(SDLPlatform platform)
{
    bool run = true;
    World currentWorldState = init_world();
    
    World nextWorldState;
    
    while (run) {
	float dt = ((float)SDL_GetTicks())/1000.0f; // this is a timer function that can be abstracted

	nextWorldState = update_world(currentWorldState, dt);
	currentWorldState = nextWorldState;
	
	drawWorld(platform, nextWorldState);
    }
}


