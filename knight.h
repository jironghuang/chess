/**
 * knight.h
 *
 * This class represents a chess knight piece.
 *
 */

#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include "square.h"
#include "piece.h"

using namespace std;

class Knight : public Piece
{
 public:
    
    /**
    * Creates a Knight
    *
    * @param color the color of the piece
    */
    Knight(bool isWhite);
    
    /**
     * Default destructor
     */
    ~Knight();

    /**
    * Get the point value of the piece
    *
    * @return the value
    */
    int value() const;

    /**
    * Determines if the piece can legally move to a given square
    *
    * @param square the square to move to
    * @return if move is legal
    */
    bool canMoveTo(Square& location) const;
    
    /**
     * Display the piece
     * @param outStream the output stream
     */
    void display() const;

}; // Knight

#endif
