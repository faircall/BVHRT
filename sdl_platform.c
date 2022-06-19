#include <SDL.h>
#include "sdl_platform.h"

SDLPlatform init_sdl(unsigned int initFlags, int screenWidth, int screenHeight, char *title)
{
    SDLPlatform result = {.created = false, .screenWidth = screenWidth, .screenHeight = screenHeight,
	.window = NULL, .renderer = NULL};
    if (SDL_Init(initFlags)) {
	printf("couldn't init sdl\n");
	return result;
    }
    if (SDL_CreateWindowAndRenderer(screenWidth, screenHeight, 0, &(result.window), &(result.renderer))) {
	printf("couldn't create window/renderer\n");
	return result;
    }

    result.frameTexture = SDL_CreateTexture(result.renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, screenWidth, screenHeight);
    result.frameBuffer = (unsigned int*)malloc(screenWidth * screenHeight * sizeof(unsigned int));

    for (int i = 0; i < screenWidth * screenHeight; i++) {
	result.frameBuffer[i] = 0xff0000ff;
    }

    SDL_UpdateTexture(result.frameTexture, NULL, result.frameBuffer, 4 * screenWidth, NULL);

    
    
    return result;
}
