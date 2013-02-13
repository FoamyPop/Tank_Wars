#include "Bullet.h"

Bullet::Bullet(SDL_Rect& tank, int dir)
{
    //ctor
    src = IMG_Load("Files\\Shell.png");
    pos.x = tank.x + 38;
    pos.y = tank.y + 37;
    alive = true;

    switch(dir)
    {
        case 0:
            direction = UP;
            pos.y -= 41;
            break;
        case 1:
            direction = LEFT;
            pos.x -= 41;
            break;
        case 2:
            direction = DOWN;
            pos.y += 41;
            break;
        case 3:
            direction = RIGHT;
            pos.x += 41;
            break;
        default:
            direction = UP;
    }
}

void Bullet::Update()
{
    if(alive)
    {
        int speed = 5;
        switch(direction)
        {
            case UP:
                pos.y -= speed;
                break;
            case DOWN:
                pos.y += speed;
                break;
            case LEFT:
                pos.x -= speed;
                break;
            case RIGHT:
                pos.x += speed;
                break;
        }

        if(pos.x <= 0 || pos.x >= 1300 || pos.y <= 0 || pos.y >= 750)
            alive = false;

        SDL_BlitSurface(src, 0, SDL_GetVideoSurface(), &pos);
    }
}

Bullet::~Bullet()
{
    //dtor
}
