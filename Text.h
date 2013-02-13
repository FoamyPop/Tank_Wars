#ifndef TEXT_H
#define TEXT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Text
{
    public:
        Text(int x, int y, std::string TEXT, int ptSize);
        ~Text();
        void Update();
        void set(std::string t)
        {
            msg = TTF_RenderText_Solid(font, t.c_str(), color);
        }

        TTF_Font* font;

        SDL_Rect pos;
        SDL_Surface* msg;
        SDL_Color color;
        std::string text;
};

#endif // TEXT_H
