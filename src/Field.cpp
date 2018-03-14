#include "Field.hpp"
#include <iostream>

Field::Field()
    :isVisited(false)
    , numberOfStep(-1)
{

}

Field::~Field()
{

}

void Field::draw()
{
    if (true == isVisited)
    {
        std::cout << " * ";
    }
    else
    {
        std::cout << " 0 " ;
    }
}

bool Field::getIsVisited() const
{
    return isVisited;
}

void Field::setIsVisited(bool value)
{
    isVisited = value;
}

int Field::getNumberOfStep() const
{
    return numberOfStep;
}

void Field::setNumberOfStep(int value)
{
    numberOfStep = value;
}
