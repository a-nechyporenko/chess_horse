#ifndef BOARD_HPP
#define BOARD_HPP

#include "NChessDefinitions.hpp"
#include "Field.hpp"
#include <vector>
#include <utility>
#include <iostream>

class Board
{
public:
    Board();
    ~Board() = default;

    const Field& getField( const int x, const int y ) const;

    bool isFieldAlreadyVisited(const std::pair<int, int> &stepCoordinate);
    bool isAllFieldsIsVisited();

    void drawBoard();
    void drawBoardWithStep (const std::pair<int, int> &stepCoordinate);
    void drawBoardWithoutFailedStep( const std::pair<int, int>& FailedStepCoordinate );

private:
    void initFields();
    bool isCoordValid(const std::pair<int, int> &stepCoordinate);
private:
    typedef std::vector<std::vector<Field>> Fields;
    Fields fields;

};

#endif // BOARD_HPP
