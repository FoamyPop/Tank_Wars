#include "Cannon.h"

Cannon::Cannon(SDL_Rect& tank, int id)
{
    //ctor
    src = IMG_Load("Files\\Tanks and Cannons\\Cannon_Default.png");
    pos.x = tank.x + 11;
    pos.y = tank.y - 31;
    direction = UP;

    switch(id)
    {
        case Default:
            src = IMG_Load("Files\\Tanks and Cannons\\Cannon_Default.png");
            break;
        case Red:
            src = IMG_Load("Files\\Tanks and Cannons\\Red\\Red_Cannon.png");
            break;
        case Green:
            src = IMG_Load("Files\\Tanks and Cannons\\Green\\Green_Cannon.png");
            break;
        case Blue:
            src = IMG_Load("Files\\Tanks and Cannons\\Blue\\Blue_Cannon.png");
            break;
        case Purple:
            src = IMG_Load("Files\\Tanks and Cannons\\Purple\\Purple_Cannon.png");
            break;
        case Yellow:
            src = IMG_Load("Files\\Tanks and Cannons\\Yellow\\Yellow_Cannon.png");
            break;
    }

    views[0].x = 0;
    views[0].y = 0;
    views[0].w = 59;
    views[0].h = 101;

    views[1].x = 59;
    views[1].y = 0;
    views[1].w = 59;
    views[1].h = 101;

    views[2].x = 118;
    views[2].y = 0;
    views[2].w = 101;
    views[2].h = 59;

    views[3].x = 219;
    views[3].y = 0;
    views[3].w = 101;
    views[3].h = 59;

    view = views[0];
}

void Cannon::Update(SDL_Rect& tank)
{
    if(direction == UP)
    {
        pos.x = tank.x + 11;
        pos.y = tank.y - 31;
        view = views[0];
    }
    else if(direction == DOWN)
    {
        pos.x = tank.x + 11;
        pos.y = tank.y + 10;
        view = views[1];
    }
    else if(direction == LEFT)
    {
        pos.x = tank.x - 30;
        pos.y = tank.y + 10;
        view = views[3];
    }
    else if(direction == RIGHT)
    {
        pos.x = tank.x + 11;
        pos.y = tank.y + 10;
        view = views[2];
    }

    SDL_BlitSurface(src, &view, SDL_GetVideoSurface(), &pos);
}

Cannon::~Cannon()
{
    //dtor
}
