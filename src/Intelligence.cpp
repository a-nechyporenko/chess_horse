#include "Intelligence.hpp"
#include<iostream>

Intelligence::Intelligence()
    : board()
    , member(board)
    , horse(member, board)
    , startPosition()
{

}

Intelligence::~Intelligence()
{

}

bool Intelligence::setStartPosition(int x, int y)
{
    bool isSuccessStartPosition = false;

    if(
            nBoard::BOARD_SIZE >= x
            &&
            nBoard::BOARD_SIZE >= y
            )
    {
        startPosition.first = x;
        startPosition.second = y;

        member.setNewStep(Step(startPosition,false));

        isSuccessStartPosition =true;
    }
    else
    {
        isSuccessStartPosition = false;
    }

    return isSuccessStartPosition;
}

void Intelligence::showSteps()
{
    if( true == member.isPositionAlreadyCalculated(startPosition))
    {
        std::vector<std::pair<int, int>> steps = member.getSuccessfulSteps();

        drawResultSteps(steps);

    }
    else
    {
        drawResultSteps(findResultSteps());
    }
}

void Intelligence::drawBoard()
{
    board.drawBoard();
}

void Intelligence::drawResultSteps(const VetorStepsCoordinates &resultSteps)
{
    for(auto pos : resultSteps)
    {
        board.drawBoardWithStep(pos);
    }
}

const Intelligence::VetorStepsCoordinates &Intelligence::findResultSteps()
{
    while( false == board.isAllFieldsIsVisited() )
    {
        if( false == horse.moveHorse() )
        {
            break;
            std::cout<< " Can`t found right steps ( \n";
        }
    }

    std::cout<< " I found right way! Could I show you? \n";
    system("pause");

    return member.getSuccessfulSteps();
}

