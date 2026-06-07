#include <iostream>
#include "board.h"
#include "queen.h"
#include "pieceColor.h"
#include "constants.h"
#include "turn.h"

/**
 * Mou la reina del jugador actual, si es pot
 */

void moveQueen(char chessboard[BOARD][BOARD], Turn turn) {

    int originRow, originColumn;
    char originPiece;

    // Loop per escollir la reina de qui ha de moure
    while (true) {

        std::cout << "Select the QUEEN you want to move.\n";
        std::cout << "Enter origin row (1-" << BOARD << "): ";
        std::cin >> originRow;
        std::cout << "Enter origin column (1-" << BOARD << "): ";
        std::cin >> originColumn;

        originRow--;
        originColumn--;

        if (originRow < 0 || originRow >= BOARD ||
            originColumn < 0 || originColumn >= BOARD) {
            std::cout << "Coordinates out of the board.\n";
            continue;
        }

        // Emmagatzma les coordenades de la pe�a que es vol fer servir
        originPiece = chessboard[originRow][originColumn];

        // Comprovaci� de si hi ha una reina a la casella
        if (originPiece != WHITE[WhiteQueen] && originPiece != BLACK[BlackQueen]) {
            std::cout << "There is no queen on that square.\n";
            continue;
        }

        bool isWhite = isWhitePiece(originPiece);
        bool isBlack = isBlackPiece(originPiece);

        // Comprovar que la reina coincideix amb el torn
        if (turn == White && !isWhite) {
            std::cout << "White's turn. You must choose the white queen.\n";
            continue;
        }
        if (turn == Black && !isBlack) {
            std::cout << "Black's turn. You must choose the black queen.\n";
            continue;
        }

        break;
    }

    int destinationRow, destinationColumn;
    std::cout << "Enter the destination square.\n";
    std::cout << "Enter destination row (1-" << BOARD << "): ";
    std::cin >> destinationRow;
    std::cout << "Enter destination column (1-" << BOARD << "): ";
    std::cin >> destinationColumn;

    destinationRow--;
    destinationColumn--;

    if (destinationRow < 0 || destinationRow >= BOARD ||
        destinationColumn < 0 || destinationColumn >= BOARD) {
        std::cout << "Coordinates out of the board.\n";
        return;
    }
    // Emmagatzema les coordenades a les que es vol moure l'usuari
    char destinationPiece = chessboard[destinationRow][destinationColumn];

    // Validaci� del moviment
    int rowDifference = destinationRow - originRow;
    int columnDifference = destinationColumn - originColumn;

    int absoluteRowDifference = rowDifference;
    int absoluteColumnDifference = columnDifference;

    if (absoluteRowDifference < 0) {
        absoluteRowDifference = -absoluteRowDifference;
    }
    if (absoluteColumnDifference < 0) {
        absoluteColumnDifference = -absoluteColumnDifference;
    }

    bool straightMove;
    bool diagonalMove;

    if (rowDifference == 0 || columnDifference == 0) {
        straightMove = true;
    }
    else {
        straightMove = false;
    }

    if (absoluteRowDifference == absoluteColumnDifference) {
        diagonalMove = true;
    }
    else {
        diagonalMove = false;
    }

    // Comprovaci� que �nicament es mogui de forma diagonal, vertical o horitzontal
    if (!straightMove && !diagonalMove) {
        std::cout << "Invalid move for queen. It must be straight or diagonal.\n";
        return;
    }

    int rowStep = 0;
    int columnStep = 0;

    if (straightMove) { //moviment vertical o horitzontal

        if (rowDifference > 0) {
            rowStep = 1;
        }
        else if (rowDifference < 0) {
            rowStep = -1;
        }

        if (columnDifference > 0) {
            columnStep = 1;
        }
        else if (columnDifference < 0) {
            columnStep = -1;
        }

    }
    else { //moviment diagonal

        if (rowDifference > 0) {
            rowStep = 1;
        }
        else {
            rowStep = -1;
        }

        if (columnDifference > 0) {
            columnStep = 1;
        }
        else {
            columnStep = -1;
        }
    }

    int currentRow = originRow + rowStep;
    int currentColumn = originColumn + columnStep;

    while (currentRow != destinationRow || currentColumn != destinationColumn) {
        if (!isEmptySquare(chessboard[currentRow][currentColumn])) {
            std::cout << "There is a piece blocking the queen's path.\n";
            return;
        }
        currentRow = currentRow + rowStep;
        currentColumn = currentColumn + columnStep;
    }

    bool whiteQueen = isWhitePiece(originPiece);
    bool blackQueen = isBlackPiece(originPiece);

    if (whiteQueen) {
        if (isWhitePiece(destinationPiece)) {
            std::cout << "You cannot capture your own piece.\n";
            return;
        }
        chessboard[destinationRow][destinationColumn] = originPiece;
        chessboard[originRow][originColumn] = EMPTY_SQUARE;
        std::cout << "The white queen has moved.\n";
    }

    if (blackQueen) {
        if (isBlackPiece(destinationPiece)) {
            std::cout << "You cannot capture your own piece.\n";
            return;
        }
        chessboard[destinationRow][destinationColumn] = originPiece;
        chessboard[originRow][originColumn] = EMPTY_SQUARE;
        std::cout << "The black queen has moved.\n";
    }
}
