#ifndef WORLD_H
#define WORLD_H

#include <SDL2/SDL.h>

#define WORLD_WIDTH 40
#define WORLD_HEIGHT 20

extern int world[WORLD_HEIGHT][WORLD_WIDTH];

void init_world();
void render_world(SDL_Renderer* renderer);
void break_block(int x, int y);
void place_block(int x, int y);

#endif
