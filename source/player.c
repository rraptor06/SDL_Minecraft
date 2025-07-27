#include "player.h"
#include "world.h"

static int steve_x = 5;
static int steve_y = 14;

void init_steve() {
    steve_x = 5;
    steve_y = 14;
}

void update_steve(const Uint8* keystate) {
    if (keystate[SDL_SCANCODE_LEFT] && steve_x > 0)
        steve_x--;
    if (keystate[SDL_SCANCODE_RIGHT] && steve_x < WORLD_WIDTH - 1)
        steve_x++;
    if (keystate[SDL_SCANCODE_UP] && steve_y > 0)
        steve_y--;
    if (keystate[SDL_SCANCODE_DOWN] && steve_y < WORLD_HEIGHT - 1)
        steve_y++;

    // Break block
    if (keystate[SDL_SCANCODE_X])
        break_block(steve_x, steve_y + 1);

    // Place block
    if (keystate[SDL_SCANCODE_Z])
        place_block(steve_x, steve_y + 1);
}

void render_steve(SDL_Renderer* renderer) {
    int blockSize = 32;
    SDL_Rect steve = { steve_x * blockSize, steve_y * blockSize, blockSize, blockSize };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // blue
    SDL_RenderFillRect(renderer, &steve);
}
