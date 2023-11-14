#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

const std::string red("\033[0;31m");
const std::string redbg("\033[0;41m");
const std::string green("\033[1;32m");
const std::string greenbg("\033[1;42m");
const std::string yellow("\033[1;33m");
const std::string yellowbg("\033[1;43m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string magentabg("\033[0;45m");
const std::string reset("\033[0m");

class PmergeMe
{
	public:
                PmergeMe(int ac, char **av);
                ~PmergeMe();
                PmergeMe(const PmergeMe &rhs);
                PmergeMe &operator=(const PmergeMe &rhs);
                template <typename T>
                void display(const T& container);
                std::deque<int> sortDeque(std::deque<int>& arr);
                std::vector<int>    sortVector(std::vector<int>& arr);
                std::deque<std::pair<int, int> > makePair(const std::deque<int>& original);
                void    separatePairs(const std::deque<std::pair<int, int> >& pairedDeque, std::deque<int>& mainList, std::deque<int>& pendingList);
                void    insertSmallestToFront(std::list<int>& mainList, std::list<int>& pendingList);
                void    insertWithBinarySearch(std::deque<int>& mainDeque, const int element);
                void    insertAllWithBinarySearch(std::deque<int>& mainDeque, std::deque<int>& pendingDeque);
                bool    isSorted(const std::deque<int>& myDeque);
                std::vector<std::pair<int, int> >    makePairVector(const std::vector<int>& original);
                void    separatePairsVector(const std::vector<std::pair<int, int> >& pairedVector, std::vector<int>& mainList, std::vector<int>& pendingList);
                void    insertionSortPairsVector(std::vector<std::pair<int, int> >& pairedVector);
                void    insertAllWithBinarySearchVector(std::vector<int>& mainVector, std::vector<int>& pendingVector) ;
                void    insertWithBinarySearchVector(std::vector<int>& mainVector, const int element) ;
                void    mergeInsertSortDeque(std::deque<int>& arr);
                void    mergeInsertSortList(std::list<int>& arr);
                void    insertionSortPairs(std::deque<std::pair<int, int> >& pairedDeque);
                void    displayPair(std::deque<std::pair<int, int> >& pairedDeque);
};

#endif
