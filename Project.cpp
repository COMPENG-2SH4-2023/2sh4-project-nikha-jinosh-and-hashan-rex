#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  

    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(30, 15); // Makes board size 30x15
    myPlayer = new Player(myGM);

    objPosArrayList* tempPos;
    myGM->generateFood(tempPos);
}

void GetInput(void)
{
    myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    bool drawn;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPos tempFoodPos;
    myGM->getFoodPos(tempFoodPos);

    // Prints game board
    for (int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for (int j = 0; j < myGM->getBoardSizeX(); j++)
        {
            drawn = false;
            // Iterates through every element in the list
            for (int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                if(tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if (drawn) continue; // If player bodty was drawn, don't draw anything below

            if (i == 0 || j == 0 || i == myGM->getBoardSizeY() - 1 || j ==  myGM->getBoardSizeX() - 1)
            {
                MacUILib_printf("#");
            }
            else if (j == tempFoodPos.x && i == tempFoodPos.y)
            {
                MacUILib_printf("%c", tempFoodPos.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Score: %d\n", myGM->getScore());

    if (myGM->getExitFlagStatus())
    {
        MacUILib_printf("");
    }

    if (myGM->getLoseFlagStatus())
    {
        MacUILib_printf("Game Ended!");
    }


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    // Removes heap instances
    // delete myGM;
    // delete myPlayer;
}
