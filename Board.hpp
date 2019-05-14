//
//  Board.hpp
//  Projekt3_PAMSI
//
//  Created by Michał on 25.04.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Board{
private:
    int board_size;           // <- board size
    int char_number;          // <- number of characters in a line
    int **board_array;        // <- 2D table representing the board
    string difficulty_level;  // <- difficulty level
    int searching_depth;      // <- searching depth
public:
    void print_board(int _player_points, int _computer_points);
    void clear_board();
    
    bool insert_circle(int _field_number);
    bool insert_cross(int _field_number);
    
    int search_row();
    
    int get_size(){ return board_size; }
    
    string get_difficulty_level(){ return difficulty_level; }
    void set_difficulty_level(string level){ difficulty_level = level; }
    
    int get_searching_depth(){ return searching_depth; }
    void set_searching_depth(int _searching_depth){ searching_depth = _searching_depth; }
    
    int get(int i, int j){ return board_array[i][j]; }
    void set(int i, int j, int value){ board_array[i][j] = value;}
    
    Board(int _board_size,int _char_number,string _diificulty_level,int _searching_depth);
    ~Board();
};

#endif /* Board_hpp */
