#include "world.h"

int world[WORLD_HEIGHT][WORLD_WIDTH];

void init_world() {
    for (int y = 0; y < WORLD_HEIGHT; y++) {
        for (int x = 0; x < WORLD_WIDTH; x++) {
            world[y][x] = (y > 15) ? 1 : 0;  // dirt layer at bottom
        }
    }
}

void render_world(SDL_Renderer* renderer) {
    int blockSize = 32;
    for (int y = 0; y < WORLD_HEIGHT; y++) {
        for (int x = 0; x < WORLD_WIDTH; x++) {
            if (world[y][x] == 1) {
                SDL_Rect block = { x * blockSize, y * blockSize, blockSize, blockSize };
                SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255); // brown
                SDL_RenderFillRect(renderer, &block);
            }
        }
    }
}

void break_block(int x, int y) {
    if (x >= 0 && x < WORLD_WIDTH && y >= 0 && y < WORLD_HEIGHT)
        world[y][x] = 0;
}

void place_block(int x, int y) {
    if (x >= 0 && x < WORLD_WIDTH && y >= 0 && y < WORLD_HEIGHT)
        world[y][x] = 1;
}
