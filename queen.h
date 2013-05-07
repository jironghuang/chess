/**
 * queen.h
 *
 * This class represents a chess queen piece.
 *
 */

#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include "square.h"
#include "piece.h"

using namespace std;

class Queen : public Piece
{
 public:
    
    /**
    * Creates a Queen
    *
    * @param color the color of the piece
    */
    Queen(bool isWhite);
    
    /**
     * Default destructor
     */
    ~Queen();

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

}; // Queen

#endif