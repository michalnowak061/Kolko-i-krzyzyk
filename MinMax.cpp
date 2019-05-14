//
//  MinMax.cpp
//  Projekt3_PAMSI
//
//  Created by Michał on 08.05.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#include "MinMax.hpp"

//----------------------------------------------------------------------------------------------------------
/* Function evaluating the state of the game
   Function return +10 if player wins
   Function return -10 if opponent wins
   Function return 0 if is draw
*/
int evaluate_position(Board _board, player _player){
    //player wins
    if( (_board.search_row() == -2 && _player.get_character() == 'X') ||
        (_board.search_row() == -1 && _player.get_character() == 'O') ){
        return +10;
    }
    //opponent wins
    else if( (_board.search_row() == -2 && _player.get_character() == 'O') ||
             (_board.search_row() == -1 && _player.get_character() == 'X') ){
        return -10;
    }
    //is draw
    else if( _board.search_row() == -3 ){
        return 0;
    }
    
    return 1;
}
//----------------------------------------------------------------------------------------------------------
// Function with alfabeta pruning
int alfa_beta(Board _board,player _player,player _computer,int _depth,int _max_player,int _alpha,int _beta){
    //rate the state of the game
    int game_rating = evaluate_position(_board,_player); // <- game rating (-10,0,10)
    //if we have reached the leaf or the rating of the game means a winning draw or defeat return game rating
    if(_depth == 0 || game_rating == 10 || game_rating == -10 || game_rating == 0) return game_rating;
    
    //case 1: maximizing player
    if(_max_player == true){
        //check each field of the game
        for(int i = 0; i < _board.get_size(); i++){
            for(int j = 0; j < _board.get_size(); j++){
                //if the field is free
                if(_board.get(i,j) != -1 && _board.get(i,j) != -2){
                    int temp_value = _board.get(i,j); // <- variable that holds the field number
                    
                    _player.make_move(_board,temp_value); //make a move
                    _alpha = max(_alpha, alfa_beta(_board,_player,_computer,_depth-1,!_max_player,_alpha,_beta) );
                    _board.set(i,j,temp_value); //undo the move
                    
                    if(_alpha >= _beta) break; //alpha pruning
                }
            }
        }
        
        return _alpha;
    }
    //case 2: minimizing player
    else{
        //check each field of the game
        for(int i = 0; i < _board.get_size(); i++){
            for(int j = 0; j < _board.get_size(); j++){
                //if the field is free
                if(_board.get(i,j) != -1 && _board.get(i,j) != -2){
                    int temp_value = _board.get(i,j); // <- variable that holds the field number
                    
                    _computer.make_move(_board,temp_value); //make a move
                    _beta = min(_beta,alfa_beta(_board,_player,_computer,_depth-1,!_max_player,_alpha,_beta));
                    _board.set(i,j,temp_value); //undo the move
                    
                    if(_alpha >= _beta) break; //beta pruning
                }
            }
        }
        
        return _beta;
    }
}
//----------------------------------------------------------------------------------------------------------
// Min-max function with alfabeta pruning
int min_max(Board _board, player _player, player _computer, int _depth){
    
    return alfa_beta(_board,_player,_computer,_depth,false,-10,10);
}
//----------------------------------------------------------------------------------------------------------
/* Function that finds the best move with the help of minmax
   Function draws and returns the best move
 */
int min_max_move(Board _board, player _player,player _computer,int _depth){
    
    int best_val = -10; // <- the best game rating for minimizing player
    int best_moves[_board.get_size()*_board.get_size()]; // <- an array storing the best possible moves
    int index = 0;
    //check each field of the game
    for(int i = 0; i < _board.get_size(); i++){
        for(int j = 0; j < _board.get_size(); j++){
            //if the field is free
            if(_board.get(i,j) != -1 && _board.get(i,j) != -2){
                int temp_value = _board.get(i,j); // <- variable that holds the field number
                
                _player.make_move(_board,temp_value); //make a move
                int move_val = min_max(_board,_player,_computer,_depth); // <- game rating to which the move leads
                _board.set(i,j,temp_value); //undo the move
                //if the move leads to a win save move to array
                if(move_val > best_val){
                    best_val = move_val;
                    index = 0;
                    best_moves[index++] = temp_value;
                }
                else if(move_val == best_val){
                    best_moves[index++] = temp_value;
                }
            }
        }
    }
    //draw a move
    if(index > 0) index = rand() % index;
    
    return best_moves[index]; //return the best move
}
//----------------------------------------------------------------------------------------------------------
