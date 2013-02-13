#include "Text.h"

Text::Text(int x, int y, std::string TEXT, int ptSize)
{
    //ctor
    text = TEXT;
    pos.x = x;
    pos.y = y;

    font = TTF_OpenFont("Files\\Font.ttf", ptSize);

    color.r = 255;
    color.g = 255;
    color.b = 255;

    msg = TTF_RenderText_Solid(font, text.c_str(), color);
}

void Text::Update()
{
    SDL_BlitSurface(msg, 0, SDL_GetVideoSurface(), &pos);
}

Text::~Text()
{
    //dtor
}
