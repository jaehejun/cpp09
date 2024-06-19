#include "./PmergeMe.hpp"

int main(int ac, char** av)
{
    try {

        PmergeMe    fordJohnson(ac, av);

        fordJohnson.runFordJohnson();

        std::cout << std::endl;
        fordJohnson.printContainer(fordJohnson.getVec(), "use vector");
        fordJohnson.printIsSorted(fordJohnson.getVec());
        std::cout << std::endl;
        fordJohnson.printContainer(fordJohnson.getDq(), "use deque");
        fordJohnson.printIsSorted(fordJohnson.getDq());

    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}