//
//  Board.cpp
//  Projekt3_PAMSI
//
//  Created by Michał on 25.04.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#include "Board.hpp"

//----------------------------------------------------------------------------------------------------------
Board::Board(int _board_size,int _char_number,string _diificulty_level,int _searching_depth){
    char_number = _char_number;
    board_size = _board_size;
    difficulty_level = _diificulty_level;
    searching_depth = _searching_depth;
    
    board_array = new int *[board_size];
    int k = 1;
    for(int i = 0; i< board_size; ++i){
        board_array[i] = new int [board_size];
        for(int j = 0; j < board_size; ++j){
            board_array[i][j] = k++;
        }
    }
}
//----------------------------------------------------------------------------------------------------------
Board::~Board(){
    board_size = 0;
    board_array = nullptr;
    free(board_array);
}
//----------------------------------------------------------------------------------------------------------
void Board::print_board(int _player_points, int _computer_points){
    cout<<"********************************"<<endl;
    cout<<"*****   TIC TAC TOE v1.0   *****"<<endl;
    cout<<"********************************"<<endl;
    cout<<endl<<"Player: "<<_player_points<<" points"<<endl;
    cout<<"Computer: "<<_computer_points<<" points"<<endl;
    
    int w = 0, k = 0;
    
    cout<<endl;
    for(int i = 0; i < board_size - 1; ++i){
        cout<<"    |";
    }
    cout<<endl;
    
    for(int i = 0; i < board_size - 1; ++i){
        if(board_array[w][k] == -1) cout<<" O";
        else if(board_array[w][k] == -2) cout<<" X";
        else cout<<" "<<board_array[w][k];
        if(board_array[w][k++] > 10) cout<<" |";
        else cout<<"  |";
        if(i == board_size - 2){
            if(board_array[w][k] == -1) cout<<" O";
            else if(board_array[w][k] == -2) cout<<" X";
            else cout<<" "<<board_array[w][k];
        }
    }
    
    cout<<endl;
    
    for(int i = 0; i < board_size - 1; ++i){
        cout<<"____|";
    }
    cout<<"____";
    
    cout<<endl;
    
    for(int i = 0; i < board_size - 2; ++i){
        ++w; k = 0;
        for(int i = 0; i < board_size - 1; ++i){
            cout<<"    |";
        }
        cout<<endl;
    
        for(int i = 0; i < board_size - 1; ++i){
            if(board_array[w][k] == -1) cout<<" O";
            else if(board_array[w][k] == -2) cout<<" X";
            else cout<<" "<<board_array[w][k];
            if(board_array[w][k++] > 9) cout<<" |";
            else cout<<"  |";
            if(i == board_size - 2){
                if(board_array[w][k] == -1) cout<<" O";
                else if(board_array[w][k] == -2) cout<<" X";
                else cout<<" "<<board_array[w][k];
            }
        }
    
        cout<<endl;
    
        for(int i = 0; i < board_size - 1; ++i){
            cout<<"____|";
        }
        cout<<"____";
        
        cout<<endl;
    }
    
    ++w; k = 0;
    for(int i = 0; i < board_size - 1; ++i){
        cout<<"    |";
    }
    cout<<endl;
    for(int i = 0; i < board_size - 1; ++i){
        if(board_array[w][k] == -1) cout<<" O";
        else if(board_array[w][k] == -2) cout<<" X";
        else cout<<" "<<board_array[w][k];
        if(board_array[w][k++] > 10) cout<<" |";
        else cout<<"  |";
        if(i == board_size - 2){
            if(board_array[w][k] == -1) cout<<" O";
            else if(board_array[w][k] == -2) cout<<" X";
            else cout<<" "<<board_array[w][k];
        }
    }
    
    cout<<endl;
    for(int i = 0; i < board_size - 1; ++i){
        cout<<"    |";
    }
    cout<<endl<<endl;
}
//----------------------------------------------------------------------------------------------------------
bool Board::insert_circle(int _field_number){
    for(int i = 0; i< board_size; ++i){
        for(int j = 0; j < board_size; ++j){
            if(board_array[i][j] == _field_number && board_array[i][j] != -2 && board_array[i][j] != -1){
                board_array[i][j] = -1;
                return true;
            }
        }
    }
    return false;
}
//----------------------------------------------------------------------------------------------------------
bool Board::insert_cross(int _field_number){
    for(int i = 0; i< board_size; ++i){
        for(int j = 0; j < board_size; ++j){
            if(board_array[i][j] == _field_number && board_array[i][j] != -2 && board_array[i][j] != -1){
                board_array[i][j] = -2;
                return true;
            }
        }
    }
    return false;
}
//----------------------------------------------------------------------------------------------------------
/*  
    Method return -1 if: O WIN
    Method return -2 if: X WIN
    Method return -3 if: draw
*/
int Board::search_row(){
    int count = 0;
    
    /* vertical testing */
    for(int i = 0; i < board_size; i++){
        for(int j = 0; j < board_size - 1; j++){
            if(board_array[j][i] == -1){
                if(board_array[j+1][i] == -1) count++;
                else count = 0;
                
                if(count == char_number - 1){
                    return -1; // O winner
                }
            }
        }
        count = 0;
    }
    
    count = 0;
    
    for(int i = 0; i < board_size; i++){
        for(int j = 0; j < board_size - 1; j++){
             if(board_array[j][i] == -2){
                 if(board_array[j+1][i] == -2) count++;
                 else count = 0;
             
                 if(count == char_number - 1){
                     return -2;  // X winner
                 }
             }
        }
        count = 0;
    }
    
    count = 0;
    
    /* horizontal testing */
    for(int i = 0; i < board_size; i++){
        for(int j = 0; j < board_size - 1; j++){
            if(board_array[i][j] == -2){
                if(board_array[i][j+1] == -2) count++;
                else count = 0;
                
                if(count == char_number - 1){
                    return -2;
                }
            }
        }
        count = 0;
    }
    
    count = 0;
    
    for(int i = 0; i < board_size; i++){
        for(int j = 0; j < board_size - 1; j++){
             if(board_array[i][j] == -1){
                 if(board_array[i][j+1] == -1) count++;
                 else count = 0;
             
                 if(count == char_number - 1){
                     return -1;
                 }
             }
        }
        count = 0;
    }
    
    count = 0;
    
    /* testing diagonally / */
    for(int i = 0; i < board_size; i++){
        for(int j = board_size - 1; j >= 0; j--){
            
            if(board_array[j][i] == -2){
                int k = j, l = i;
                count = 0;
                while(l < board_size && k >= 0){
                    if(board_array[k][l] == -2) count++;
                    else count = 0;
                    k--; l++;
                    
                    if(count == char_number ){
                        return -2;
                    }
                }
                count = 0;
            }
            count = 0;
        }
        count = 0;
    }
    
    count = 0;
    
    for(int i = 0; i < board_size; i++){
        for(int j = board_size - 1; j >= 0; j--){
             if(board_array[j][i] == -1){
                 int k = j, l = i;
                 count = 0;
                 while(l < board_size && k >= 0){
                     if(board_array[k][l] == -1) count++;
                     else count = 0;
                     k--; l++;
             
                     if(count == char_number ){
                         return -1;
                     }
                 }
                 count = 0;
            }
            count = 0;
        }
        count = 0;
    }
    
    count = 0;
    
    /* testing diagonally \ */
    for(int i = 0; i < board_size; i++){
        for(int j = 0; j < board_size; j++){
            if(board_array[j][i] == -2){
                int k = j, l = i;
                while(l < board_size && k < board_size){
                    if(board_array[k][l] == -2) count++;
                    else count = 0;
                    k++; l++;
                    
                    if(count == char_number ){
                        return -2;
                    }
                }
                count = 0;
            }
            count = 0;
        }
        count = 0;
    }
    
    count = 0;
    
    for(int i = 0; i < board_size; i++){
        for(int j = 0; j < board_size; j++){
             if(board_array[j][i] == -1){
                 int k = j, l = i;
                 while(l < board_size && k < board_size){
                     if(board_array[k][l] == -1) count++;
                     else count = 0;
                     k++; l++;
             
                     if(count == char_number ){
                         return -1;
                     }
                 }
                 count = 0;
            }
            count = 0;
        }
        count = 0;
    }
    
    count = 0;
    
    //draw test
    for(int i = 0; i < board_size; ++i){
        for(int j = 0; j < board_size; j++){
            if(board_array[j][i] == -1 || board_array[j][i] == -2) count++;
        }
    }
    if(count == board_size*board_size) return -3; //draw
    else return 0;  //anything
}
//----------------------------------------------------------------------------------------------------------
void Board::clear_board(){
    int k = 1;
    for(int i = 0; i< board_size; ++i){
        for(int j = 0; j < board_size; ++j){
            board_array[i][j] = k++;
        }
    }
}
//----------------------------------------------------------------------------------------------------------
