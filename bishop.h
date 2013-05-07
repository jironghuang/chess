/**
 * bishop.h
 *
 * This class represents a chess bishop piece.
 *
 */

#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include "piece.h"
#include "square.h"

using namespace std;

class Bishop : public Piece
{
 public:
    
    /**
    * Creates a Bishop
    *
    * @param color the color of the piece
    */
    Bishop(bool isWhite);
    
    /**
     * Default destructor
     */
    ~Bishop();

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

}; // Bishop

#endif
