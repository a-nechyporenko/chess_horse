#ifndef MEMBER_HPP
#define MEMBER_HPP

#include <list>
#include <utility>

#include "Step.hpp"
#include "Board.hpp"

class Member
{
public:
    explicit Member (Board& board_);

    bool isPositionAlreadyCalculated( const std::pair<int, int> position );
    std::vector<std::pair<int, int> > &&getSuccessfulSteps();

    void setNewStep (const Step step);
    Step &getLastStep();
    void lastStepIsFailed();

    int countOfSteps();

private:
    std::list<Step> steps;
    Board& board;
};

#endif // MEMBER_HPP
