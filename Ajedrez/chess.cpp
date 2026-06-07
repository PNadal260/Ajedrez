#include <iostream>
#include "board.h"
#include "pawn.h"
#include "king.h"
#include "horse.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "pieceColor.h"
#include "constants.h"
#include "turn.h"

/**
 * Funció principal del programa.
 * Inicialitza el taulell, mostra la posicio inicial i executa un bucle de joc
   per torns en el que cada jugador eligeix quina peça moure.
 */


int main() {

    std::cout << "=== CHESS ===\n";

    // Matriu que representa el taulell
    char chessBoard[BOARD][BOARD];

    // Coloquem les peces a la posició inicial
    initializeBoard(chessBoard);
    showChessBoard(chessBoard);

    // Començen les blanques
    Turn turn = White;

    // Loop principal
    while (true) {

        if (turn == White) {
            std::cout << "\nWhite's turn\n";
        }
        else {
            std::cout << "\nBlack's turn\n";
        }

        std::cout << "Select the piece you want to move "
            "(P pawn, K king, N knight, R rook, B bishop, Q queen): ";
        char chosenPiece;
        std::cin >> chosenPiece;

        // Segons la lletra seleccionada cridem a la funcio que correspon.
        if (chosenPiece == 'P' || chosenPiece == 'p') {
            movePawn(chessBoard, turn);
        }
        else if (chosenPiece == 'K' || chosenPiece == 'k') {
            moveKing(chessBoard, turn);
        }
        else if (chosenPiece == 'H' || chosenPiece == 'h') {
            moveHorse(chessBoard, turn);
        }
        else if (chosenPiece == 'R' || chosenPiece == 'r') {
            moveRook(chessBoard, turn);
        }
        else if (chosenPiece == 'B' || chosenPiece == 'b') {
            moveBishop(chessBoard, turn);
        }
        else if (chosenPiece == 'Q' || chosenPiece == 'q') {
            moveQueen(chessBoard, turn);
        }
        else {
            std::cout << "Invalid piece.\n";
        }

        // // Mostra el taulell una vegada acabat el moviment
        showChessBoard(chessBoard);

        // Comprobació de si algun rei ha sigut capturat
        if (!isKingAlive(chessBoard, true)) {
            std::cout << "Black wins! White king has been captured.\n";
            break;
        }
        if (!isKingAlive(chessBoard, false)) {
            std::cout << "White wins! Black king has been captured.\n";
            break;
        }

        // Cambi de torn, alterna entre blanc i negre
        if (turn == White) {
            turn = Black;
        }
        else {
            turn = White;
        }
    }

    return 0;
}
