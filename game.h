#ifndef GAME_H
#define GAME_H

#include <cairo.h>
#include <vector>
#include <memory>
#include "deck.h"
#include "card.h"
#include "player.h"
#include "board.h"
#include "button.h"

enum class GameState{
    PLAYER_1,
    PLAYER_2
};

class Game {
public:
    Game();
    void draw(cairo_t *cr);
    void handle_click(double x, double y);
    void giveCards();

private:
    Player _playerA;
    Player _playerB;
    Deck _deck;
    Board _board;
    Button _restartButton;

    GameState _currentState = GameState::PLAYER_1;
};

#endif // GAME_H
