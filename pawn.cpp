#include <iostream>
#include "board.h"
#include "pawn.h"
#include "pieceColor.h"
#include "constants.h"
#include "turn.h"

/**
 * Mou un peó del jugador si el movimente es valid
 */

void movePawn(char chessBoard[BOARD][BOARD], Turn turn) {

    int originRow, originColumn;
    char originPiece;

    // Bucle para escollir un peó valid del jugador que te el torn
    while (true) {
        std::cout << "Select the pawn you want to move\n";
        std::cout << "Enter row (1-" << BOARD << "): ";
        std::cin >> originRow;
        std::cout << "Enter column (1-" << BOARD << "): ";
        std::cin >> originColumn;

        originRow--;
        originColumn--;

        if (originRow < 0 || originRow >= BOARD ||
            originColumn < 0 || originColumn >= BOARD) {
            std::cout << "Coordinates out of board.\n";
            continue;
        }

        // Guarda les cordenades de la peça a la que vol accedir el usuari
        originPiece = chessBoard[originRow][originColumn];

        // Comprobem si hi ha un peó a la casella
        if (originPiece != WHITE[WhitePawn] && originPiece != BLACK[BlackPawn]) {
            std::cout << "There is no pawn on that square.\n";
            continue;
        }

        bool isWhite = isWhitePiece(originPiece);
        bool isBlack = isBlackPiece(originPiece);
       
        // Comprobar que el peó coincideix amb el torn
        if (turn == White && !isWhite) {
            std::cout << "White's turn, you must choose a white pawn.\n";
            continue;
        }
        if (turn == Black && !isBlack) {
            std::cout << "Black's turn, you must choose a black pawn.\n";
            continue;
        }

        break;
    }

    int destinationRow, destinationColumn;
    std::cout << "Enter the target square\n";
    std::cout << "Enter row (1-" << BOARD << "): ";
    std::cin >> destinationRow;
    std::cout << "Enter column (1-" << BOARD << "): ";
    std::cin >> destinationColumn;

    destinationRow--;
    destinationColumn--;

    if (destinationRow < 0 || destinationRow >= BOARD ||
        destinationColumn < 0 || destinationColumn >= BOARD) {
        std::cout << "Coordinates out of board.\n";
        return;
    }

    // Guarda coordenades a on vol accedir el usuari
    char destinationPiece = chessBoard[destinationRow][destinationColumn];

    // Validem els moviments de la peça
    int rowDifference = destinationRow - originRow;
    int columnDifference = destinationColumn - originColumn;

    bool whitePawn = (originPiece == WHITE[WhitePawn]);
    bool blackPawn = (originPiece == BLACK[BlackPawn]);

    // Movimient de avançar del peó
    bool whiteForward = (rowDifference == 1 && columnDifference == 0);
    bool blackForward = (rowDifference == -1 && columnDifference == 0);

    // Movimient d'atacar, es mou en diagonal
    bool whiteCapture = (rowDifference == 1 && (columnDifference == 1 || columnDifference == -1));
    bool blackCapture = (rowDifference == -1 && (columnDifference == 1 || columnDifference == -1));

    if (whitePawn) {

        if (whiteForward && isEmptySquare(destinationPiece)) {
            chessBoard[destinationRow][destinationColumn] = originPiece;
            chessBoard[originRow][originColumn] = EMPTY_SQUARE;
            std::cout << "Pawn moved to target square.\n";
        }
        else if (whiteCapture && isBlackPiece(destinationPiece)) {
            chessBoard[destinationRow][destinationColumn] = originPiece;
            chessBoard[originRow][originColumn] = EMPTY_SQUARE;
            std::cout << "Pawn captured an enemy piece.\n";
        }
        else {
            std::cout << "Invalid move for white pawn.\n";
            return;
        }
    }
    else if (blackPawn) {

        if (blackForward && isEmptySquare(destinationPiece)) {
            chessBoard[destinationRow][destinationColumn] = originPiece;
            chessBoard[originRow][originColumn] = EMPTY_SQUARE;
            std::cout << "Pawn moved to target square.\n";
        }
        else if (blackCapture && isWhitePiece(destinationPiece)) {
            chessBoard[destinationRow][destinationColumn] = originPiece;
            chessBoard[originRow][originColumn] = EMPTY_SQUARE;
            std::cout << "Pawn captured an enemy piece.\n";
        }
        else {
            std::cout << "Invalid move for black pawn.\n";
            return;
        }
    }

    // Peó es converteix en reina si arriba al final
    if (originPiece == WHITE[WhitePawn] && destinationRow == 0) {
        chessBoard[destinationRow][destinationColumn] = WHITE[WhiteQueen];
        std::cout << "White pawn promoted to queen.\n";
    }
    if (originPiece == BLACK[BlackPawn] && destinationRow == BOARD - 1) {
        chessBoard[destinationRow][destinationColumn] = BLACK[BlackQueen];
        std::cout << "Black pawn promoted to queen.\n";
    }
}
