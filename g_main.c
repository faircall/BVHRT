#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL.h>
#include "sdl_platform.h"
#include "render.h"
#include "sim.h"


int main_loop(SDLPlatform platform);

int main(int argc, char **argv)
{
    int screenWidth = 320;
    int screenHeight = 200;
    
    SDLPlatform platform = init_sdl(SDL_INIT_EVERYTHING, screenWidth, screenHeight, "bvh ray");

    int loopResult = main_loop(platform);

    
    if (loopResult) {
	printf("some error occured in the game loop\n");
	return loopResult;
    }
    
    
    return 0;
}


int main_loop(SDLPlatform platform)
{
    bool run = true;
    World currentWorldState = init_world(64);
    //World currentWorldState = hardcode_world();
    
    World nextWorldState;
    float lastTime = 0.0f;
    
    while (run) {
	float currentTime = (float)SDL_GetTicks();
	float dt = (currentTime - lastTime) / 1000.0f;
	lastTime = currentTime;
	printf("fps is %f\n", 1.0f / dt);

	nextWorldState = update_world(currentWorldState, dt);
	currentWorldState = nextWorldState;
	
	drawWorld(platform, nextWorldState);
    }

    return 0;
}


