/**
 * restrictedPiece.h
 *
 * This class represents a chess piece that knows if it has 
 * previously been moved.
 *
 */

#ifndef RESTRICTED_H
#define RESTRICTED_H

#include "piece.h"

class Player;

using namespace std;

class RestrictedPiece : public Piece
{
 public:
    
    /**
    * Creates a RestrictedPiece
    *
    * @param color the color of the piece
    */
    RestrictedPiece(bool isWhite);
    
    /**
     * Default destructor
     */
    virtual ~RestrictedPiece();

    /**
    * Move the piece to another square.
    *
    * @return successful move
    */
    virtual bool moveTo(Player& byPlayer, Square& to);

    /**
    * Get if the piece has been moved previously
    *
    * @return if moved
    */
    bool hasMoved() const;

 private:
   
    // private attributes
    bool _moved;

}; // RestrictedPiece

#endif