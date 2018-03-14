#include "Step.hpp"
#include <iostream>

Step::Step()
    : coord(-1,-1)
    , faildNextSteps()
    , isStepFaild(false)
{

}

Step::Step(int x, int y)
    : coord(x,y)
    , faildNextSteps()
    , isStepFaild(false)
{

}

Step::Step(const std::pair<int, int> &coord_, bool isStepFaild_)
    : coord(coord_)
    , faildNextSteps()
    , isStepFaild(isStepFaild_)
{

}

const std::pair<int, int>& Step::getCoord() const
{
    return coord;
}

void Step::setCoord(const std::pair<int, int> &value)
{
    coord = value;
}

bool Step::getIsStepFaild() const
{
    return isStepFaild;
}

void Step::setIsStepFaild(bool value)
{
    isStepFaild = value;

    if( false == isStepFaild)
    {
        faildNextSteps.clear();
    }
}

void Step::addNewFaildNextStep(const Step& step)
{
    faildNextSteps.push_back(step);

    if( 8 < faildNextSteps.size())
    {
        std::cout << "It`s imposble that node have more than 8 next node";
    }
}

bool Step::isNextStepAlreadyInFaild(const std::pair<int, int> &nextStepCoord)
{
    //TODO use findif!!!
    for(auto faildStep : faildNextSteps)
    {
        if( nextStepCoord == faildStep.getCoord() )
        {
            return true;
        }
    }

    return false;
}

std::vector<Step> Step::getFaildNextSteps() const
{
    return faildNextSteps;
}
