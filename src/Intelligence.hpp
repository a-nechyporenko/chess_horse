#ifndef INTELLIGENCE_HPP
#define INTELLIGENCE_HPP

#include <utility>
#include <vector>

#include "Member.hpp"
#include "Board.hpp"
#include "Horse.hpp"



class Intelligence
{
    typedef std::vector<std::pair<int, int>> VetorStepsCoordinates;

public:
    Intelligence();
    ~Intelligence() = default;

    bool setStartPosition(int x, int y);
    void showSteps();
    void drawBoard();
private:
    void drawResultSteps( const VetorStepsCoordinates& resultSteps);
    const VetorStepsCoordinates& findResultSteps();

private:
    Board board;
    Member member;
    Horse horse;
    std::pair<int, int> startPosition;

};

#endif // INTELLIGENCE_HPP
