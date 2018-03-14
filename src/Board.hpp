#ifndef BOARD_HPP
#define BOARD_HPP

#include "Field.hpp"
#include <vector>
#include <utility>

namespace nBoard
{
    const int BOARD_SIZE = 5;
    const int MAX_STEPS = 8;
}
class Board
{
    public:
        Board();
        ~Board();

        const Field &getField( const int x, const int y) const;

        bool isFildAlreadyVisited(const std::pair<int, int>& stepCoordinate);
        bool isAllFieldsIsVisited();

        void drawBoard();
        void drawBoardWithStep (const std::pair<int, int>& stepCoordinate);
        void drawBoardWithoutFaildStep( const std::pair<int, int>& faildStepCoordinate );

    private:
        void initFields();
        bool isCoordValid(const std::pair<int, int> &stepCoordinate);
    private:
        typedef std::vector<std::vector<Field>> Fields;
        Fields fields;

};

#endif // BOARD_HPP
