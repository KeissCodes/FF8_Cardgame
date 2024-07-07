#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>
#include "card.h"
#include "color.h"

class Board;

class Player : public CardHolder {
public:
    Player(int xPos, int yPos, const RGBColor& color, Board* board);
    void addCard(std::unique_ptr<Card> card);
    std::unique_ptr<Card> playCard(size_t index);
    const std::vector<std::unique_ptr<Card>>& getHand() const;

    std::pair<int,int> getPosition() final;

    void drawHand(cairo_t *cr);

    const RGBColor& getColor() const;

    bool userClick(int x, int y);

    void clear();

private:
    std::vector<std::unique_ptr<Card>> _hand;
    int _nextCardPositionY = 0;
    int _xPos;
    int _yPos;
    RGBColor _color;
    Board* _board;

    void resetSelection();

    void selectCard(size_t index);

    int _selectedCard = -1;
};

#endif // PLAYER_H
