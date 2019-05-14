//
//  main.cpp
//  Projekt3_PAMSI
//
//  Created by Michał on 25.04.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

/*
 Należy zaimplementować grę w kółko i krzyżyk z wykorzystaniem algorytmu MinMax z alfa-beta cię- ciami. Gracz
 powinien posiadać możliwość definiowana rozmiaru pola (kwadratowego) wraz z ilością znaków w rzędzie.
*/

#include <iostream>
#include "Player.hpp"
#include "AdditionalFunctions.hpp"

int main(void) {
    
    int board_size = 3;
    int char_number = 3;
    int searching_depth = 7;
    
    string difficulty_level = "hard";
    
    player player1('X');
    player computer1('O');
    
    int choice = 0;
    int field_number = 0;
    
    while(choice != 9){
        Board board(board_size,char_number,difficulty_level,searching_depth);
        
        char player_char = player1.get_character();
        char computer_char = computer1.get_character();
        
        //drawing who starts
        srand((unsigned int)time(NULL));
        int who_start = rand() % 3;
        if(who_start == 0) who_start++;
        
        system("clear");
        cout<<"********************************"<<endl;
        cout<<"*****   TIC TAC TOE v1.0   *****"<<endl;
        cout<<"********************************"<<endl;
        cout<<"Board size: "<<board_size<<"x"<<board_size<<endl;
        cout<<"Number of characters in a row: "<<char_number<<endl;
        cout<<"You play as a: "<<player_char<<endl;
        cout<<"Computer play as a: "<<computer_char<<endl;
        cout<<"Difficulty level: "<<board.get_difficulty_level()
                                  <<endl<<"Searching depth: "<<board.get_searching_depth()
                                  <<endl;
        cout<<"********************************"<<endl<<endl;
        cout<<"1.Start game"<<endl;
        cout<<"2.Change the size of the board"<<endl;
        cout<<"3.Change the number of characters in a row"<<endl;
        cout<<"4.Change your character(O/X)"<<endl;
        cout<<"5.Change the level of difficulty"<<endl;
        cout<<"9.Exit"<<endl;
        cout<<"> ";
        cin>>choice;
        
        switch(choice){
            case 1:
                while(true){
                    system("clear");
                    board.print_board(player1.get_points(),computer1.get_points());
                    switch(who_start){
                        case 1:
                            computer1.make_move_AI(board,computer1,player1);
                            break;
                        case 2:
                            while(true){
                                cout<<"Your move> ";
                                cin>>field_number;
                                if(field_number <= board_size*board_size){
                                    if(player1.make_move(board,field_number) == true) break;
                                    else cout<<"This field is not empty !"<<endl;
                                }else cout<<"Nie ma takiego pola"<<endl;
                            }
                            break;
                    }
                    
                    if(win_test(board,player1,computer1) == 1) break;
                    
                    system("clear");
                    board.print_board(player1.get_points(),computer1.get_points());
                    
                    switch(who_start){
                        case 1:
                            while(true){
                                cout<<"Your move> ";
                                cin>>field_number;
                                if(field_number <= board_size*board_size){
                                    if(player1.make_move(board,field_number) == true) break;
                                else cout<<"This field is not empty !"<<endl;
                                }else cout<<"There is no such field !"<<endl;
                            }
                            break;
                        case 2:
                            computer1.make_move_AI(board,computer1,player1);
                            break;
                    }
                           
                    system("clear");
                    board.print_board(player1.get_points(),computer1.get_points());
                    
                    if(win_test(board,player1,computer1) == 1) break;
                }
                break;
            case 2:
                while(true){
                    cout<<"Board size (min: 3x3 | max: 5x5): ";
                    cin>>board_size;
                    if(board_size > 5 || board_size < 3){
                        cout<<"Minimum size of the board: 3, maximum size of the board: 5 !"<<endl;
                    }else break;
                }
                break;
            case 3:
                while(true){
                    cout<<"Number of characters in a row: ";
                    cin>>char_number;
                    if(char_number <= 2){
                        cout<<"Number of characters must be greater than two !"<<endl;
                    }
                    else if(char_number > board_size){
                        cout<<"Number of characters must be less than or equal to the size of the board !"<<endl;
                    }else break;
                }
                break;
            case 4:
                cout<<"Insert your character(O/X): ";
                cin>>player_char;
                if(player_char == 'x' && 'X'){
                    player1.change_character('X');
                    computer1.change_character('O');
                }
                else if(player_char == 'o' && 'O'){
                    player1.change_character('O');
                    computer1.change_character('X');
                }
                break;
            case 5:
                cout<<"1. Easy   (searching depth = 0)"<<endl<<"2. Medium (searching depth = 2)"
                <<endl<<"3. Hard   (searching depth = 5)"<<endl;
                cout<<"> ";
                cin>>choice;
                
                switch (choice){
                    case 1:
                        difficulty_level = "easy";
                        searching_depth = 0;
                        break;
                    case 2:
                        difficulty_level = "medium";
                        searching_depth = 2;
                        break;
                    case 3:
                        difficulty_level = "hard";
                        searching_depth = 7;
                        break;
                }
                break;
        }
    }
    
    return 0;
}
