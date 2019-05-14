//
//  computer.hpp
//  Projekt3_PAMSI
//
//  Created by Michał on 29.04.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#ifndef computer_hpp
#define computer_hpp

#include <stdio.h>
#include "Board.hpp"

class player{
private:
    char character; // <- the symbol the player is playing
    int points;     // <- player points
public:
    void make_move_AI(Board &_board, player &_player,player &_computer);
    bool make_move(Board &_board,int const _field_number);
    
    char get_character(){ return character; }
    void change_character(char _character){ character = _character; }
    
    int get_points(){ return points; }
    void more_points(){ points++; }
    void null_points(){ points = 0; }
    
    player(char _charakter);
    ~player();
};


#endif /* computer_hpp */
