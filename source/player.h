#ifndef STEVE_H
#define STEVE_H

#include <SDL2/SDL.h>

void init_steve();
void update_steve(const Uint8* keystate);
void render_steve(SDL_Renderer* renderer);

#endif
