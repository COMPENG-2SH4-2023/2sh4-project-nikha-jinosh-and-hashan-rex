#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    loseFlag = false;
    exitFlag = false;

    // default board size
    boardSizeX = 30; 
    boardSizeY = 15; 

    //initializes food position so that its not displayed by putting it outside of the board
    foodPos.setObjPos(-1, -1, 'o'); 
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    score = 0;
    loseFlag = false;
    exitFlag = false;

    // out of bound check
    if( boardX <= 0){
		boardX = 30; 
	}
	if (boardY <= 0){
		boardY = 15;
	}

    // default board size
    boardSizeX = boardX;
    boardSizeY = boardY;

    foodPos.setObjPos(-1, -1, 'o'); 
    score = 0; 
    foodPos.setObjPos(3, 3, 'o'); 
}

// do you need a destructor?
GameMechs::~GameMechs()
{
   delete [] GM; // delete created heap data members
}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

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

void GameMechs::setLoseFlag() 
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::setLoseTrue()
{
    loseFlag = true;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}


void GameMechs::generateFood(objPosArrayList *blockOff)
{
    srand(time(NULL));
    //random generation of x and y coordinates 
    // generating number betwwen 0 - (cols-2 = 18)
    foodPos.x = (rand() % (boardSizeX - 2)) + 1; 
    foodPos.y = (rand() % (boardSizeY - 2)) + 1; 
    
    // looping through each item in blockOff array
    objPos tempPos;
    
    for(int i = 0; i < blockOff->getSize(); i++)
        {
        blockOff->getElement(tempPos, i);
        while(foodPos.isPosEqual(&tempPos)) 
            foodPos.x = (rand() % (boardSizeX - 2)) + 1; // regenerating x
            foodPos.y = (rand() % (boardSizeX - 2)) + 1; // regenerating y
        }
}


void GameMechs::getFoodPos(objPos &returnFood)
{
    //Getter method for obtaining the current position of the food
    returnFood.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}
