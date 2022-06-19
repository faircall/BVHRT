#include "render.h"

void drawWorld(SDLPlatform platform, World world)
{
    SDL_SetRenderDrawColor(platform.renderer, 0xff, 0x00, 0x00, 0x00);
    SDL_RenderClear(platform.renderer);
    // update our framebuffer, then copy it

    SDL_RenderCopy(platform.renderer, platform.frameTexture, NULL, NULL);
    
    SDL_RenderPresent(platform.renderer);
}

