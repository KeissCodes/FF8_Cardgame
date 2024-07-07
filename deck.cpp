#include "deck.h"
#include <algorithm>
#include <random>

#include "card.h"
#include <memory>


Deck::Deck() : cards() {
    cards.push_back(std::make_unique<Card>("Geezard", 1, 5, 4, 1, "NEUTRAL", 1, "img/cards/001.png"));
    cards.push_back(std::make_unique<Card>("Funguar", 5, 3, 1, 1, "NEUTRAL", 1, "img/cards/002.png"));
    cards.push_back(std::make_unique<Card>("Bite Bug", 1, 5, 3, 3, "NEUTRAL", 1, "img/cards/003.png"));
    cards.push_back(std::make_unique<Card>("Red Bat", 1, 4, 1, 1, "NEUTRAL", 1, "img/cards/004.png"));
    cards.push_back(std::make_unique<Card>("Blobra", 2, 5, 3, 1, "NEUTRAL", 1, "img/cards/005.png"));
    cards.push_back(std::make_unique<Card>("Gayla", 2, 4, 1, 4, "THUNDER", 1, "img/cards/006.png"));
    cards.push_back(std::make_unique<Card>("Gesper", 1, 1, 5, 4, "NEUTRAL", 1, "img/cards/007.png"));
    cards.push_back(std::make_unique<Card>("Fastitocalon-F", 3, 1, 5, 2, "EARTH", 1, "img/cards/008.png"));
    cards.push_back(std::make_unique<Card>("Blood Soul", 2, 1, 1, 6, "NEUTRAL", 1, "img/cards/009.png"));
    cards.push_back(std::make_unique<Card>("Caterchipillar", 4, 3, 2, 4, "NEUTRAL", 1, "img/cards/010.png"));
    cards.push_back(std::make_unique<Card>("Cockatrice", 2, 6, 1, 2, "THUNDER", 1, "img/cards/011.png"));
    cards.push_back(std::make_unique<Card>("Grat", 7, 1, 1, 3, "NEUTRAL", 2, "img/cards/012.png"));
    cards.push_back(std::make_unique<Card>("Buel", 6, 3, 2, 2, "NEUTRAL", 2, "img/cards/013.png"));
    cards.push_back(std::make_unique<Card>("Mesmerize", 5, 4, 3, 3, "NEUTRAL", 2, "img/cards/014.png"));
    cards.push_back(std::make_unique<Card>("Glacial Eye", 6, 3, 1, 4, "ICE", 2, "img/cards/015.png"));
    cards.push_back(std::make_unique<Card>("Belhelmel", 3, 3, 4, 5, "NEUTRAL", 2, "img/cards/016.png"));
    cards.push_back(std::make_unique<Card>("Thrustaevis", 5, 5, 3, 2, "WIND", 2, "img/cards/017.png"));
    cards.push_back(std::make_unique<Card>("Anacondaur", 5, 5, 1, 3, "POISON", 2, "img/cards/018.png"));
    cards.push_back(std::make_unique<Card>("Creeps", 5, 2, 2, 5, "THUNDER", 2, "img/cards/019.png"));
    cards.push_back(std::make_unique<Card>("Grendel", 4, 2, 4, 5, "THUNDER", 2, "img/cards/020.png"));
    cards.push_back(std::make_unique<Card>("Jelleye", 3, 7, 2, 1, "NEUTRAL", 2, "img/cards/021.png"));
    cards.push_back(std::make_unique<Card>("Grand Mantis", 5, 3, 2, 5, "NEUTRAL", 2, "img/cards/022.png"));
    cards.push_back(std::make_unique<Card>("Forbidden", 6, 2, 6, 3, "NEUTRAL", 3, "img/cards/023.png"));
    cards.push_back(std::make_unique<Card>("Armadodo", 6, 6, 3, 1, "EARTH", 3, "img/cards/024.png"));
    cards.push_back(std::make_unique<Card>("Tri-Face", 3, 5, 5, 5, "POISON", 3, "img/cards/025.png"));
    cards.push_back(std::make_unique<Card>("Fastitocalon", 7, 3, 5, 1, "EARTH", 3, "img/cards/026.png"));
    cards.push_back(std::make_unique<Card>("Snow Lion", 7, 3, 1, 5, "ICE", 3, "img/cards/027.png"));
    cards.push_back(std::make_unique<Card>("Ochu", 5, 3, 6, 3, "NEUTRAL", 3, "img/cards/028.png"));
    cards.push_back(std::make_unique<Card>("SAM08G", 5, 4, 6, 2, "FIRE", 3, "img/cards/029.png"));
    cards.push_back(std::make_unique<Card>("Death Claw", 4, 2, 4, 7, "FIRE", 3, "img/cards/030.png"));
    cards.push_back(std::make_unique<Card>("Cactuar", 6, 3, 2, 6, "NEUTRAL", 3, "img/cards/031.png"));
    cards.push_back(std::make_unique<Card>("Tonberry", 3, 4, 6, 4, "NEUTRAL", 3, "img/cards/032.png"));
    cards.push_back(std::make_unique<Card>("Abyss Worm", 7, 5, 2, 3, "EARTH", 3, "img/cards/033.png"));
    cards.push_back(std::make_unique<Card>("Turtapod", 2, 7, 3, 6, "NEUTRAL", 4, "img/cards/034.png"));
    cards.push_back(std::make_unique<Card>("Vysage", 6, 5, 5, 4, "NEUTRAL", 4, "img/cards/035.png"));
    cards.push_back(std::make_unique<Card>("T-Rexaur", 4, 7, 6, 2, "NEUTRAL", 4, "img/cards/036.png"));
    cards.push_back(std::make_unique<Card>("Bomb", 2, 3, 7, 6, "FIRE", 4, "img/cards/037.png"));
    cards.push_back(std::make_unique<Card>("Blitz", 1, 7, 6, 4, "THUNDER", 4, "img/cards/038.png"));
    cards.push_back(std::make_unique<Card>("Wendigo", 7, 6, 3, 1, "NEUTRAL", 4, "img/cards/039.png"));
    cards.push_back(std::make_unique<Card>("Torama", 7, 4, 4, 4, "NEUTRAL", 4, "img/cards/040.png"));
    cards.push_back(std::make_unique<Card>("Imp", 3, 6, 7, 3, "NEUTRAL", 4, "img/cards/041.png"));
    cards.push_back(std::make_unique<Card>("Blue Dragon", 6, 3, 2, 7, "POISON", 4, "img/cards/042.png"));
    cards.push_back(std::make_unique<Card>("Adamantoise", 4, 6, 5, 5, "EARTH", 4, "img/cards/043.png"));
    cards.push_back(std::make_unique<Card>("Hexadragon", 7, 3, 5, 4, "FIRE", 4, "img/cards/044.png"));
    cards.push_back(std::make_unique<Card>("Iron Giant", 6, 5, 5, 6, "NEUTRAL", 5, "img/cards/045.png"));
    cards.push_back(std::make_unique<Card>("Behemoth", 3, 7, 6, 5, "NEUTRAL", 5, "img/cards/046.png"));
    cards.push_back(std::make_unique<Card>("Chimera", 7, 3, 6, 5, "WATER", 5, "img/cards/047.png"));
    cards.push_back(std::make_unique<Card>("PuPu", 3, 1, 10, 2, "NEUTRAL", 5, "img/cards/048.png"));
    cards.push_back(std::make_unique<Card>("Elastoid", 6, 7, 2, 6, "NEUTRAL", 5, "img/cards/049.png"));
    cards.push_back(std::make_unique<Card>("GIM47N", 5, 4, 5, 7, "NEUTRAL", 5, "img/cards/050.png"));
    cards.push_back(std::make_unique<Card>("Malboro", 7, 2, 7, 4, "POISON", 5, "img/cards/051.png"));
    cards.push_back(std::make_unique<Card>("Ruby Dragon", 7, 4, 2, 7, "FIRE", 5, "img/cards/052.png"));
    cards.push_back(std::make_unique<Card>("Elnoyle", 5, 6, 3, 7, "NEUTRAL", 5, "img/cards/053.png"));
    cards.push_back(std::make_unique<Card>("Tonberry King", 4, 4, 6, 7, "NEUTRAL", 5, "img/cards/054.png"));
    cards.push_back(std::make_unique<Card>("Wedge, Biggs", 6, 7, 6, 2, "NEUTRAL", 5, "img/cards/055.png"));
    cards.push_back(std::make_unique<Card>("Fujin Raijin", 2, 4, 8, 8, "NEUTRAL", 6, "img/cards/056.png"));
    cards.push_back(std::make_unique<Card>("Elvoret", 7, 4, 8, 3, "WIND", 6, "img/cards/057.png"));
    cards.push_back(std::make_unique<Card>("X-ATM092", 4, 3, 8, 7, "NEUTRAL", 6, "img/cards/058.png"));
    cards.push_back(std::make_unique<Card>("Granaldo", 7, 5, 2, 8, "NEUTRAL", 6, "img/cards/059.png"));
    cards.push_back(std::make_unique<Card>("Gerogero", 1, 3, 8, 8, "POISON", 6, "img/cards/060.png"));
    cards.push_back(std::make_unique<Card>("Iguion", 8, 2, 2, 8, "NEUTRAL", 6, "img/cards/061.png"));
    cards.push_back(std::make_unique<Card>("Abadon", 6, 5, 8, 4, "NEUTRAL", 6, "img/cards/062.png"));
    cards.push_back(std::make_unique<Card>("Trauma", 4, 6, 8, 5, "NEUTRAL", 6, "img/cards/063.png"));
    cards.push_back(std::make_unique<Card>("Oilboyle", 1, 8, 8, 4, "NEUTRAL", 6, "img/cards/064.png"));
    cards.push_back(std::make_unique<Card>("Shumi", 6, 4, 5, 8, "NEUTRAL", 6, "img/cards/065.png"));
    cards.push_back(std::make_unique<Card>("Krysta", 7, 1, 5, 8, "NEUTRAL", 6, "img/cards/066.png"));
    cards.push_back(std::make_unique<Card>("Propagator", 8, 8, 4, 4, "NEUTRAL", 7, "img/cards/067.png"));
    cards.push_back(std::make_unique<Card>("Jumbo Cactuar", 8, 4, 8, 4, "NEUTRAL", 7, "img/cards/068.png"));
    cards.push_back(std::make_unique<Card>("Tri-Point", 8, 8, 5, 2, "THUNDER", 7, "img/cards/069.png"));
    cards.push_back(std::make_unique<Card>("Gargantua", 5, 8, 6, 6, "NEUTRAL", 7, "img/cards/070.png"));
    cards.push_back(std::make_unique<Card>("Mobile Type 8", 8, 3, 6, 7, "NEUTRAL", 7, "img/cards/071.png"));
    cards.push_back(std::make_unique<Card>("Sphinxara", 8, 8, 3, 5, "NEUTRAL", 7, "img/cards/072.png"));
    cards.push_back(std::make_unique<Card>("Tiamat", 8, 4, 8, 5, "NEUTRAL", 7, "img/cards/073.png"));
    cards.push_back(std::make_unique<Card>("BGH251F2", 5, 5, 7, 8, "NEUTRAL", 7, "img/cards/074.png"));
    cards.push_back(std::make_unique<Card>("Red Giant", 6, 7, 8, 4, "NEUTRAL", 7, "img/cards/075.png"));
    cards.push_back(std::make_unique<Card>("Catoblepas", 1, 7, 8, 7, "NEUTRAL", 7, "img/cards/076.png"));
    cards.push_back(std::make_unique<Card>("Ultima Weapon", 7, 8, 7, 2, "NEUTRAL", 7, "img/cards/077.png"));
    cards.push_back(std::make_unique<Card>("Chubby Chocobo", 4, 9, 4, 8, "NEUTRAL", 8, "img/cards/078.png"));
    cards.push_back(std::make_unique<Card>("Angelo", 9, 3, 6, 7, "NEUTRAL", 8, "img/cards/079.png"));
    cards.push_back(std::make_unique<Card>("Gilgamesh", 3, 6, 7, 9, "NEUTRAL", 8, "img/cards/080.png"));
    cards.push_back(std::make_unique<Card>("MiniMog", 9, 2, 3, 9, "NEUTRAL", 8, "img/cards/081.png"));
    cards.push_back(std::make_unique<Card>("Chicobo", 9, 4, 4, 8, "NEUTRAL", 8, "img/cards/082.png"));
    cards.push_back(std::make_unique<Card>("Quezacotl", 2, 4, 9, 9, "THUNDER", 8, "img/cards/083.png"));
    cards.push_back(std::make_unique<Card>("Shiva", 6, 9, 7, 4, "ICE", 8, "img/cards/084.png"));
    cards.push_back(std::make_unique<Card>("Ifrit", 9, 8, 6, 2, "FIRE", 8, "img/cards/085.png"));
    cards.push_back(std::make_unique<Card>("Siren", 8, 2, 9, 6, "NEUTRAL", 8, "img/cards/086.png"));
    cards.push_back(std::make_unique<Card>("Sacred", 5, 9, 1, 9, "EARTH", 8, "img/cards/087.png"));
    cards.push_back(std::make_unique<Card>("Minotaur", 9, 9, 5, 2, "EARTH", 8, "img/cards/088.png"));
    cards.push_back(std::make_unique<Card>("Carbuncle", 8, 4, 4, 10, "NEUTRAL", 9, "img/cards/089.png"));
    cards.push_back(std::make_unique<Card>("Diablos", 5, 3, 10, 8, "NEUTRAL", 9, "img/cards/090.png"));
    cards.push_back(std::make_unique<Card>("Leviathan", 7, 7, 10, 1, "WATER", 9, "img/cards/091.png"));
    cards.push_back(std::make_unique<Card>("Odin", 8, 5, 10, 3, "NEUTRAL", 9, "img/cards/092.png"));
    cards.push_back(std::make_unique<Card>("Pandemona", 10, 7, 1, 7, "WIND", 9, "img/cards/093.png"));
    cards.push_back(std::make_unique<Card>("Cerberus", 7, 10, 4, 6, "NEUTRAL", 9, "img/cards/094.png"));
    cards.push_back(std::make_unique<Card>("Alexander", 9, 2, 10, 4, "HOLY", 9, "img/cards/095.png"));
    cards.push_back(std::make_unique<Card>("Phoenix", 7, 10, 2, 7, "FIRE", 9, "img/cards/096.png"));
    cards.push_back(std::make_unique<Card>("Bahamut", 10, 6, 8, 2, "NEUTRAL", 9, "img/cards/097.png"));
    cards.push_back(std::make_unique<Card>("Doomtrain", 3, 10, 1, 10, "POISON", 9, "img/cards/098.png"));
    cards.push_back(std::make_unique<Card>("Eden", 4, 10, 4, 9, "NEUTRAL", 9, "img/cards/099.png"));
    cards.push_back(std::make_unique<Card>("Ward", 10, 8, 7, 2, "NEUTRAL", 10, "img/cards/100.png"));
    cards.push_back(std::make_unique<Card>("Kiros", 6, 10, 7, 6, "NEUTRAL", 10, "img/cards/101.png"));
    cards.push_back(std::make_unique<Card>("Laguna", 5, 9, 10, 3, "NEUTRAL", 10, "img/cards/102.png"));
    cards.push_back(std::make_unique<Card>("Selphie", 10, 4, 8, 6, "NEUTRAL", 10, "img/cards/103.png"));
    cards.push_back(std::make_unique<Card>("Quistis", 9, 2, 6, 10, "NEUTRAL", 10, "img/cards/104.png"));
    cards.push_back(std::make_unique<Card>("Irvine", 2, 10, 6, 9, "NEUTRAL", 10, "img/cards/105.png"));
    cards.push_back(std::make_unique<Card>("Zell", 8, 6, 5, 10, "NEUTRAL", 10, "img/cards/106.png"));
    cards.push_back(std::make_unique<Card>("Rinoa", 4, 10, 10, 2, "NEUTRAL", 10, "img/cards/107.png"));
    cards.push_back(std::make_unique<Card>("Edea", 10, 3, 10, 3, "NEUTRAL", 10, "img/cards/108.png"));
    cards.push_back(std::make_unique<Card>("Seifer", 6, 4, 9, 10, "NEUTRAL", 10, "img/cards/109.png"));
    cards.push_back(std::make_unique<Card>("Squall", 10, 9, 4, 6, "NEUTRAL", 10, "img/cards/110.png"));
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

std::unique_ptr<Card> Deck::drawCard() {
    if (cards.empty()) {
        //Fehlerbehandlung
    }
    // Move the last unique_ptr from the vector
    std::unique_ptr<Card> drawnCard = std::move(cards.back());
    // Remove the last element from the vector
    cards.pop_back();
    // Return the drawn card
    return drawnCard;
}

const std::vector<std::unique_ptr<Card>>& Deck::getCards() const {
    return cards;
}
