/**
 * board.h
 *
 * This class represents a game board.
 *
 */

#ifndef BOARD_H
#define BOARD_H

#include <ostream>
#include "square.h"

using namespace std;

class Board 
{
 public:

    /**
     * Default destructor
     */
    ~Board();

    /**
    * Get the board
    *
    * @return the board
    */
    static Board* getBoard();

    /**
    * Get a specific square on the board
    *
    * @params x, y the location of the square on the board
    * @return the square
    */
    Square* squareAt(int x, int y) const;

    /**
    * Determine if the path between two squares is a clear vertical
    *
    * @param from the starting square
    * @param to the ending square
    * @return if the path is a clear vertical
    */
    bool isClearVertical(Square& from, Square& to) const;

    /**
    * Determine if the path between two squares is a clear horizontal
    *
    * @param from the starting square
    * @param to the ending square
    * @return if the path is a clear horizontal
    */
    bool isClearHorizontal(Square& from, Square& to) const;

    /**
    * Determine if the path between two squares is a clear diagonal
    *
    * @param from the starting square
    * @param to the ending square
    * @return if the path is a clear diagonal
    */
    bool isClearDiagonal(Square& from, Square& to) const;
    
    /**
     * Determine if the square is on an ending row of the board
     *
     * @param square the square to check
     * @return if the square is on an end row
     */
    bool isEndRow(Square& location) const;

    /**
    * Display the board
    *
    * @param outStream the output stream
    */
    void display(ostream& outStream) const;


 private:
    
    /**
     * Creates an 8x8 Board
     *
     */
    Board();

    // Private attributes
    static Board* _theBoard;
    static const int _DIMENSION = 8;
    Square* _squares[_DIMENSION][_DIMENSION];

}; // Board

#endif
