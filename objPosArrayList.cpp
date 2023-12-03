#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; // 200 elements on the heap
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

// objPosArrayList::objPosArrayList(const objPosArrayList &l)
// {
    // aList = new objPos[ARRAY_MAX_CAP];
    // for (int i = 0; i < listSize; i++)
    //     aList[i] = l.aList[i];
// }

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize == arrayCapacity)
    {
        return;
    }
    
    for(int i = listSize ; i > 0; i--)
    {
        aList[i].setObjPos(aList[i-1]); // this shuffles all the elements towards the tail
    }
    
    aList[0].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == arrayCapacity)
    {
        return;
    }

    aList[listSize++].setObjPos(thisPos);
}

void objPosArrayList::removeHead()
{
    if (listSize <= 0)
    {
        return;
    }

    for (int i = 0; i < listSize - 1 ; i++)
    {
        aList[i] = aList[i+1];
    }
    listSize--; 
}

void objPosArrayList::removeTail()
{
    if (listSize <= 0)
    {
        return;
    }

    listSize--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}