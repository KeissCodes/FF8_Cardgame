#ifndef DECK_H
#define DECK_H

#include <vector>
#include <memory>
#include "card.h"

class Deck {
public:
    Deck();
    void shuffle();
    std::unique_ptr<Card> drawCard();
    const std::vector<std::unique_ptr<Card>>& getCards() const;

private:
    std::vector<std::unique_ptr<Card>> cards;
};

#endif // DECK_H
