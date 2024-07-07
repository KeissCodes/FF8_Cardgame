#include "board.h"
#include <glib.h> // Fügt G_PI hinzu
#include <iostream>
#include <memory>
#include <algorithm>

Board::Board(int xPos, int yPos, Player* playerA, Player* playerB ) : _xPos(xPos), _yPos(yPos), _playerA(playerA), _playerB(playerB)
{   
    for( size_t y = 0; y < 3; y++){
        for( size_t x = 0; x < 3; x++){   
            _grid[y][x].reset();
        }
    }

    _image = cairo_image_surface_create_from_png("img/background.png");
    if (cairo_surface_status(_image) != CAIRO_STATUS_SUCCESS) {
        std::cerr << "Failed to load image: " << std::endl;
    }
}

void Board::draw(cairo_t *cr)
{  
    // Zeichnungslogik für das Spielfeld
    cairo_set_source_rgb(cr, 0.6, 0.6, 0.6); // Hintergrundfarbe setzen
    cairo_paint(cr); // Hintergrund zeichnen

    // Kartenbild
    cairo_set_source_surface(cr, _image, _xPos, _yPos);
    cairo_paint(cr);

    // Setze die Linienfarbe für das Raster
    cairo_set_source_rgb(cr, 0, 0, 0); // Schwarze Linien

    // Dimensionen des Spielfeldes (beispielhaft)
    double width = CARD_SIZE * 3 ;  // Breite des Spielfelds
    double height = CARD_SIZE * 3; // Höhe des Spielfelds

    // Anzahl der Zellen
    int rows = 3;
    int cols = 3;

    // Berechne die Größe jeder Zelle
    double cell_width = width / cols;
    double cell_height = height / rows;

    // Offsets für das Verschieben des Rasters
    double h_shift = _xPos; // Horizontaler Verschiebung
    double v_shift = _yPos; // Vertikaler Verschiebung

    // Zeichne die vertikalen Linien
    for (int i = 1; i < cols; ++i) {
        double x = h_shift + i * cell_width;
        cairo_move_to(cr, x, v_shift);
        cairo_line_to(cr, x, v_shift + height);
    }

    // Zeichne die horizontalen Linien
    for (int i = 1; i < rows; ++i) {
        double y = v_shift + i * cell_height;
        cairo_move_to(cr, h_shift, y);
        cairo_line_to(cr, h_shift + width, y);
    }

    // Zeichne die äußere Umrandung
    cairo_rectangle(cr, h_shift, v_shift, width, height);

    cairo_stroke(cr); // Rasterlinien und Umrandung zeichnen

    // Karten Zeichnen
    for( size_t y = 0; y < 3; y++){
        for( size_t x = 0; x < 3; x++){   
            if(_grid[y][x] != nullptr){
                _grid[y][x]->setPosition(x * 128, y * 128);
                _grid[y][x]->draw(cr);
            }
        }
    }

    // Spielstand zeichnen für beide Player
    int playerAScore = getPlayerScore(_playerA);
    RGBColor playerAColor = _playerA->getColor();

    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, 50.0);
    cairo_set_source_rgb(cr,playerAColor.red,playerAColor.green,playerAColor.blue); 
    cairo_move_to(cr, _playerA->getPosition().first + 195, 615);
    cairo_show_text(cr, std::to_string(playerAScore).c_str());

    int playerBScore = getPlayerScore(_playerB);
    RGBColor playeBColor = _playerB->getColor();

    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, 50.0);
    cairo_set_source_rgb(cr,playeBColor.red,playeBColor.green,playeBColor.blue); 
    cairo_move_to(cr, _playerB->getPosition().first - 90, 615);
    cairo_show_text(cr, std::to_string(playerBScore).c_str());
    
}

std::pair<int,int> Board::getPosition() 
{
    return {_xPos, _yPos};
}


bool Board::tryPlaceCard(int x, int y, std::unique_ptr<Card>& card){
    int relativeX = x - _xPos;
    int relativeY = y - _yPos;
    int placedCardX = relativeX / 128;
    int placedCardY = relativeY / 128;

    if( placedCardX < 3 && placedCardY < 3){
        if(_grid[placedCardY][placedCardX] != nullptr){
            return false;
        }
        _grid[placedCardY][placedCardX] = std::move(card);
        _grid[placedCardY][placedCardX]->setCardHolder(this);
        _grid[placedCardY][placedCardX]->setSelected(false);

        checkCardOwnerChanges(placedCardY, placedCardX);

        return true;
    }
    return false;
}


void Board::checkCardOwnerChanges(int placedCardY, int placedCardX){

    std::vector<std::pair<int,int>> _fieldsToCheck;
    _fieldsToCheck.push_back({placedCardY - 1, placedCardX});
    _fieldsToCheck.push_back({placedCardY + 1, placedCardX});
    _fieldsToCheck.push_back({placedCardY, placedCardX - 1 });
    _fieldsToCheck.push_back({placedCardY, placedCardX + 1 });
    _fieldsToCheck.erase(std::remove_if(_fieldsToCheck.begin(), _fieldsToCheck.end(), [] (const std::pair<int,int>& pair) {
        return !(pair.first >= 0 && pair.first <= 2 && pair.second >= 0 && pair.second <=2);
    } ), _fieldsToCheck.end());
    _fieldsToCheck.erase(std::remove_if(_fieldsToCheck.begin(), _fieldsToCheck.end(), [&] (const auto& pair){
        return _grid[pair.first][pair.second] == nullptr;
    } ), _fieldsToCheck.end());

    for(const auto& [gridCardY, gridCardX] : _fieldsToCheck){
        Card& placedCard = *(_grid[placedCardY][placedCardX]);
        Card& gridCard = *(_grid[gridCardY][gridCardX]);

        if(gridCardY < placedCardY){
            if(placedCard.getUp() > gridCard.getDown()){
                gridCard.setCardOwner(placedCard.getCardOwner());
            }
        }
        else if(gridCardY > placedCardY){
            if(placedCard.getDown() > gridCard.getUp()){
                gridCard.setCardOwner(placedCard.getCardOwner());
            }
        }
        else if(gridCardX < placedCardX){
            if(placedCard.getLeft() > gridCard.getRight()){
                gridCard.setCardOwner(placedCard.getCardOwner());
            }
        }
        else if(gridCardX > placedCardX){
            if(placedCard.getRight() > gridCard.getLeft()){
                gridCard.setCardOwner(placedCard.getCardOwner());
            }
        }
    }

}

int Board::getPlayerScore(Player* player){
    int score = 0;
    for( size_t y = 0; y < 3; y++){
        for( size_t x = 0; x < 3; x++){   
            if(_grid[y][x] != nullptr && _grid[y][x]->getCardOwner() == player){
                score ++;
            }
        }
    }
    return score;
}

void Board::clear(){
    for( size_t y = 0; y < 3; y++){
        for( size_t x = 0; x < 3; x++){   
            _grid[y][x].reset();
        }
    }
}