#ifndef HORSE_HPP
#define HORSE_HPP

#include "Member.hpp"
#include "Board.hpp"

enum class VariantsOfSteps
{
    BotomLeft, BotomRight,
    LeftBotom, LeftTop,
    TopLeft, TopRight,
    RightTop, RightBotom,
    StepIsFaild
};

class Horse
{
public:
    Horse(Member& member_, Board& board_);

    bool moveHorse();

private:
    Step doNextStep(const std::pair<int, int>& nextStep_);

    void switchCurentStepVariant();
    void addCoordinateToFaildStep(const std::pair<int, int> &nextStep);
    bool isFildAlreadyVisited(const std::pair<int, int>& nextStep );
    void checkCurrent(std::pair<int, int> &&nextStep, Step &step, bool isFindNextStep);

private:
    Member& member;
    Board& board;

    std::pair<int, int> curentStep;
    VariantsOfSteps curentVariant;


};

#endif // HORSE_HPP
