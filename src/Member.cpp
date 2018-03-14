#include "Member.hpp"
#include <iostream>

Member::Member(Board &board_)
    : steps()
    , board(board_)
{

}

bool Member::isPositionAlreadyCalculated(const std::pair<int, int> position)
{
    bool isPositionAlreadyCalculated = false;

    std::cout << " Position to find in member : \n X : " << position.first << " Y : " << position.second << "\n";

    return isPositionAlreadyCalculated;
}

std::vector<std::pair<int, int>>&& Member::getSuccessfulSteps()
{
    std::vector<std::pair<int, int>> successfulSteps;
    for(auto step : steps)
    {
        successfulSteps.push_back(step.getCoord());
    }

    const int NEED_COUNT_OF_STEPS = 5*5;
    const int RESULT_COUNT_OF_STEPS = successfulSteps.size();

    if( NEED_COUNT_OF_STEPS != RESULT_COUNT_OF_STEPS )
    {
        std::cout << "getSuccessfulSteps return faild count of steps : " << RESULT_COUNT_OF_STEPS<<"\n";
    }

    return std::move(successfulSteps);
}

void Member::setNewStep(const Step step)
{
    board.drawBoardWithStep(step.getCoord());
    steps.push_back(step);
}

Step &Member::getLastStep()
{
    return steps.back();
}

void Member::lastStepIsFaild()
{
    Step faildStep = steps.back();
    faildStep.setIsStepFaild(true);

    board.drawBoardWithoutFaildStep(faildStep.getCoord());

    steps.pop_back();
    steps.back().addNewFaildNextStep(faildStep);
}

int Member::countOfSteps()
{
    return steps.size();
}





