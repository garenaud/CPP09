#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

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
        void mergeInsertSortDeque(std::deque<int>& arr);
        void mergeInsertSortList(std::list<int>& arr);
};

#endif
