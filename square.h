/**
 * square.h
 *
 * This class represents a square on a game board.
 *
 */

#ifndef SQUARE_H
#define SQUARE_H

class Piece;

using namespace std;

class Square 
{
 public:
   
    /**
    * Creates a Square
    *
    * @params x, y the location of the square on the board
    */
    Square(int x, int y);
    Square();

    /**
     * Default destructor
     */
    ~Square();
    
    /**
    * Set the piece that occupies the square
    *
    * @param piece the piece on the square
    */
    void setOccupier(Piece* piece);

    /**
    * Get the X position of the square
    *
    * @return the position
    */
    int getX() const;

    /**
    * Get the Y position of the square
    *
    * @return the position
    */
    int getY() const;

    /**
    * Determine if the square is occupied by a piece
    *
    * @return if occupied
    */
    bool occupied() const;   

    /**
    * Get the Piece that is on the square
    *
    * @return the piece
    */
    Piece* occupiedBy() const;


 private:

    // Private attributes
    int _x;
    int _y;
    Piece* _piece;

}; // Square

#endif
