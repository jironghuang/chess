/*
 *  restrictedPiece.cpp
 *  ChessProject
 */
#include "player.h"
#include "restrictedPiece.h"

RestrictedPiece::RestrictedPiece(bool isWhite) : Piece(isWhite)
{
    _moved = false;
}
    
RestrictedPiece::~RestrictedPiece()
{
}

bool RestrictedPiece::moveTo(Player& byPlayer, Square& to)
{
    bool validMove = Piece::moveTo(byPlayer, to);
    
    // only change _moved if a valid move is made 
    // and this piece hasn't already been moved
    if(validMove && !_moved)
    {
        _moved = true;
    }
    
    return validMove;
}

bool RestrictedPiece::hasMoved() const
{
    return _moved;
}

