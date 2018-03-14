#include "Board.hpp"

Board::Board()
{
    initFields();
}

void Board::initFields()
{
    for( int i = 0; i < Chess::Board::BOARD_SIZE; ++i )
    {
        std::vector<Field> lien;
        fields.push_back(lien);

        for(int j = 0; j < Chess::Board::BOARD_SIZE; ++j)
        {
            Field field;
            fields.back().push_back(field);
        }
    }
}

bool Board::isCoordValid(const std::pair<int, int> &stepCoordinate)
{
    bool isValid = true;

    if(stepCoordinate.first >= Chess::Board::BOARD_SIZE) { isValid = false;}
    if(stepCoordinate.second >= Chess::Board::BOARD_SIZE){ isValid = false;}
    if(stepCoordinate.first <  0) { isValid = false;}
    if(stepCoordinate.second < 0) { isValid = false;}

    return isValid;
}

const Field& Board::getField( const int x, const int y) const
{
    return fields.at(x).at(y);
}

bool Board::isFildAlreadyVisited(const std::pair<int, int> &stepCoordinate)
{
    bool isAlreadyVisited = false;

    if( true == isCoordValid(stepCoordinate) )
    {
        isAlreadyVisited = fields.at(stepCoordinate.first).at(stepCoordinate.second).getIsVisited();
    }
    else
    {
        isAlreadyVisited = true;
    }

    return isAlreadyVisited;
}

bool Board::isAllFieldsIsVisited()
{
    bool isAllFieldsIsVisited = true;

    for(int x = 0; x < Chess::Board::BOARD_SIZE; ++x)
    {
        for(int y = 0; y < Chess::Board::BOARD_SIZE; ++y)
        {
            if( false == fields.at(x).at(y).getIsVisited())
            {
                isAllFieldsIsVisited = false;

                return isAllFieldsIsVisited;
            }
        }
    }

    return isAllFieldsIsVisited;
}


void Board::drawBoardWithStep(const std::pair<int, int>& stepCoordinate)
{
    fields.at(stepCoordinate.first).at(stepCoordinate.second).setIsVisited(true);

    drawBoard();
}

void Board::drawBoardWithoutFaildStep(const std::pair<int, int>& faildStepCoordinate)
{
    fields.at(faildStepCoordinate.first).at(faildStepCoordinate.second).setIsVisited(false);

    drawBoard();
}

void Board::drawBoard()
{
    system("clear");

    for( auto verticalLien = fields.begin(); verticalLien != fields.end(); ++verticalLien)
    {
        for(auto field = verticalLien->begin(); field != verticalLien->end(); ++field )
        {
            field->draw();
        }

        std::cout << "\n";
    }
}
