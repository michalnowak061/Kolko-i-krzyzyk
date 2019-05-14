//
//  AdditionalFunctions.hpp
//  Projekt3_PAMSI
//
//  Created by Michał on 28.05.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#ifndef AdditionalFunctions_hpp
#define AdditionalFunctions_hpp

#include <stdio.h>
#include "Board.hpp"
#include "Player.hpp"
#include <termios.h>

int getch(void);
int win_test(Board &_board, player &_player1, player &_computer1);

#endif /* AdditionalFunctions_hpp */
