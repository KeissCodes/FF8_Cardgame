#include "button.h"
#include <cairo.h>

Button::Button(int xPos, int yPos, int width, int height, const RGBColor& color, const std::string& text, int textShiftX, int textShiftY) : _xPos(xPos), _yPos(yPos), _width(width), _height(height), _color(color), _text(text), _textShiftX(textShiftX), _textShiftY(textShiftY)
{

}

void Button::draw(cairo_t *cr)
{
    cairo_set_source_rgb(cr, _color.red, _color.green, _color.blue); 
    cairo_rectangle(cr, _xPos, _yPos, _width, _height);
    cairo_fill(cr);

    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, 20.0);
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_move_to(cr, _xPos + _textShiftX, _yPos + _textShiftY);
    cairo_show_text(cr, _text.c_str());
}

bool Button::tryClick(int xPos, int yPos)
{
    if(xPos >= _xPos && yPos >= _yPos && xPos < _xPos + _width && yPos < _yPos + _height)
        return true;
    return false;
}