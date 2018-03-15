
#include "Horse.hpp"
#include "Step.hpp"

Horse::Horse(Member &member_, Board &board_)
    : member(member_)
    , board(board_)
    , curentStep()
    , curentVariant(VariantsOfSteps::TopRight)
{

}

bool Horse::moveHorse()
{
    bool isHorseHaveSteps = true;
    curentStep = member.getLastStep().getCoord();
    curentVariant = VariantsOfSteps::TopRight;

    Step newStep = doNextStep(curentStep);

    if( false == newStep.getIsStepFailed() )
    {
        member.setNewStep(newStep);
    }

    if( member.countOfSteps() <= 1 )
    {
        isHorseHaveSteps = false;
    }

    return isHorseHaveSteps;
}

void Horse::addCoordinateToFailedStep(const std::pair<int, int>& nextStep)
{
    if( false == member.getLastStep().isNextStepAlreadyInFailed(nextStep) )
    {
        Step FailedStep(nextStep, true);
        member.getLastStep().addNewFailedNextStep(FailedStep);
    }
}

void Horse::checkCurrent(const std::pair<int, int>& nextStep, Step& step, bool& isFindNextStep)
{
    if( false == isFieldAlreadyVisited(nextStep))
    {
        isFindNextStep = true;
        step.setCoord(nextStep);
    }
    else
    {
        addCoordinateToFailedStep(nextStep);
    }
}

Step Horse::doNextStep(const std::pair<int, int>& nextStep_)
{
    //TODO make it easier
    Step step(nextStep_.first, nextStep_.second);

    bool isAllStepsArroundFailed = false;
    bool isFindNextStep = false;

    for(; false == isAllStepsArroundFailed && false == isFindNextStep ; switchCurentStepVariant())
    {
        std::pair<int, int> nextStep( step.getCoord() );

        switch (curentVariant)
        {
        case VariantsOfSteps::TopRight:
            nextStep.first = curentStep.first + 1;
            nextStep.second = curentStep.second + 2;

            break;

        case VariantsOfSteps::RightTop:
            nextStep.first = curentStep.first +2;
            nextStep.second = curentStep.second + 1;

            break;

        case VariantsOfSteps::RightBottom:
            nextStep.first = curentStep.first +2;
            nextStep.second = curentStep.second - 1;

            break;

        case VariantsOfSteps::BottomRight:
            nextStep.first = curentStep.first + 1;
            nextStep.second = curentStep.second - 2;

            break;

        case VariantsOfSteps::BottomLeft:
            nextStep.first = curentStep.first - 1;
            nextStep.second = curentStep.second - 2;

            break;

        case VariantsOfSteps::LeftBottom:
            nextStep.first = curentStep.first - 2;
            nextStep.second = curentStep.second - 1;

            break;

        case VariantsOfSteps::LeftTop:
            nextStep.first = curentStep.first - 2;
            nextStep.second = curentStep.second + 1;

            break;

        case VariantsOfSteps::TopLeft:
            nextStep.first = curentStep.first -1;
            nextStep.second = curentStep.second + 2;

            break;

        case VariantsOfSteps::StepIsFailed:
            isAllStepsArroundFailed =  true;
            break;

        default:
            break;
        }

        if( false == isAllStepsArroundFailed)
        {
            checkCurrent(nextStep, step, isFindNextStep);
        }
        else
        {
            member.lastStepIsFailed();
            step.setIsStepFailed(true);
        }
    }

    return step;
}

bool Horse::isFieldAlreadyVisited(const std::pair<int, int>& nextStep )
{
    if( true == board.isFieldAlreadyVisited(nextStep) ) return true;
    if( true == member.getLastStep().isNextStepAlreadyInFailed(nextStep)) return true;

    return false;
}

void Horse::switchCurentStepVariant()
{
    switch (curentVariant)
    {
    case VariantsOfSteps::TopRight:
        curentVariant = VariantsOfSteps::RightTop;

        break;

    case VariantsOfSteps::RightTop:
        curentVariant = VariantsOfSteps::RightBottom;

        break;

    case VariantsOfSteps::RightBottom:
        curentVariant = VariantsOfSteps::BottomRight;

        break;

    case VariantsOfSteps::BottomRight:
        curentVariant = VariantsOfSteps::BottomLeft;

        break;

    case VariantsOfSteps::BottomLeft:
        curentVariant = VariantsOfSteps::LeftBottom;

        break;

    case VariantsOfSteps::LeftBottom:
        curentVariant = VariantsOfSteps::LeftTop;

        break;

    case VariantsOfSteps::LeftTop:
        curentVariant = VariantsOfSteps::TopLeft;

        break;

    case VariantsOfSteps::TopLeft:
        curentVariant = VariantsOfSteps::StepIsFailed;

        break;

    default:
        curentVariant = VariantsOfSteps::TopRight;
        break;
    }
}
