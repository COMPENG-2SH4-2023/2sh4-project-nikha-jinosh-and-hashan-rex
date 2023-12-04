#include "GameMechs.h"
#include "MacUILib.h"

//constructor that initializes various game-related
GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    loseFlag = false;
    exitFlag = false;

    //default board size
    boardSizeX = 30; 
    boardSizeY = 15; 

    //initializes food position so that its not displayed by putting it outside of the board
    foodPos.setObjPos(-1, -1, 'o'); 
}

//similar constructor to the default constructor 
GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    score = 0;
    loseFlag = false;
    exitFlag = false;

    //checks for out of bound
    if( boardX <= 0){
		boardX = 30; 
	}
	if (boardY <= 0){
		boardY = 15;
	}

    //default board size
    boardSizeX = boardX;
    boardSizeY = boardY;

    foodPos.setObjPos(-1, -1, 'o'); 
    foodPos.setObjPos(3, 3, 'o'); 
}

// do you need a destructor?
GameMechs::~GameMechs()
{
   delete [] myGM; //delete created heap data members
}


//getter methods to retrieve the values of private member variables
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
    //checks if there is any input available and updates the input variable
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

int GameMechs::getScore()
{
    return score;
}


//setter methods to modify the values of private member variables
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

void GameMechs::setLoseTrue()
{
    loseFlag = true;
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::incrementScore()
{
    score++;
}


void GameMechs::generateFood(objPosArrayList *blockOff)
{
    srand(time(NULL));
    
    //random generation of x and y coordinates 
    foodPos.x = (rand() % (boardSizeX - 2)) + 1; 
    foodPos.y = (rand() % (boardSizeY - 2)) + 1; 
    
    //looping through each item in the blockOff array
    objPos tempPos;
    
    for(int i = 0; i < blockOff->getSize(); i++)
        {
        blockOff->getElement(tempPos, i);
        while(foodPos.isPosEqual(&tempPos)) 

            //regenerating x
            foodPos.x = (rand() % (boardSizeX - 2)) + 1;

            //regenerating y 
            foodPos.y = (rand() % (boardSizeX - 2)) + 1; 
        }
}


void GameMechs::getFoodPos(objPos &returnFood)
{
    //getter for obtaining the current position of the food
    returnFood.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}
