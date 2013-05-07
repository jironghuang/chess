/**
 * pawn.h
 *
 * This class represents a chess pawn piece.
 *
 */

#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "square.h"
#include "restrictedPiece.h"

using namespace std;

class Pawn : public RestrictedPiece
{
 public:
    
    /**
    * Creates a Pawn
    *
    * @param color the color of the piece
    */
    Pawn(bool isWhite);
    
    /**
     * Default destructor
     */
    ~Pawn();

    /**
    * Set which square the piece is located on
    *
    * @param location the square
    */
    void setLocation(Square* location);

    /**
    * Get the point value of the piece
    *
    * @return the value
    */
    int value() const;
    
    /**
     * Move the piece to another square.
     *
     * @return successful move
     */
    bool moveTo(Player& byPlayer, Square& to);

    /**
    * Determines if the piece can legally move to a given square
    * based on the geometry of the move
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
   
   
 private:

    // Private attributes
    Piece* _delegate;

}; // Pawn

#endif
