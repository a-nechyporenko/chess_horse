#include "Step.hpp"
#include <iostream>

Step::Step()
    : coord(-1,-1)
    , FailedNextSteps()
    , isStepFailed(false)
{

}

Step::Step(int x, int y)
    : coord(x,y)
    , FailedNextSteps()
    , isStepFailed(false)
{

}

Step::Step(const std::pair<int, int> &coord_, bool isStepFailed_)
    : coord(coord_)
    , FailedNextSteps()
    , isStepFailed(isStepFailed_)
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

bool Step::getIsStepFailed() const
{
    return isStepFailed;
}

void Step::setIsStepFailed(bool value)
{
    isStepFailed = value;

    if( false == isStepFailed)
    {
        FailedNextSteps.clear();
    }
}

void Step::addNewFailedNextStep(const Step& step)
{
    FailedNextSteps.push_back(step);

    if( 8 < FailedNextSteps.size())
    {
        std::cout << "It`s imposble that node have more than 8 next node";
    }
}

bool Step::isNextStepAlreadyInFailed(const std::pair<int, int> &nextStepCoord)
{
    //TODO use findif!!!
    for(auto FailedStep : FailedNextSteps)
    {
        if( nextStepCoord == FailedStep.getCoord() )
        {
            return true;
        }
    }

    return false;
}

std::vector<Step> Step::getFailedNextSteps() const
{
    return FailedNextSteps;
}
