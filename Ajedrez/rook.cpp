#include <iostream>
#include "board.h"
#include "rook.h"
#include "pieceColor.h"
#include "constants.h"
#include "turn.h"

/**
 * Mou la torre del jugador actual, si es pot
 */

void moveRook(char chessBoard[BOARD][BOARD], Turn turn) {

    int originRow, originColumn;
    char originPiece;

    // Loop per escollir la torre de qui ha de moure
    while (true) {
        std::cout << "Select the rook you want to move\n";
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

        // Emmagatzma les coordenades de la peça que es vol fer servir
        originPiece = chessBoard[originRow][originColumn];

        // Comprovació de si hi ha una torre a la casella
        if (originPiece != WHITE[WhiteRook] && originPiece != BLACK[BlackRook]) {
            std::cout << "There is no rook on that square.\n";
            continue;
        }

        bool isWhite = isWhitePiece(originPiece);
        bool isBlack = isBlackPiece(originPiece);

        // Comprovar que la torre coincideix amb el torn
        if (turn == White && !isWhite) {
            std::cout << "White's turn, you must choose a white rook.\n";
            continue;
        }
        if (turn == Black && !isBlack) {
            std::cout << "Black's turn, you must choose a black rook.\n";
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

    // Emmagatzema les coordenades a les que es vol moure l'usuari
    char destinationPiece = chessBoard[destinationRow][destinationColumn];

    // Validació del moviment
    int rowDifference = destinationRow - originRow;
    int columnDifference = destinationColumn - originColumn;

    bool sameRow;
    bool sameColumn;

    if (rowDifference == 0) {
        sameRow = true;
    }
    else {
        sameRow = false;
    }

    if (columnDifference == 0) {
        sameColumn = true;
    }
    else {
        sameColumn = false;
    }
    // Comprovació que únicament es mogui de forma vertical u horitzontal
    if (!sameRow && !sameColumn) {
        std::cout << "Invalid move for rook. It must stay in the same row or column.\n";
        return;
    }

    int rowStep = 0;
    int columnStep = 0;

    if (sameRow) {
        if (columnDifference > 0) {
            columnStep = 1;
        }
        else {
            columnStep = -1;
        }
    }
    else { 
        if (rowDifference > 0) {
            rowStep = 1;
        }
        else {
            rowStep = -1;
        }
    }

    int currentRow = originRow + rowStep;
    int currentColumn = originColumn + columnStep;

    while (currentRow != destinationRow || currentColumn != destinationColumn) {
        if (!isEmptySquare(chessBoard[currentRow][currentColumn])) {
            std::cout << "There is a piece blocking the rook's path.\n";
            return;
        }
        currentRow = currentRow + rowStep;
        currentColumn = currentColumn + columnStep;
    }

    bool whiteRook = isWhitePiece(originPiece);
    bool blackRook = isBlackPiece(originPiece);

    if (whiteRook) {
        if (isWhitePiece(destinationPiece)) {
            std::cout << "You cannot capture your own piece.\n";
            return;
        }

        chessBoard[destinationRow][destinationColumn] = originPiece;
        chessBoard[originRow][originColumn] = EMPTY_SQUARE;
        std::cout << "Rook moved.\n";
    }

    if (blackRook) {
        if (isBlackPiece(destinationPiece)) {
            std::cout << "You cannot capture your own piece.\n";
            return;
        }
        chessBoard[destinationRow][destinationColumn] = originPiece;
        chessBoard[originRow][originColumn] = EMPTY_SQUARE;
        std::cout << "Rook moved.\n";
    }
}