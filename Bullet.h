#ifndef BULLET_H
#define BULLET_H

#include <SDL.h>
#include <SDL_image.h>
#include "Tank.h"

class Bullet
{
    public:
        Bullet(SDL_Rect& tank, int dir);
        ~Bullet();
        SDL_Surface* src;
        SDL_Rect pos;
        void Update();
        enum Direction
        {
            UP,
            LEFT,
            DOWN,
            RIGHT
        };
        Direction direction;
        bool alive;
};

#endif // BULLET_H
