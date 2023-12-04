#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2,
                        mainGameMechsRef->getBoardSizeY() / 2, 
                        '*'); // Sets default player pos

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);


}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
    // Come back for Iteration 3
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic

    // Where to get input. How do i check for input.
    char input = mainGameMechsRef->getInput();

    switch(input)
    {
        case 87:
        case 119: // W key
            if (myDir == LEFT || myDir == RIGHT || myDir == STOP)
            {
                myDir = UP;
            }
            break;
        case 65:
        case 97: // A key
            if (myDir == UP || myDir == DOWN || myDir == STOP)
            {
                myDir = LEFT;
            }
            break;
        case 83:
        case 115: // S key
            if (myDir == LEFT || myDir == RIGHT || myDir == STOP)
            {
                myDir = DOWN;
            }
            break;
        case 68:
        case 100: // D key
            if (myDir == UP || myDir == DOWN || myDir == STOP)
            {
                myDir = RIGHT;
            }
            break;
        default:
            break;
    }

    mainGameMechsRef->clearInput();        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic'
    objPos currentHead; // Holds the pos information of the current head
    playerPosList->getHeadElement(currentHead);

    switch(myDir)
    {
        case UP:
            currentHead.y--;
            if (currentHead.y <= 0) // Wraparound logic
                currentHead.y = mainGameMechsRef->getBoardSizeY() - 2;
            break;
        case LEFT:
            currentHead.x--;
            if (currentHead.x <= 0) // Wraparound logic
                currentHead.x = mainGameMechsRef->getBoardSizeX() - 2;
            break;
        case DOWN:
            currentHead.y++;
            if (currentHead.y >= mainGameMechsRef->getBoardSizeY() - 1) // Wraparound logic
                currentHead.y = 1;
            break;
        case RIGHT:
            currentHead.x++;
            if (currentHead.x >= mainGameMechsRef->getBoardSizeX() - 1) // Wraparound logic
                currentHead.x = 1;
            break;
        case STOP:
        default:
            break;
    }

    //New current ehads gets inserted to the head of the lost
    if (checkSelfCollision() == true)
    {
        mainGameMechsRef->setExitTrue();
    }

    //New current ehads gets inserted to the head of the lost


    if (checkFoodConsumption() == true)
    {
        playerPosList->insertHead(currentHead);
        mainGameMechsRef->incrementScore();
        
        objPosArrayList* tempPos = new objPosArrayList();
        mainGameMechsRef->generateFood(tempPos);
    }
    else
    {
        playerPosList->insertHead(currentHead);
        playerPosList->removeTail();
    }


}

bool Player::checkFoodConsumption()
{
    objPos currentHead; // Holds the pos information of the current head
    playerPosList->getHeadElement(currentHead);

    objPos tempFoodPos;
    mainGameMechsRef->getFoodPos(tempFoodPos);

    if (currentHead.x == tempFoodPos.x && currentHead.y == tempFoodPos.y)
    {
        return true;
    }
    return false;

}

void Player::increasePlayerLength()
{
    // Not used
    objPosArrayList* playerBody = getPlayerPos();
    objPos tempBody;
    // playerBody->insertHead(tempBody);

    objPos currentHead; // Holds the pos information of the current 
    

    // playerPosList->getHeadElement(currentHead);

    // playerPosList->insertHead(currentHead);




}

bool Player::checkSelfCollision()
{
    objPos currentHead; // Holds the pos information of the current head
    playerPosList->getHeadElement(currentHead);
    
    objPosArrayList* playerBody = getPlayerPos();
    objPos tempBody;

    for (int i = 1; i < playerBody->getSize(); i++)
    {
        playerBody->getElement(tempBody, i);
        if (currentHead.x == tempBody.x && currentHead.y == tempBody.y)
        {
            return true;
        }
    }
    return false;
}

