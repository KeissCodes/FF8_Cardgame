#pragma once
#include <cairo.h>
#include "color.h"
#include <string>

class Button{
    public:
    Button(int xPos, int yPos, int width, int height, const RGBColor& color, const std::string& text, int textShiftX, int textShiftY);

    void draw(cairo_t *cr);
    
    bool tryClick(int xPos, int yPos);

    private:
        int _xPos;
        int _yPos;
        int _width;
        int _height;
        RGBColor _color;
        std::string _text;
        int _textShiftX;
        int _textShiftY;
};