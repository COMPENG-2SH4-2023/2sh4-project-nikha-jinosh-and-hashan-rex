#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here
    
    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        
        int boardSizeX;
        int boardSizeY;

        bool loseFlag; // Declare loseFlag
        int score;     // Declare score
        objPos foodPos;
        
        int** myGM; // heap data member

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // Destructor
        
        bool getExitFlagStatus();
        void setExitTrue();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();

        void incrementScore();
        bool getLoseFlagStatus();
        void setLoseTrue();
        int getScore();

        void setLoseFlag();

        void generateFood(objPosArrayList *blockOff); 
        void getFoodPos(objPos &returnPos);
};

#endif