#include <iostream>
#include "board.h"
#include "horse.h"
#include "pieceColor.h"
#include "constants.h"
#include "turn.h"

/**
 * Moure cavall del jugador actual si el moviment és vàlid.
 */

void moveHorse(char chessBoard[BOARD][BOARD], Turn turn) {

    int originRow, originColumn;
    char originPiece;

    // Bucle per escollir el caball de qui te el torn
    while (true) {
        std::cout << "Select the horse you want to move\n";
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
        // Guarda coordenades de la peça que a la que vol accedir el usuari
        originPiece = chessBoard[originRow][originColumn];

        if (originPiece != WHITE[WhiteHorse] && originPiece != BLACK[BlackHorse]) {
            std::cout << "There is no horse on that square.\n";
            continue;
        }

        bool isWhite = isWhitePiece(originPiece);
        bool isBlack = isBlackPiece(originPiece);

        if (turn == White && !isWhite) {
            std::cout << "White's turn, you must choose a white horse.\n";
            continue;
        }
        if (turn == Black && !isBlack) {
            std::cout << "Black's turn, you must choose a black horse.\n";
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
    // Guarda coordenades a les que vol anar el usuari
    char destinationPiece = chessBoard[destinationRow][destinationColumn];

    // Amb aixó validem els moviments de la peça
    int rowDifference = destinationRow - originRow;
    int columnDifference = destinationColumn - originColumn;

    if (rowDifference < 0) rowDifference = -rowDifference;
    if (columnDifference < 0) columnDifference = -columnDifference;

    // Patro del caball en L: 2-1 o 1-2
    bool validHorseMove =
        (rowDifference == 1 && columnDifference == 2) ||
        (rowDifference == 2 && columnDifference == 1);

    if (!validHorseMove) {
        std::cout << "Invalid move for horse.\n";
        return;
    }

    bool whiteHorse = isWhitePiece(originPiece);
    bool blackHorse = isBlackPiece(originPiece);

    if (whiteHorse) {
        if (isBlackPiece(destinationPiece)) {
            chessBoard[destinationRow][destinationColumn] = originPiece;
            chessBoard[originRow][originColumn] = EMPTY_SQUARE;
            std::cout << "Horse captured an enemy piece.\n";
        }
        else if (isWhitePiece(destinationPiece)) {
            std::cout << "You cannot capture your own piece.\n";
            return;
        }
        else if (isEmptySquare(destinationPiece)) {
            chessBoard[destinationRow][destinationColumn] = originPiece;
            chessBoard[originRow][originColumn] = EMPTY_SQUARE;
            std::cout << "Horse moved to target square.\n";
        }
    }

    if (blackHorse) {
        if (isWhitePiece(destinationPiece)) {
            chessBoard[destinationRow][destinationColumn] = originPiece;
            chessBoard[originRow][originColumn] = EMPTY_SQUARE;
            std::cout << "Horse captured an enemy piece.\n";
        }
        else if (isBlackPiece(destinationPiece)) {
            std::cout << "You cannot capture your own piece.\n";
            return;
        }
        else if (isEmptySquare(destinationPiece)) {
            chessBoard[destinationRow][destinationColumn] = originPiece;
            chessBoard[originRow][originColumn] = EMPTY_SQUARE;
            std::cout << "Horse moved to target square.\n";
        }
    }
}
