#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>

class PmergeMe 
{
public:
    void sortAndDisplay(const std::vector<int>& numbers);
    void sortAndDisplay(const std::list<int>& numbers);


private:
    template <typename T>
    void mergeInsertSort(T& container);
    template <typename T>
    void displayResult(const T& container, const std::string& containerName);
};

#endif
