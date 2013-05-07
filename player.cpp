/*
 *  player.cpp
 *  ChessProject
 *
 */
#include <iostream>
#include "player.h"
#include "board.h"
#include "game.h"

#define X_MIN 'a'
#define X_MAX 'h'
#define Y_MIN '1'
#define Y_MAX '8'

Player::Player(string name, bool isWhite, King& myKing, set<Piece*>& myPieces) :
_name(name), _isWhite(isWhite), _myPieces(myPieces), _myKing(myKing)
{
}

Player::~Player()
{
}

bool Player::makeMove()
{
    string badInput; // string for throwing away invalid input
    string fromSquare =  "  ";
    string toSquare = "  ";
    int fromX;
    int fromY;
    int toX;
    int toY;
    
    // check/announce if player is in check
    if(inCheck())
    {
        cout << _name << " is in check!" << endl;
    }
    
    // get move from player input
    cout << _name << " player enter move (e.g. a2 a4): ";
    cin >> fromSquare >> toSquare;
    
    // move must be in algebraic notation 
    // (start and end squares denoted by 2 characters, a1-h8,
    // and separated from each other by whitespace)
    // move cannot start from an empty square
    while(fromSquare.length() != 2 ||
          toSquare.length() != 2 ||
          tolower(fromSquare.at(0)) < X_MIN ||
          tolower(fromSquare.at(0)) > X_MAX ||
          tolower(toSquare.at(0)) < X_MIN ||
          tolower(toSquare.at(0)) > X_MAX ||
          tolower(fromSquare.at(1)) < Y_MIN ||
          tolower(fromSquare.at(1)) > Y_MAX ||
          tolower(toSquare.at(1)) < Y_MIN ||
          tolower(toSquare.at(1)) > Y_MAX ||
          !(Board::getBoard()->squareAt(tolower(fromSquare.at(0)) - X_MIN, 
                                      tolower(fromSquare.at(1)) - Y_MIN)->occupied())
          )
    {
        cerr << "Invalid move. Try again." << endl;
        cin.clear();
        getline(cin, badInput); // take bad input off the stream and ignore it
        cout << _name << " player enter move (e.g. a2 a4): ";
        cin >> fromSquare >> toSquare;
    }
    
    // translate input (algebraic notation) into board coordinates
    fromX = tolower(fromSquare.at(0)) - X_MIN;
    fromY = tolower(fromSquare.at(1)) - Y_MIN;
    toX = tolower(toSquare.at(0)) - X_MIN;
    toY = tolower(toSquare.at(1)) - Y_MIN;
    
    // move the piece on fromSquare to toSquare
    return Board::getBoard()->squareAt(fromX, fromY)->occupiedBy()->moveTo(*this, 
                                                                  *(Board::getBoard()->squareAt(toX, toY)));
}

bool Player::inCheck()
{
    bool check = false;
    
    // for each piece in the opponent's set of pieces
    for (set<Piece*>::iterator itr = Game::opponentOf(*this)->myPieces()->begin(); 
         itr != Game::opponentOf(*this)->myPieces()->end(); ++itr)
    {
        // if a piece that is still located on the board
        // can move to my king's square
        if (((Piece*)*itr)->location() && 
            ((Piece*)*itr)->canMoveTo(*(myKing()->location())))
        {
            // I am in check
            check = true;
        }
    }
    
    return check;
}

void Player::capture(Piece* aPiece)
{
    // unset the piece's location on the board
    aPiece->setLocation(NULL);
    
    // put the piece into this player's set of captured pieces
    _capturedPieces.insert(aPiece);
}

string Player::getName() const
{
    return _name;
}

bool Player::isWhite() const
{
    return _isWhite;
}

int Player::score() const
{
    int score = 0;
    
    // add up the points of all captured pieces
    for (set<Piece*>::iterator itr = _capturedPieces.begin(); itr != _capturedPieces.end(); ++itr)
    {
        score += ((Piece*)*itr)->value();
    }
    
    return score;
}

set<Piece*>* Player::myPieces() const
{
    return &_myPieces;
}

King* Player::myKing() const
{
    return &_myKing;
}