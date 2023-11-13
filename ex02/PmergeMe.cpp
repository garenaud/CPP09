#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>

template <typename T>
void PmergeMe::mergeInsertSort(T& container) 
{

}

template <typename T>
void PmergeMe::displayResult(const T& container, const std::string& containerName) 
{
    auto start = std::chrono::high_resolution_clock::now();
    mergeInsertSort(container);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed = end - start;

    for (auto& elem : container) 
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process with " << containerName << ": " << elapsed.count() << " us" << std::endl;
}

void PmergeMe::sortAndDisplay(const std::vector<int>& numbers) 
{
    std::vector<int> nums = numbers;
    displayResult(nums, "std::vector");
}

void PmergeMe::sortAndDisplay(const std::list<int>& numbers) 
{
    std::list<int> nums = numbers;
    displayResult(nums, "std::list");
}
