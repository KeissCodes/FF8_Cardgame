#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <gtk/gtk.h>
#include "card.h"
#include <memory>
#include "player.h"

class Board : public CardHolder{
public:
    Board(int xPos, int yPos, Player* playerA, Player* playerB);
    void draw(cairo_t *cr);
    std::pair<int,int> getPosition() final;

    // Versucht eine Karte am Feld zu Platzieren
    // Liefert true falls erfolgreich
    bool tryPlaceCard(int x, int y, std::unique_ptr<Card>& card);

    void checkCardOwnerChanges(int yIndex, int xIndex);

    void clear();

private:
    cairo_surface_t* _image;

    int getPlayerScore(Player* player);

    std::unique_ptr<Card> _grid[3][3];

    Player* _playerA;
    Player* _playerB;

    int _xPos;
    int _yPos;
};

#endif // BOARD_H
