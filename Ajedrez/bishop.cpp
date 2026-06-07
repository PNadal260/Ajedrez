#include <iostream>
#include "board.h"
#include "bishop.h"
#include "pieceColor.h"
#include "constants.h"
#include "turn.h"

/**
 * Mou l'alfil del jugador actual, si es pot
 */

void moveBishop(char chessBoard[BOARD][BOARD], Turn turn) {

    int originRow, originColumn;
    char originPiece;

    // Loop per escollir l'alfil de qui ha de moure
    while (true) {

        std::cout << "Select the bishop you want to move.\n";
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

        // Emmagatzma les coordenades de la peça que es vol fer servir
        originPiece = chessBoard[originRow][originColumn];

        // Comprovació de si hi ha un alfil a la casella
        if (originPiece != WHITE[WhiteBishop] && originPiece != BLACK[BlackBishop]) {
            std::cout << "There is no bishop on that square.\n";
            continue;
        }

        bool isWhite = isWhitePiece(originPiece);
        bool isBlack = isBlackPiece(originPiece);

        // Comprovar que l'alfil coincideix amb el torn
        if (turn == White && !isWhite) {
            std::cout << "White's turn. You must choose a white bishop.\n";
            continue;
        }
        if (turn == Black && !isBlack) {
            std::cout << "Black's turn. You must choose a black bishop.\n";
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
    char destinationPiece = chessBoard[destinationRow][destinationColumn];

    // Validació del moviment
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

    // Comprovació que únicament es mogui de forma diagonal
    if (absoluteRowDifference != absoluteColumnDifference) {
        std::cout << "Invalid move for bishop. It must move diagonally.\n";
        return;
    }

    int rowStep;
    int columnStep;

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

    int currentRow = originRow + rowStep;
    int currentColumn = originColumn + columnStep;

    while (currentRow != destinationRow || currentColumn != destinationColumn) {
        if (!isEmptySquare(chessBoard[currentRow][currentColumn])) {
            std::cout << "There is a piece blocking the bishop's path.\n";
            return;
        }
        currentRow = currentRow + rowStep;
        currentColumn = currentColumn + columnStep;
    }

    bool whiteBishop = isWhitePiece(originPiece);
    bool blackBishop = isBlackPiece(originPiece);

    if (whiteBishop) {
        if (isWhitePiece(destinationPiece)) {
            std::cout << "You cannot capture your own piece.\n";
            return;
        }
        chessBoard[destinationRow][destinationColumn] = originPiece;
        chessBoard[originRow][originColumn] = EMPTY_SQUARE;
        std::cout << "The white bishop has moved.\n";
    }

    if (blackBishop) {
        if (isBlackPiece(destinationPiece)) {
            std::cout << "You cannot capture your own piece.\n";
            return;
        }
        chessBoard[destinationRow][destinationColumn] = originPiece;
        chessBoard[originRow][originColumn] = EMPTY_SQUARE;
        std::cout << "The black bishop has moved.\n";
    }
}
