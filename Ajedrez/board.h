//Comentaris fets amb IA

#pragma once

#include "constants.h"
#include <iostream>

/*
 * Peces blanques i negres representades amb caràcters.
 */

extern char WHITE[NUMBER_OF_PIECES];
extern char BLACK[NUMBER_OF_PIECES];

/*
 * Índexs de les peces blanques dins de WHITE.
 */

enum whitePieces { WhitePawn, WhiteRook, WhiteHorse, WhiteBishop, WhiteQueen, WhiteKing };

/*
 * Índexs de les peces negres dins de BLACK.
 */

enum blackPieces { BlackPawn, BlackRook, BlackHorse, BlackBishop, BlackKing, BlackQueen };

/*
 * Inicialitza el tauler d'escacs.
 */

void initializeBoard(char chessBoard[BOARD][BOARD]);

/*
 * Mostra el tauler per pantalla.
 */

void showChessBoard(char chessBoard[BOARD][BOARD]);

/*
 * Comprova si el rei continua viu.
 */

bool isKingAlive(char chessBoard[BOARD][BOARD], bool white);
