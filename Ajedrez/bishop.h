#pragma once

#include "constants.h"
#include "turn.h"

/**
 * Gestiona la selecció i el  moviment de un alfil del jugador actual.
 *
 * Demana a l'usuari la casella d'origen, comprova que hi hagi un alfil del color correcte,
 * després demana el destí i valida que el moviment sigui en diagonal
 * sense peçes intermitges. Actualitza el tauler si el moviment es vàlid.
 *
 */


void moveBishop(char chessBoard[BOARD][BOARD], Turn turn);