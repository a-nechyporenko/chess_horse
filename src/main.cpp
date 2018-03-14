#include <iostream>
#include <Intelligence.hpp>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Intelligence intel;

    intel.drawBoard();

    do{
//        std::cout << "Enter X position : ";
//        std::cin >> x;
//        std::cout << "\n ";

//        std::cout << "Enter Y position : ";
//        std::cin >> y;
//        std::cout << "\n ";

    }while ( false == intel.setStartPosition(2,2) );

    intel.showSteps();
    system("pause");
    return 0;
}
