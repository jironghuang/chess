/*
 *  bishop.cpp
 *  ChessProject
 *
 *
 */
#include "bishop.h"

Bishop::Bishop(bool isWhite) : Piece(isWhite)
{
}

Bishop::~Bishop()
{
}

int Bishop::value() const
{
    return 3;
}

bool Bishop::canMoveTo(Square& location) const
{
    bool validMove = false;
    
    // valid move if moving on a clear diagonal
    if(Board::getBoard()->isClearDiagonal(*(this->location()), location))
    {
        validMove = true;
    }
    
    return validMove;
}

void Bishop::display() const
{
    cout << _color + "B";
}