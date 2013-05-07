/**
 * king.h
 *
 * This class represents a chess king piece.
 *
 */

#ifndef KING_H
#define KING_H

#include <iostream>
#include "restrictedPiece.h"

using namespace std;

class King : public RestrictedPiece
{
 public:

   /**
    * Creates a King
    *
    * @param color the color of the piece
    */
    King(bool isWhite);
    
    /**
     * Default destructor
     */
    ~King();

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

}; // King

#endif
