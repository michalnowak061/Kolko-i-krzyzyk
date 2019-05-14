//
//  computer.cpp
//  Projekt3_PAMSI
//
//  Created by Michał on 29.04.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#include "Player.hpp"
#include "MinMax.hpp"

//----------------------------------------------------------------------------------------------------------
player::player(char _charakter){
    points = 0;
    character = _charakter;
}
//----------------------------------------------------------------------------------------------------------
player::~player(){
    points = 0;
}
//----------------------------------------------------------------------------------------------------------
void player::make_move_AI(Board &_board, player &_player,player &_computer){
    
    int field = min_max_move(_board,_player,_computer,_board.get_searching_depth());
    
    if(character == 'O') _board.insert_circle(field);
    if(character == 'X') _board.insert_cross(field);
}
//----------------------------------------------------------------------------------------------------------
bool player::make_move(Board &_board,int const _field_number){
    
    if(character == 'O'){
        if(_board.insert_circle(_field_number) == true) return true;
    }
    if(character == 'X'){
        if(_board.insert_cross(_field_number) == true) return true;
    }
    
    return false;
}
//----------------------------------------------------------------------------------------------------------
