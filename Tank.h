#ifndef TANK_H
#define TANK_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Cannon.h"
#include "Bullet.h"

using std::vector;

class Tank
{
    public:
        Tank(int x, int y, int NUM, int PLAYER_NUM);
        ~Tank();
        Cannon* cannon;
        void Update(bool AI);
        //void SHOOT(vector<Bullet*>& bullets);

        SDL_Surface* src;
        SDL_Rect pos;
        SDL_Rect view;
        SDL_Rect views[2];
        int health;
        bool up, down, left, right;

        int _VAL;

        enum Direction
        {
            UP_DOWN,
            LEFT_RIGHT
        };
        enum TANK_ID
        {
            Default,
            Red,
            Blue,
            Green,
            Yellow,
            Purple
        };

        Direction direction;
        TANK_ID ID;

        /* Charge Rects */
        SDL_Rect chrgPos;
        SDL_Rect chrg;
        SDL_Rect outlineRect;

        SDL_Rect healthOut;
        SDL_Rect healthRect;
        SDL_Rect healthPos;

        int vals[4];
};

#endif // TANK_H
