#pragma once
#include "constants.h"
#include "turn.h"

/**
 * Gestiona la elecció i el moviment del rei del jugador actual
 * 
 * Demana a l'usuari la casella d'origen, comprova que hi hagi un rei del color
 * corresponent al torn, demana la casella de destí i verifica que el moviment es
 * vàlid segons les regles del rei (una casella en qualsevol direcció).
 * Actualitza el tauler si el moviment es correcte
 *
 */

void moveKing(char chessBoard[BOARD][BOARD], Turn turn);
