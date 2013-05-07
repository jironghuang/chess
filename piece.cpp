/*
 *  piece.cpp
 *  ChessProject
 */
#include <string>
#include "piece.h"
#include "player.h"

Piece::Piece(bool isWhite) : _isWhite(isWhite), _square(NULL)
{
    if(isWhite)
        _color = "W";
    else
        _color = "B";
}

Piece::~Piece()
{
}

bool Piece::moveTo(Player& byPlayer, Square& toSquare)
{
    bool validMove = false;
    Piece* toCapture = NULL;
    Square* fromSquare = _square;
    
    // check if this is being moved by its player
    if(_isWhite == byPlayer.isWhite())
    {
        // check if this is moving according to the correct geometry
        if(canMoveTo(toSquare))
        {
            // check if toSquare is occupied by a piece that could be captured
            if(toSquare.occupied())
            {
                toCapture = toSquare.occupiedBy();
                
                // move only valid if piece to capture is of different color
                if(toCapture->isWhite() != byPlayer.isWhite())
                {
                    validMove = true;
                }
            }
            // if there isn't a capture and we've made it this far, the move is valid
            else 
            {
                validMove = true;
            }

            if(validMove)
            {
                // tentatively make the move:
                // tentatively take opponent's piece off the board, if needed
                if(toCapture)
                {
                    toCapture->setLocation(NULL);
                } 
                
                // unset this piece's current square's occupant
                _square->setOccupier(NULL);
                
                // set this piece's new location
                _square = &toSquare;
                
                // set new square's occupant
                _square->setOccupier(this);
                
                // check if the move leaves byPlayer's king in check
                if(byPlayer.inCheck())
                {
                    // if in check, move is invalid
                    validMove = false;
                    
                    // undo the move:
                    // reset this piece's location
                    _square = fromSquare;
                    
                    // update the square's occupant
                    _square->setOccupier(this);
                    
                    // reset the other square's occupant with opponent's piece or NULL
                    toSquare.setOccupier(toCapture);
                    
                    // if a piece was tentatively captured, put it back
                    if(toCapture)
                    {
                        toCapture->setLocation(&toSquare);
                    }
                }
                else 
                {
                    // if not in check, move is valid, so actually
                    // capture the opponent's piece, if needed
                    if(toCapture)
                    {
                        byPlayer.capture(toCapture);
                    } 
                }
            }
        }
    }
    
    return validMove;
}

void Piece::setLocation(Square* location)
{
    _square = location;
}

bool Piece::isWhite() const
{
    return _isWhite;
}

string Piece::color() const
{
    return _color;
}

bool Piece::isOnSquare() const
{
    return _square;
}

Square* Piece::location() const
{
    return _square;
}

