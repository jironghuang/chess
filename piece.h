/**
 * piece.h
 *
 * This class represents a game piece.
 *
 */

#ifndef PIECE_H
#define PIECE_H

#include <ostream>
#include "square.h"
#include "board.h"
class Player;

using namespace std;

class Piece 
{
 public:
   
    /**
    * Creates a Piece
    *
    * @param isWhite if the color of the piece is white
    */
    Piece(bool isWhite);
    
    /**
     * Default destructor
     */
    virtual ~Piece();

    /**
    * Move the piece to the square, making sure that the move
    * is legal
    *
    * @param piece the piece on the square
    * @return if legal move was made
    */
    virtual bool moveTo(Player& byPlayer, Square& toSquare);

    /**
    * Set which square the piece is located on
    *
    * @param location the square
    */
    virtual void setLocation(Square* location);

    /**
    * Get the point value of the piece
    *
    * @return the value
    */
    virtual int value() const = 0;

    /**
    * Determine if the piece is white
    *
    * @return if is white
    */
    bool isWhite() const;

    /**
     * Get the piece's color
     *
     * @return the color
     */
    string color() const;    
    
    /**
    * Display the piece
    * @param outStream the output stream
    */
    virtual void display() const = 0;   

    /**
    * Determines if the piece can legally move to a given square
    * based on the geometry of the move
    *
    * @param square the square to move to
    * @return if move is legal
    */
    virtual bool canMoveTo(Square& location) const = 0;

    /**
    * Determines if the piece is on a square
    *
    * @return if on square
    */
    bool isOnSquare() const;

    /**
    * Gets the piece's location
    *
    * @return the square the piece is on
    */
    Square* location() const;

 protected:
    bool _isWhite;
    string _color;
    
 private:

    // Private attributes
    Square* _square;

}; // Piece

#endif
