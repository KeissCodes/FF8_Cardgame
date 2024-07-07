#include "game.h"
#include "draw.h"

#define CARDS_PER_PLAYER 5

Game::Game() : _deck(), _playerA(160,34,{0.2,0.2,0.8}, &_board), _playerB(992,34,{0.8,0.2,0.2}, &_board), _board(448, 168, &_playerA, &_playerB), _restartButton(1280 / 2 - 100, 50, 200, 70, {0.8, 0.8, 0.8}, "Restart", 65, 43) {
    giveCards();
}

void Game::giveCards(){
    _deck.shuffle();
    
    for(size_t i = 0; i < CARDS_PER_PLAYER * 2; i++){
        if(i % 2 == 0) // Player A bekommt eine Karte
        {
            _playerA.addCard(_deck.drawCard());
        }
        else // Player B bekommt eine Karte
        {
            _playerB.addCard(_deck.drawCard());
        }
    }
}

void Game::draw(cairo_t *cr) {
    _board.draw(cr);
    _playerA.drawHand(cr);
    _playerB.drawHand(cr);
    _restartButton.draw(cr);
}

void Game::handle_click(double x, double y) {
    bool placedCard = false;
    if(_currentState == GameState::PLAYER_1)
    {
        placedCard = _playerA.userClick(x,y);
    }
    else if(_currentState == GameState::PLAYER_2){
        placedCard = _playerB.userClick(x,y);
    }

    if(placedCard){
        // Karten Eigentümer überprüfen

        if(_currentState == GameState::PLAYER_2)
            _currentState = GameState::PLAYER_1;
        else{
            _currentState = GameState::PLAYER_2;
        }
    }

    if(_restartButton.tryClick(x,y)){
        _board.clear();
        _playerA.clear();
        _playerB.clear();
        _deck = Deck();
        giveCards();
    }

    redraw();
}
