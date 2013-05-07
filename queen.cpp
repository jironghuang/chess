/*
 *  queen.cpp
 *  ChessProject
 *
 *
 */
#include "queen.h"

Queen::Queen(bool isWhite) : Piece(isWhite)
{
}

Queen::~Queen()
{
}

int Queen::value() const
{
    return 9;
}

bool Queen::canMoveTo(Square& location) const
{
    bool validMove = false;
    
    // valid move if moving on a clear vertical
    if(Board::getBoard()->isClearVertical(*(this->location()), location))
    {
        validMove = true;
    }
    
    // valid move if moving on a clear horizontal
    else if(Board::getBoard()->isClearHorizontal(*(this->location()), location))
    {
        validMove = true;
    }
    
    // valid move if moving on a clear diagonal
    else if(Board::getBoard()->isClearDiagonal(*(this->location()), location))
    {
        validMove = true;
    }
    
    
    return validMove;
}

void Queen::display() const
{
    cout << _color + "Q";
}