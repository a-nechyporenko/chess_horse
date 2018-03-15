#ifndef HORSE_HPP
#define HORSE_HPP

#include "Member.hpp"
#include "Board.hpp"

enum class VariantsOfSteps
{
    BottomLeft = 0,
    BottomRight,
    LeftBottom,
    LeftTop,
    TopLeft,
    TopRight,
    RightTop,
    RightBottom,
    StepIsFailed
};

class Horse
{
public:
    Horse(Member& member_, Board& board_);

    bool moveHorse();

private:
    Step doNextStep(const std::pair<int, int>& nextStep_);

    void switchCurentStepVariant();
    void addCoordinateToFailedStep(const std::pair<int, int> &nextStep);
    bool isFieldAlreadyVisited(const std::pair<int, int>& nextStep );
    void checkCurrent(const std::pair<int, int>& nextStep, Step &step, bool& isFindNextStep);

private:
    Member& member;
    Board& board;

    std::pair<int, int> curentStep;
    VariantsOfSteps curentVariant;


};

#endif // HORSE_HPP
