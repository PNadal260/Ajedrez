#pragma once

/**
 * Retorna si el caràcter representa una peça blanca.
 *
 * Les peçes blanques s'emmagatzemen amb les lletres majùscules ASCII (A-Z).
 */

inline bool isWhitePiece(char c) {
    return c >= 'A' && c <= 'Z';
}

/**
 * Retorna si el caràcter representa una peça negra.
 *
 * Les peçes blanques s'emmagatzemen amb les lletres minùscules ASCII (a-z).
 */

inline bool isBlackPiece(char c) {
    return c >= 'a' && c <= 'z';
}

/**
 * Retorna si el caràcter representa una casella buida.
 *
 * Les caselles buides es representen amb el caràcter '*'.
 */
inline bool isEmptySquare(char c) {
    return c == '*';
}
