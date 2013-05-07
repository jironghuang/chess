/*
 *  knight.cpp
 *  ChessProject
 */
#include "knight.h"

Knight::Knight(bool isWhite) : Piece(isWhite)
{
}

Knight::~Knight()
{
}

int Knight::value() const
{
    return 3;
}

bool Knight::canMoveTo(Square& location) const
{
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();
    int translationY = location.getY() - this->location()->getY();
    
    // valid move if moving 1 square forward/backwards
    // and 2 squares sideways
    if(abs(translationY) == 1 && abs(translationX) == 2)
    {
        validMove = true;
    }
    
    // valid move if moving 1 square sideways and 2 squares
    // forward/backwards
    else if(abs(translationX) == 1 && abs(translationY) == 2)
    {
        validMove = true;
    }
    
    return validMove;
}

void Knight::display() const
{
    cout << _color + "N";
}



