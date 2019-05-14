//
//  AdditionalFunctions.cpp
//  Projekt3_PAMSI
//
//  Created by Michał on 28.05.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#include "AdditionalFunctions.hpp"

//----------------------------------------------------------------------------------------------------------
//Function waits for pressing the button with the given ASCII code
int getch( void ){
    int kbdinput;
    struct termios t_orig, t_new;
    
    // We need to change terminal settings so getchar() does't
    // require a CR at the end. Also disable local echo.
    tcgetattr( 0, &t_orig );
    t_new = t_orig;
    t_new.c_lflag &= ~ICANON;
    t_new.c_lflag &= ~ECHO;
    t_new.c_lflag &= ~ISIG;
    t_new.c_cc[VMIN] = 1;
    t_new.c_cc[VTIME] = 0;
    tcsetattr( 0, TCSANOW, &t_new );
    
    // Get actual input
    kbdinput = getchar();
    
    // Reset terminal settings.
    tcsetattr( 0, TCSANOW, &t_orig );
    
    return ( kbdinput );
}
//----------------------------------------------------------------------------------------------------------
//Function prints out messages about winning or losing
int win_test(Board &_board, player &_player1, player &_computer1){
    
    char player_char = _player1.get_character();
    char computer_char = _computer1.get_character();
    
    if(_board.search_row() == -1){
        if(_computer1.get_character() == 'O'){
            _computer1.more_points();
            system("clear");
            _board.print_board(_player1.get_points(),_computer1.get_points());
            cout<<computer_char<<" +1 point !"<<endl;
            cout<<"Press space to continue"<<endl;
            while(getch() != 32);
        }
        else if(_player1.get_character() == 'O'){
            _player1.more_points();
            system("clear");
            _board.print_board(_player1.get_points(),_computer1.get_points());
            cout<<player_char<<" +1 point !"<<endl;
            cout<<"Press space to continue"<<endl;
            while(getch() != 32);
        }
        _board.clear_board();
    }
    if(_board.search_row() == -2){
        if(_computer1.get_character() == 'X'){
            _computer1.more_points();
            system("clear");
            _board.print_board(_player1.get_points(),_computer1.get_points());
            cout<<computer_char<<" +1 point !"<<endl;
            cout<<"Press space to continue"<<endl;
            while(getch() != 32);
        }
        else if(_player1.get_character() == 'X'){
            _player1.more_points();
            system("clear");
            _board.print_board(_player1.get_points(),_computer1.get_points());
            cout<<player_char<<" +1 point !"<<endl;
            cout<<"Press space to continue"<<endl;
            while(getch() != 32);
        }
        _board.clear_board();
    }
    if(_board.search_row() == -3){
        system("clear");
        _board.print_board(_player1.get_points(),_computer1.get_points());
        cout<<"Draw !"<<endl;
        cout<<"Press space to continue"<<endl;
        while(getch() != 32);
        _board.clear_board();
    }
    
    if(_player1.get_points() == 3){
        _computer1.null_points();
        _player1.null_points();
        cout<<"CONGRATULATIONS, YOU WIN :) !"<<endl;
        cout<<"Press space to continue"<<endl;
        while(getch() != 32);
        return 1;
    }
    else if(_computer1.get_points() == 3){
        _computer1.null_points();
        _player1.null_points();
        cout<<"YOU LOSE :( !"<<endl;
        cout<<"Press space to continue"<<endl;
        while(getch() != 32);
        return 1;
    }
    
    return 0;
}
//----------------------------------------------------------------------------------------------------------
