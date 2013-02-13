#ifndef CANNON_H
#define CANNON_H

#include <SDL.h>
#include <SDL_image.h>

class Cannon
{
    public:
        Cannon(SDL_Rect& tank, int id);
        ~Cannon();
        void Update(SDL_Rect& tank);
        SDL_Surface* src;
        SDL_Rect pos;

        SDL_Rect view;
        SDL_Rect views[4];

        enum Direction
        {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };
        Direction direction;

        int getDir()
        {
            switch(direction)
            {
                case UP:
                    return 0;
                    break;
                case LEFT:
                    return 1;
                    break;
                case DOWN:
                    return 2;
                    break;
                case RIGHT:
                    return 3;
                    break;
            }
            return 0;
        }

        enum TANK_ID
        {
            Default,
            Red,
            Blue,
            Green,
            Yellow,
            Purple
        };
};

#endif // CANNON_H
