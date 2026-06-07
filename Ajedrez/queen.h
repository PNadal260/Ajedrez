// queen.h
#pragma once

#include "constants.h"
#include "turn.h"

/**
 * Gestiona la selecció i moviment de la reina dle jugador actual
 *
 * Combina els moviments de la torre i l'alfil
 *  - en la línea recta
 *  - en diagonal
 */

void moveQueen(char chessboard[BOARD][BOARD], Turn turn);

