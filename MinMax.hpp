//
//  MinMax.hpp
//  Projekt3_PAMSI
//
//  Created by Michał on 08.05.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#ifndef MinMax_hpp
#define MinMax_hpp

#include <stdio.h>
#include "Player.hpp"

int evaluate_position(Board _board, player _player);
int alfa_beta(Board _board,player _player,player _computer,int _depth,int _max_player,int _alpha,int _beta);
int min_max(Board _board, player _player, player _computer, int _depth);
int min_max_move(Board _board, player _player,player _computer,int _depth);

#endif /* MinMax_hpp */
