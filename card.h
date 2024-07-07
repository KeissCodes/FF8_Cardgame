#ifndef CARD_H
#define CARD_H

#include <string>
#include <cairo.h>
#include <utility>

#define CARD_SIZE 128

class Player;

class CardHolder{
    public:
    virtual std::pair<int,int> getPosition() = 0;
};

class Card {
public:
    Card(const std::string &name, int up, int right, int down, int left, const std::string &element, int rarity, const std::string &img_path);
    ~Card();
    Card(const Card&) = delete;
    Card& operator=(const Card&) = delete;


    void setCardHolder(CardHolder* cardHolder);

    void setCardOwner(Player* cardOwner);

    Player* getCardOwner();

    void draw(cairo_t *cr);

    std::string getName() const;
    int getUp() const;
    int getRight() const;
    int getDown() const;
    int getLeft() const;
    std::string getElement() const;
    int getRarity() const;
    std::string getImagePath() const;

    void setPosition(int x, int y);

    void setSelected(bool selected);

    bool clicked(int x, int y);

private:
    std::pair<int,int> getAbsolutPosition();

    std::string _name;
    int _up, _right, _down, _left;
    std::string _element;
    int _rarity;
    std::string _img_path;
    cairo_surface_t* _image;

    bool _selected = false;
    int _xPos = 0;
    int _yPos = 0;
    CardHolder* _cardHolder = nullptr;
    Player* _cardOwner = nullptr;
};

#endif // CARD_H
