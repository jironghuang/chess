/*
 *  square.cpp
 *  ChessProject
 */
#include "piece.h"
#include "square.h"

Square::Square(int x, int y) : _x(x), _y(y), _piece(NULL)
{
}

Square::~Square()
{
}

void Square::setOccupier(Piece* piece)
{
    _piece = piece;
}

int Square::getX() const
{
    return _x;
}

int Square::getY() const
{
    return _y;
}

bool Square::occupied() const
{
    return _piece;
}

Piece* Square::occupiedBy() const
{
    return _piece;
}