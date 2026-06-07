// board.cpp: aquest fitxer conte el taulell del ajedrez

#include "board.h"
#include <iostream>

/**
 * Conjunt de caràcters per a les peces blanques.
 *
 * Índexs segons l'enum de PecesBlanques:
 *  [PeoBlanc]    = 'P'
 *  [TorreBlanca] = 'T'
 *  [CavallBlanc] = 'C'
 *  [AlfilBlanc]  = 'A'
 *  [DamaBlanca]  = 'D'
 *  [ReiBlanc]    = 'R'
 */

char WHITE[NUMBER_OF_PIECES] = { 'P','T','H','B','Q','K' };

/**
 * Conjunt de caràcters per a les peces negres.
 *
 * Índexs segons l'enum PecesNegres:
 *  [PeoNegre]     = 'p'
 *  [TorreNegra]   = 't'
 *  [CavallNegre]  = 'c'
 *  [AlfilNegre]   = 'a'
 *  [ReiNegre]     = 'r'
 *  [DamaNegra]    = 'd'
 */

char BLACK[NUMBER_OF_PIECES] = { 'p','t','h','b','k','q' };

/**
 * Inicialització del taulell amb posicions inicials
 */

void initializeBoard(char chessBoard[BOARD][BOARD])
{
	// Es posen totes les caselles amb	 '*' 
	for (int height = 0; height < BOARD; height++)
	{
		for (int width = 0; width < BOARD; width++)
		{
			chessBoard[height][width] = EMPTY_SQUARE;
		}
	}


	// Peces blanques
	chessBoard[7][0] = WHITE[WhiteRook];
	chessBoard[7][1] = WHITE[WhiteHorse];
	chessBoard[7][2] = WHITE[WhiteBishop];
	chessBoard[7][3] = WHITE[WhiteQueen];
	chessBoard[7][4] = WHITE[WhiteKing];
	chessBoard[7][5] = WHITE[WhiteBishop];
	chessBoard[7][6] = WHITE[WhiteHorse];
	chessBoard[7][7] = WHITE[WhiteRook];

	// Peons blancs
	for (int j = 0; j < BOARD; ++j)
		chessBoard[6][j] = WHITE[WhitePawn];

	// Peces negres
	chessBoard[0][0] = BLACK[BlackRook];
	chessBoard[0][1] = BLACK[BlackHorse];
	chessBoard[0][2] = BLACK[BlackBishop];
	chessBoard[0][3] = BLACK[BlackKing];
	chessBoard[0][4] = BLACK[BlackQueen];
	chessBoard[0][5] = BLACK[BlackBishop];
	chessBoard[0][6] = BLACK[BlackHorse];
	chessBoard[0][7] = BLACK[BlackRook];

	// Peons negres
	for (int j = 0; j < BOARD; ++j)
		chessBoard[1][j] = BLACK[BlackPawn];

}

/**
 * Mostrem el taulell a la consola
 */

void showChessBoard(char chessBoard[BOARD][BOARD])
{
	// Numeros de la columna
	std::cout << "  1 2 3 4 5 6 7 8\n";

	// Files de la 8 a la 1
	for (int height = 0; height < BOARD; height++)
	{
		std::cout << (BOARD - height) << " "; 
		for (int width = 0; width < BOARD; width++)
		{
			std::cout << chessBoard[height][width] << " ";
		}
		std::cout << "\n";
	}
}

/**
 * Retorna true si algun dels reis segueix al taulell
 */
bool isKingAlive(char chessBoard[BOARD][BOARD], bool whiteKing)
{
	char kingCharacter;

	if (whiteKing)
	{
		kingCharacter = WHITE[WhiteKing];
	}
	else
	{
		kingCharacter = BLACK[BlackKing];
	}

	for (int row = 0; row < BOARD; ++row)
	{
		for (int column = 0; column < BOARD; ++column)
		{
			if (chessBoard[row][column] == kingCharacter)
			{
				return true;
			}
		}
	}

	return false;
}
