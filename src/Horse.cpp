
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

    if( false == newStep.getIsStepFaild() )
    {
        member.setNewStep(newStep);
    }

    if( member.countOfSteps() <= 1 )
    {
        isHorseHaveSteps = false;
    }

    return isHorseHaveSteps;
}

void Horse::addCoordinateToFaildStep(const std::pair<int, int>& nextStep)
{
    if( false == member.getLastStep().isNextStepAlreadyInFaild(nextStep) )
    {
        Step faildStep(nextStep, true);
        member.getLastStep().addNewFaildNextStep(faildStep);
    }
}

Step Horse::doNextStep(const std::pair<int, int>& nextStep_)
{
    //TODO make it easier
    Step step(nextStep_.first, nextStep_.second);

    bool isAllStepsArroundFaild = false;
    bool isFindNextStep = false;

    for(; false == isAllStepsArroundFaild && false == isFindNextStep ; switchCurentStepVariant())
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

        case VariantsOfSteps::RightBotom:
            nextStep.first = curentStep.first +2;
            nextStep.second = curentStep.second - 1;

            break;

        case VariantsOfSteps::BotomRight:
            nextStep.first = curentStep.first + 1;
            nextStep.second = curentStep.second - 2;

            break;

        case VariantsOfSteps::BotomLeft:
            nextStep.first = curentStep.first - 1;
            nextStep.second = curentStep.second - 2;

            break;

        case VariantsOfSteps::LeftBotom:
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

        case VariantsOfSteps::StepIsFaild:
            isAllStepsArroundFaild =  true;
            break;

        default:
            break;
        }

        if( false == isAllStepsArroundFaild)
        {
            checkCurrent(std::move(nextStep), step, isFindNextStep);
        }
        else
        {
            member.lastStepIsFaild();
            step.setIsStepFaild(true);
        }
    }

    return step;
}

void Horse::checkCurrent(std::pair<int, int>&& nextStep, Step& step, bool isFindNextStep)
{
    if( false == isFildAlreadyVisited(nextStep))
    {
        isFindNextStep = true;
        step.setCoord(nextStep);
    }
    else
    {
        addCoordinateToFaildStep(nextStep);
    }
}

bool Horse::isFildAlreadyVisited(const std::pair<int, int>& nextStep )
{
    if( true == board.isFildAlreadyVisited(nextStep) ) return true;
    if( true == member.getLastStep().isNextStepAlreadyInFaild(nextStep)) return true;

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
        curentVariant = VariantsOfSteps::RightBotom;

        break;

    case VariantsOfSteps::RightBotom:
        curentVariant = VariantsOfSteps::BotomRight;

        break;

    case VariantsOfSteps::BotomRight:
        curentVariant = VariantsOfSteps::BotomLeft;

        break;

    case VariantsOfSteps::BotomLeft:
        curentVariant = VariantsOfSteps::LeftBotom;

        break;

    case VariantsOfSteps::LeftBotom:
        curentVariant = VariantsOfSteps::LeftTop;

        break;

    case VariantsOfSteps::LeftTop:
        curentVariant = VariantsOfSteps::TopLeft;

        break;

    case VariantsOfSteps::TopLeft:
        curentVariant = VariantsOfSteps::StepIsFaild;

        break;

    default:
        curentVariant = VariantsOfSteps::TopRight;
        break;
    }
}
