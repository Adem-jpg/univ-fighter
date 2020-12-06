#ifndef EVENTS_HPP
#define EVENTS_HPP

#include "commun.hpp"
#include "player.hpp"
#include "logic.hpp"
#include "graphic.hpp"

void handle_events(SDL_Event* events,game_t* game, textures_t* textures,Player *p1);

#endif