#include "PmergeMe.hpp"

int main(int ac, char* av[])
{
	if (ac <= 1)
    {
        std::cerr << "Error: No input sequence provided." << std::endl;
        return 1;
    }
	PmergeMe pmergeMe(ac, av);
	(void)pmergeMe;
    system("leaks PmergeMe");
    return 0;
}
