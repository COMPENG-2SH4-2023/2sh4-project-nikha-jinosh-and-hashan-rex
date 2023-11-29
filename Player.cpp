#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2,
                        mainGameMechsRef->getBoardSizeY() / 2, 
                        '*'); // Sets default player pos
}


Player::~Player()
{
    // delete any heap members here

    // Come back for Iteration 3
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
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
    // PPA3 Finite State Machine logic

    switch(myDir)
    {
        case UP:
            playerPos.y--;
            if (playerPos.y <= 0) // Wraparound logic
                playerPos.y = mainGameMechsRef->getBoardSizeY() - 2;
            break;
        case LEFT:
            playerPos.x--;
            if (playerPos.x <= 0) // Wraparound logic
                playerPos.x = mainGameMechsRef->getBoardSizeX() - 2;
            break;
        case DOWN:
            playerPos.y++;
            if (playerPos.y >= mainGameMechsRef->getBoardSizeY()) // Wraparound logic
                playerPos.y = 1;
            break;
        case RIGHT:
            playerPos.x++;
            if (playerPos.x >= mainGameMechsRef->getBoardSizeX()) // Wraparound logic
                playerPos.x = 1;
            break;
        case STOP:
        default:
            break;
    }
}

