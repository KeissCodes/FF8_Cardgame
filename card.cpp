#include "card.h"
#include <iostream>
#include <cassert>
#include "player.h"

static cairo_surface_t* createScaledCairoImage(const std::string& path, int width, int height) {
    cairo_surface_t* image_surface = cairo_image_surface_create_from_png(path.c_str());
    
    if (cairo_surface_status(image_surface) != CAIRO_STATUS_SUCCESS) {
        return nullptr;
    }
    
    cairo_surface_t* scaled_surface = cairo_surface_create_similar(
        image_surface, CAIRO_CONTENT_COLOR_ALPHA, width, height);
    
    cairo_t* cr = cairo_create(scaled_surface);
    
    cairo_scale(cr, (double)width / cairo_image_surface_get_width(image_surface),
                (double)height / cairo_image_surface_get_height(image_surface));
    cairo_set_source_surface(cr, image_surface, 0, 0);
    cairo_paint(cr);
    
    cairo_destroy(cr);
    cairo_surface_destroy(image_surface);
    
    return scaled_surface;
}

Card::Card(const std::string &name, int up, int right, int down, int left, const std::string &element, int rarity, const std::string &img_path)
    : _name(name), _up(up), _right(right), _down(down), _left(left), _element(element), _rarity(rarity), _img_path(img_path) {
    _image = createScaledCairoImage(_img_path.c_str(), CARD_SIZE, CARD_SIZE);
    if (cairo_surface_status(_image) != CAIRO_STATUS_SUCCESS) {
        std::cerr << "Failed to load image: " << _img_path << std::endl;
    }
}

Card::~Card() {
    cairo_surface_destroy(_image);
}

void Card::setCardHolder(CardHolder* cardHolder){
    _cardHolder = cardHolder;
}

void Card::setCardOwner(Player* cardOwner){
    _cardOwner = cardOwner;
}

Player* Card::getCardOwner(){
    return _cardOwner;
}


void Card::draw(cairo_t *cr) {
        
    auto absCardPosition = getAbsolutPosition();

    // Kartenhintergrund
    auto bg = _cardOwner->getColor();
    cairo_set_source_rgb(cr, bg.red, bg.green, bg.blue); 
    cairo_rectangle(cr, absCardPosition.first, absCardPosition.second, CARD_SIZE, CARD_SIZE);
    cairo_fill(cr);

    // Kartenbild
    cairo_set_source_surface(cr, _image, absCardPosition.first, absCardPosition.second);
    cairo_paint(cr);

    // KartenText
    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, 20.0);
    cairo_set_source_rgb(cr, 1, 1, 1);  // Farbe Schwarz
    cairo_move_to(cr, absCardPosition.first + 64, absCardPosition.second + 20);
    cairo_show_text(cr, std::to_string(_up).c_str());

    cairo_move_to(cr, absCardPosition.first + 64, absCardPosition.second + 128 - 10);
    cairo_show_text(cr, std::to_string(_down).c_str());

    cairo_move_to(cr, absCardPosition.first + 10, absCardPosition.second + 64 );
    cairo_show_text(cr, std::to_string(_left).c_str());

    cairo_move_to(cr, absCardPosition.first + 128 - 20, absCardPosition.second + 64 );
    cairo_show_text(cr, std::to_string(_right).c_str());

    if(_selected){
        cairo_set_source_rgb(cr, 1, 0.84, 0);  // Gold
        cairo_set_line_width(cr, 3);
        cairo_rectangle(cr, absCardPosition.first, absCardPosition.second, CARD_SIZE, CARD_SIZE);
        cairo_stroke(cr);    
    }
}

std::string Card::getName() const {
    return _name;
}

int Card::getUp() const {
    return _up;
}

int Card::getRight() const {
    return _right;
}

int Card::getDown() const {
    return _down;
}

int Card::getLeft() const {
    return _left;
}

std::string Card::getElement() const {
    return _element;
}

int Card::getRarity() const {
    return _rarity;
}

std::string Card::getImagePath() const {
    return _img_path;
}

void Card::setPosition(int x, int y){
    _xPos = x;
    _yPos = y;
}

void Card::setSelected(bool selected){
    _selected = selected;
}

bool Card::clicked(int x, int y){
    auto absCardPosition = getAbsolutPosition();

    if( x >= absCardPosition.first && y >= absCardPosition.second && 
        x < absCardPosition.first + CARD_SIZE && y < absCardPosition.second + CARD_SIZE)
    {
        return true;
    }

    return false;
}

std::pair<int,int> Card::getAbsolutPosition(){
    assert (_cardHolder != nullptr);

    auto cardHolderPos = _cardHolder->getPosition();
    auto cardPosition = std::pair<int, int>();
    cardPosition.first = cardHolderPos.first + _xPos;
    cardPosition.second = cardHolderPos.second + _yPos;
    return cardPosition;
}
