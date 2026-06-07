#include <iostream>
#include "board.h"
#include "king.h"
#include "pieceColor.h"
#include "constants.h"
#include "turn.h"

/**
 *  Mou el rei del jugador actual, si es pot
 */

void moveKing(char chessBoard[BOARD][BOARD], Turn turn) {

    int originRow, originColumn;
    char originPiece;

    // Loop per escollir el rei de qui ha de moure
    while (true) {
        std::cout << "Select the king you want to move\n";
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

        // Emmagatzma les coordenades de la pe�a que es vol fer servir
        originPiece = chessBoard[originRow][originColumn];

        // Comprovaci� de si hi ha un rei a la casella
        if (originPiece != WHITE[WhiteKing] && originPiece != BLACK[BlackKing]) {
            std::cout << "There is no king on that square.\n";
            continue;
        }

        bool isWhite = isWhitePiece(originPiece);
        bool isBlack = isBlackPiece(originPiece);

        // Comprovar que el rei coincideix amb el torn
        if (turn == White && !isWhite) {
            std::cout << "White's turn, you must choose the white king.\n";
            continue;
        }
        if (turn == Black && !isBlack) {
            std::cout << "Black's turn, you must choose the black king.\n";
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

    // Validaci� del moviment
    int rowDifference = destinationRow - originRow;
    int columnDifference = destinationColumn - originColumn;

    if (rowDifference < 0) rowDifference = -rowDifference;
    if (columnDifference < 0) columnDifference = -columnDifference;

    /**
 * Moviment vàlid del rei:
 *  - Una casella en vertical (difFila = 1, difCol = 0)
 *  - Una casella en horitzontal (difFila = 0, difCol = 1)
 *  - Una casella en diagonal (difFila = 1, difCol = 1)
 */
    bool validKingMove =
        (rowDifference == 1 && columnDifference == 1) ||
        (rowDifference == 1 && columnDifference == 0) ||
        (rowDifference == 0 && columnDifference == 1);

    if (!validKingMove) {
        std::cout << "Invalid move for king.\n";
        return;
    }

    bool whiteKing = isWhitePiece(originPiece);
    bool blackKing = isBlackPiece(originPiece);

    // Moviment del rei blanc
    if (whiteKing) {
        if (isBlackPiece(destinationPiece)) {
            chessBoard[destinationRow][destinationColumn] = originPiece;
            chessBoard[originRow][originColumn] = EMPTY_SQUARE;
            std::cout << "King captured an enemy piece.\n";
        }
        else if (isWhitePiece(destinationPiece)) {
            std::cout << "You cannot capture your own piece.\n";
            return;
        }
        else if (isEmptySquare(destinationPiece)) {
            chessBoard[destinationRow][destinationColumn] = originPiece;
            chessBoard[originRow][originColumn] = EMPTY_SQUARE;
            std::cout << "King moved to target square.\n";
        }
    }
    // Moviment del rei negre
    if (blackKing) {
        if (isWhitePiece(destinationPiece)) {
            chessBoard[destinationRow][destinationColumn] = originPiece;
            chessBoard[originRow][originColumn] = EMPTY_SQUARE;
            std::cout << "King captured an enemy piece.\n";
        }
        else if (isBlackPiece(destinationPiece)) {
            std::cout << "You cannot capture your own piece.\n";
            return;
        }
        else if (isEmptySquare(destinationPiece)) {
            chessBoard[destinationRow][destinationColumn] = originPiece;
            chessBoard[originRow][originColumn] = EMPTY_SQUARE;
            std::cout << "King moved to target square.\n";
        }
    }
}
