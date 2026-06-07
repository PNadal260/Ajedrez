#pragma once
#include "constants.h"
#include "turn.h"

/**
 * Gestiona la elecció i el moviment de la torre del jugador.
 *
 * Demana a l'usuari la casella d'origen, verifica que hi hagi una torre del seu color
 * demana la casella del destí i comprova si el moviment es vàlid segons les regles 
 * bàsiques de la torre (avança ùnicamenten línea recta sense restriccións).
 * Actualitza el tauler i realitza la promoció a dama quan correspon.
 *
 */

void moveRook (char chessBoard[BOARD][BOARD], Turn turn);