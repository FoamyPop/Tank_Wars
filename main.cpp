#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>
#include <string>
#include <sstream>

#include "Tank.h"
#include "Text.h"
#include "Bullet.h"

SDL_Surface* Window;
const int Width = 1280;
const int Height = 720;
const int Bits = 32;
void shoot(Tank& tank);

SDL_Surface* background;
std::vector<Bullet*> bullets;
Tank* TANK;
Uint32 Firing_Delay = 2000; //ms
int _Val;

int DIRECTION = 0;

SDL_Surface* IMAGE(const char* filename)
{
    SDL_Surface* a = IMG_Load(filename);
    SDL_Surface* b = SDL_DisplayFormat(a);
    SDL_FreeSurface(a);
    return b;
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

Mix_Music* song;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING); /* Initialize SDL */
    TTF_Init();
    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
    song = Mix_LoadMUS("Files\\Song.mp3");
    Mix_PlayMusic(song, 100);

    Window = SDL_SetVideoMode(Width, Height, Bits, SDL_SWSURFACE); /* Initialize The Window */
    SDL_WM_SetCaption("Tank Wars", NULL);
    Uint32 start = SDL_GetTicks();

    background = IMAGE("Files\\Back_Default.png");

    TANK = new Tank(550, 340, Red, 1);
    Tank enemy1(40, 200, Purple, 2);

    Text help(0, 600, "devmode - test build", 15);

    bool running = true;
    while(running)
    {
        SDL_Event event;
        DIRECTION = TANK->cannon->getDir();

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_w)
                    {
                        TANK->direction = Tank::UP_DOWN;
                        TANK->up = true;
                    }
                    else if(event.key.keysym.sym == SDLK_s)
                    {
                        TANK->direction = Tank::UP_DOWN;
                        TANK->down = true;
                    }
                    else if(event.key.keysym.sym == SDLK_a)
                    {
                        TANK->direction = Tank::LEFT_RIGHT;
                        TANK->left = true;
                    }
                    else if(event.key.keysym.sym == SDLK_d)
                    {
                        TANK->direction = Tank::LEFT_RIGHT;
                        TANK->right = true;
                    }

                    if(event.key.keysym.sym == SDLK_UP)
                    {
                        TANK->cannon->direction = Cannon::UP;
                    }
                    else if(event.key.keysym.sym == SDLK_DOWN)
                    {
                        TANK->cannon->direction = Cannon::DOWN;
                    }
                    else if(event.key.keysym.sym == SDLK_LEFT)
                    {
                        TANK->cannon->direction = Cannon::LEFT;
                    }
                    else if(event.key.keysym.sym == SDLK_RIGHT)
                    {
                        TANK->cannon->direction = Cannon::RIGHT;
                    }

                    if(event.key.keysym.sym == SDLK_SPACE)
                    {
                        shoot(*TANK);
                    }
                    break;
                case SDL_KEYUP:
                    if(event.key.keysym.sym == SDLK_w)
                    {
                        TANK->up = false;
                        TANK->direction = Tank::UP_DOWN;
                    }
                    else if(event.key.keysym.sym == SDLK_s)
                    {
                        TANK->down = false;
                        TANK->direction = Tank::UP_DOWN;
                    }
                    else if(event.key.keysym.sym == SDLK_a)
                    {
                        TANK->left = false;
                        TANK->direction = Tank::LEFT_RIGHT;
                    }
                    else if(event.key.keysym.sym == SDLK_d)
                    {
                        TANK->right = false;
                        TANK->direction = Tank::LEFT_RIGHT;
                    }
                    break;
            }
        }
        SDL_FillRect(Window, 0, SDL_MapRGB(Window->format, 0, 0, 0));
        SDL_BlitSurface(background, 0, Window, 0);
        for(unsigned int i = 0; i < bullets.size(); i++)
        {
            bullets[i]->Update();
            if(bullets[i]->alive == false)
            {
                delete bullets[i];
                bullets.erase(bullets.begin() + (i - 1));
            }
        }
        TANK->Update(false);
        enemy1.Update(true);
        help.Update();
        SDL_Flip(Window);

        if(60/1000 > (SDL_GetTicks() - start))
            SDL_Delay(60/1000 - (SDL_GetTicks() - start));
    }

    SDL_Quit();
    return 0;
}

void shoot(Tank& tank)
{
    if(tank._VAL >= 400)
    {
        tank._VAL = 0;
        bullets.push_back(new Bullet(tank.pos, tank.cannon->getDir()));
    }
}
