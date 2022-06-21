#ifndef SDL_PLATFORM_H
#define SDL_PLATFORM_H
#include <SDL.h>
#include <stdbool.h>


typedef struct {
    bool created;
    unsigned int screenWidth;
    unsigned int screenHeight;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *frameTexture;
    unsigned int *frameBuffer;
} SDLPlatform;

SDLPlatform init_sdl(unsigned int initFlags, int screenWidth, int screenHeight, char *title);

#endif
