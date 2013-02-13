#include "Tank.h"

Tank::Tank(int x, int y, int NUM, int PLAYER_NUM)
{
    //ctor
    src = IMG_Load("Files\\Tanks and Cannons\\Tank_Default.png");
    pos.x = x;
    pos.y = y;
    health = 100;

    _VAL = 0;

    switch(NUM)
    {
        case Default:
            src = IMG_Load("Files\\Tanks and Cannons\\Tank_Default.png");
            break;
        case Red:
            src = IMG_Load("Files\\Tanks and Cannons\\Red\\Red_Tank.png");
            break;
        case Green:
            src = IMG_Load("Files\\Tanks and Cannons\\Green\\Green_Tank.png");
            break;
        case Blue:
            src = IMG_Load("Files\\Tanks and Cannons\\Blue\\Blue_Tank.png");
            break;
        case Purple:
            src = IMG_Load("Files\\Tanks and Cannons\\Purple\\Purple_Tank.png");
            break;
        case Yellow:
            src = IMG_Load("Files\\Tanks and Cannons\\Yellow\\Yellow_Tank.png");
            break;
    }

    switch(PLAYER_NUM)
    {
        case 1:
            outlineRect.x = 2;
            outlineRect.y = 2;
            healthOut.x = 2;
            healthOut.y = 695;
            break;
        case 2:
            outlineRect.x = 122;
            outlineRect.y = 2;
            healthOut.x = 122;
            healthOut.y = 695;
            break;
        case 3:
            outlineRect.x = 242;
            outlineRect.y = 2;
            healthOut.x = 242;
            healthOut.y = 695;
        case 4:
            outlineRect.x = 362;
            outlineRect.y = 2;
            healthOut.x = 362;
            healthOut.y = 695;
        default:
            outlineRect.x = 2;
            outlineRect.y = 2;
            healthOut.x = 2;
            healthOut.y = 695;
    }

    views[0].x = 0;
    views[0].y = 0;
    views[0].w = 80;
    views[0].h = 80;

    views[1].x = 80;
    views[1].y = 0;
    views[1].w = 80;
    views[1].h = 80;

    view = views[0];
    direction = UP_DOWN;
    up = down = left = right = false;
    cannon = new Cannon(pos, NUM);


    outlineRect.w = 104;
    outlineRect.h = 24;
    healthOut.w = 104;
    healthOut.h = 24;

    chrgPos.x = outlineRect.x + 2;
    chrgPos.y = outlineRect.y + 2;
    chrgPos.w = 100;
    chrgPos.h = 20;

    chrg.x = chrgPos.x;
    chrg.y = chrgPos.y;
    chrg.w = 100;
    chrg.h = 20;

    healthRect.x = healthOut.x + 2;
    healthRect.y = healthOut.y + 2;
    healthRect.w = health;
    healthRect.h = 20;

    healthPos.x = healthRect.x;
    healthPos.y = healthRect.y;
    healthPos.w = 100;
    healthPos.h = 20;

    srand(time(NULL));
}

void Tank::Update(bool AI)
{
    if(_VAL <= 400)
        _VAL++;

    chrg.w = _VAL / 4;
    healthRect.w = health;
    vals[0] = 255;
    vals[1] = 200 - (_VAL / 4);
    vals[2] = 0;
    vals[3] = (_VAL / 4) + 155;

    if(direction == UP_DOWN)
        view = views[0];
    else if(direction == LEFT_RIGHT)
        view = views[1];

    if(up)
    {
        pos.y--; view = views[0];
    }
    else if(down)
    {
        pos.y++; view = views[0];
    }
    else if(left)
    {
        pos.x--; view = views[1];
    }
    else if(right)
    {
        pos.x++; view = views[1];
    }

    SDL_BlitSurface(src, &view, SDL_GetVideoSurface(), &pos);
    cannon->Update(pos);

    SDL_FillRect(SDL_GetVideoSurface(), &outlineRect, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
    SDL_FillRect(SDL_GetVideoSurface(), &healthOut, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));

    SDL_FillRect(SDL_GetVideoSurface(), &chrgPos, SDL_MapRGB(SDL_GetVideoSurface()->format, 50, 50, 50));
    SDL_FillRect(SDL_GetVideoSurface(), &healthPos, SDL_MapRGB(SDL_GetVideoSurface()->format, 50, 50, 50));

    SDL_FillRect(SDL_GetVideoSurface(), &healthRect, SDL_MapRGB(SDL_GetVideoSurface()->format, 255, 0, 0));
    SDL_FillRect(SDL_GetVideoSurface(), &chrg, SDL_MapRGBA(SDL_GetVideoSurface()->format, vals[0], vals[1], vals[2], vals[3]));

    /* Artificial Intelligence */
    if(AI)
    {

    }
}

/*
void Tank::SHOOT(std::vector<Bullet*>& bullets)
{
    if(_VAL >= 400)
    {
        _VAL = 0;
        Bullet bullet(pos, cannon->getDir());
        bullets.push_back(new Bullet(pos, cannon->getDir()));
    }
}
*/

Tank::~Tank()
{
    //dtor
}
