#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

int main(int argc, char* argv[]) {
    PmergeMe sorter;
    std::vector<int> numbersVector;
    std::list<int> numbersList;

    for (int i = 1; i < argc; ++i) 
    {
        int num = std::atoi(argv[i]);
        if (num <= 0) 
        {
            std::cerr << "Error: All numbers must be positive integers." << std::endl;
            return 1;
        }
        numbersVector.push_back(num);
        numbersList.push_back(num);
    }

    std::cout << "Before: ";
    for (int num : numbersVector) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sorter.sortAndDisplay(numbersVector);
    sorter.sortAndDisplay(numbersList);

    return 0;
}
