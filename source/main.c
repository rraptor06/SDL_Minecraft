#include <SDL2/SDL.h>
#include <stdbool.h>
#include "world.h"
#include "player.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

typedef enum {
    NO,
    YES
} QUIT_MODE;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("WiiU Minecraft",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    init_world();
    init_steve();

    int quit = NO;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = YES;
        }

        const Uint8* keystate = SDL_GetKeyboardState(NULL);
        update_steve(keystate);

        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255); // sky blue
        SDL_RenderClear(renderer);

        render_world(renderer);
        render_steve(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
