#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
   //clean up code
}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    exitFlag = true;
}

void GameMechs::clearInput()
{
    input = '\0';
}

void GameMechs::incrementScore()
{
    score++;
}

