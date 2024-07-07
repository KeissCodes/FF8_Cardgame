#include "player.h"
#include <iostream>
#include <stdexcept>
#include <cairo.h>
#include "board.h"

Player::Player(int xPos, int yPos, const RGBColor& color, Board* board) : _hand(), _xPos(xPos), _yPos(yPos), _color(color), _board(board) {

}

void Player::clear(){
    _hand.clear();
    _nextCardPositionY = 0;
}

#define HAND_VERTICAL_DRAW_OFFSET CARD_SIZE + 5

void Player::addCard(std::unique_ptr<Card> card) {
    _hand.push_back(std::move(card));
    _hand.back()->setCardHolder(this);
    _hand.back()->setCardOwner(this);
    int cardYPosition = _nextCardPositionY;
    _hand.back()->setPosition(0, cardYPosition);
    _nextCardPositionY = cardYPosition + HAND_VERTICAL_DRAW_OFFSET;
}

std::pair<int,int> Player::getPosition(){
    return {_xPos, _yPos};
}

std::unique_ptr<Card> Player::playCard(size_t index) {
    // Überprüfen ob der Index gültig ist
    if (index >= _hand.size()) {
        throw std::out_of_range("Index out of range");
    }

    // Transferiere die Ownership der Karte und entferne sie aus der Hand
    std::unique_ptr<Card> playedCard = std::move(_hand[index]);
    _hand.erase(_hand.begin() + index);

    return playedCard;
}

const std::vector<std::unique_ptr<Card>>& Player::getHand() const {
    return _hand;
}

void Player::drawHand(cairo_t *cr){
    for (size_t i = 0; i < _hand.size(); i++){
        _hand[i]->draw(cr);
    }
}

const RGBColor& Player::getColor() const{
    return _color;
}

bool Player::userClick(int x, int y){
    // Zunächst schauen ob eine Karte Selektiert wurde
    for(size_t i = 0; i < _hand.size(); i++)
    {
        if(_hand[i]->clicked(x,y)){
            selectCard(i);
            return false;
        }
    }

    // Danach schauen ob ein Feld am Brett Selektiert wurde
    if(_selectedCard == -1){
        return false;
    }

    bool placedCard = _board->tryPlaceCard(x, y, _hand[_selectedCard]);
    if(placedCard){
        _hand.erase(_hand.begin() + _selectedCard);
        _selectedCard = -1;
        return true;
    }

    return false;
}

void Player::resetSelection(){
    for(auto& card : _hand)
    {
        card->setSelected(false);
    };
}

void Player::selectCard(size_t index){
    _selectedCard = index;
    resetSelection();
    _hand[index]->setSelected(true);
}