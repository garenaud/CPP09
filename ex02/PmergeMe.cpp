#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av){

    std::deque<int> inputDeque;
    std::vector<int> inputVector;

    // fill the containers with random integers
    srand(time(NULL));
    for (int i = 1; i < ac; ++i)
    {
        int value = atoi(av[i]);
        if (value <= 0)
        {
            std::cerr << "Error: Invalid input value \"" << av[i] << "\". Only positive integers are allowed." << std::endl;
			exit(1);
        }
        inputDeque.push_back(value);
        inputVector.push_back(value);
    }
    std::cout << yellowbg << "Before: " << reset;
    display(inputDeque);
/*     std::cout << redbg << "mainList = " << reset;
    display(mainList);
    std::cout << std::endl << magentabg << "pendList = " << reset;
    display(pendList);
    insertAllWithBinarySearch(mainList, pendList);
    std::cout << greenbg << "mainList fini = " << reset;
    display(mainList);
    while (!isSorted(mainList))
    {
        pairedDeque = makePair(inputDeque);
        separatePairs(pairedDeque, mainList, pendList);
        insertAllWithBinarySearch(mainList, pendList);
    } */
    clock_t start1 = clock();
    //mergeInsertSortDeque(inputDeque);
    inputDeque = sortDeque(inputDeque);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    clock_t start2 = clock();
    //mergeInsertSortList(inputList);
    inputVector = sortVector(inputVector);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

    std::cout << greenbg << "After: " << reset;
    display(inputDeque);
    std::cout << magentabg << "After: " << reset;
    display(inputVector);
    std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << inputVector.size() << " elements with std::vector container: " << time2 << " us" << std::endl;
    if (inputDeque == std::deque<int>(inputVector.begin(), inputVector.end()))
        std::cout << "The sorted sequences are equal." << std::endl;
    else
        std::cout << "The sorted sequences are not equal." << std::endl;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe    &PmergeMe::operator=(const PmergeMe &rhs)
{
    (void) rhs;
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
    *this = rhs;
}

template <typename T>
void PmergeMe::display(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::displayPair(std::deque<std::pair<int, int> >& pairedDeque) 
{
    for (std::deque<std::pair<int, int> >::const_iterator it = pairedDeque.begin(); it != pairedDeque.end(); ++it) 
    {
        // Afficher chaque paire
        std::cout << green << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << reset << std::endl;
}

std::deque<int>    PmergeMe::sortDeque(std::deque<int>& arr)
{
    std::deque<std::pair<int, int> > pairedDeque;
    std::deque<int> mainList;
    std::deque<int> pendList;
    pairedDeque = makePair(arr);
    separatePairs(pairedDeque, mainList, pendList);
    insertAllWithBinarySearch(mainList, pendList);
    if (!mainList.empty() && mainList.front() == -1) 
    {
        mainList.erase(mainList.begin());
    }
    return mainList;
}

std::vector<int>    PmergeMe::sortVector(std::vector<int>& arr)
{
    std::vector<std::pair<int, int> > pairedVector;
    std::vector<int> mainList;
    std::vector<int> pendList;
    pairedVector = makePairVector(arr);
    separatePairsVector(pairedVector, mainList, pendList);
    insertAllWithBinarySearchVector(mainList, pendList);
    if (!mainList.empty() && mainList.front() == -1) 
    {
        mainList.erase(mainList.begin());
    }
    return mainList;
}

std::deque<std::pair<int, int> >    PmergeMe::makePair(const std::deque<int>& original)
{
    std::deque<std::pair<int, int> > pairedDeque;

    for (size_t i = 0; i < original.size(); i += 2) 
    {
        if (i + 1 < original.size()) 
        {
            int first = original[i];
            int second = original[i + 1];
            if (first < second)
                std::swap(first, second);
            pairedDeque.push_back(std::make_pair(first, second));
        } 
        else 
        {
            pairedDeque.push_back(std::make_pair(original[i], -1));
        }
    }
    insertionSortPairs(pairedDeque);
    return pairedDeque;
}

std::vector<std::pair<int, int> >    PmergeMe::makePairVector(const std::vector<int>& original)
{
    std::vector<std::pair<int, int> > pairedVector;

    for (size_t i = 0; i < original.size(); i += 2) 
    {
        if (i + 1 < original.size()) 
        {
            int first = original[i];
            int second = original[i + 1];
            if (first < second)
                std::swap(first, second);
            pairedVector.push_back(std::make_pair(first, second));
        } 
        else 
        {
            pairedVector.push_back(std::make_pair(original[i], -1));
        }
    }
    insertionSortPairsVector(pairedVector);
    return pairedVector;
}
/* 
void PmergeMe::insertionSortPairs(std::deque<std::pair<int, int> >& pairedDeque) 
{
    for (size_t i = 1; i > pairedDeque.size(); ++i) 
    {
        std::pair<int, int> key = pairedDeque[i];
        size_t j = i;
        while (j > 0 && pairedDeque[j - 1].first > key.first) 
        {
            pairedDeque[j] = pairedDeque[j - 1];
            --j;
        }
        pairedDeque[j] = key;
    }
    std::cout << "depuis la fonction = ";
    displayPair(pairedDeque);
} */

void PmergeMe::insertionSortPairs(std::deque<std::pair<int, int> >& pairedDeque) 
{
    for (size_t i = 1; i < pairedDeque.size(); ++i) 
    {
        std::pair<int, int> key = pairedDeque[i];
        size_t j = i;
        while (j > 0 && pairedDeque[j - 1].first > key.first) 
        {
            pairedDeque[j] = pairedDeque[j - 1];
            --j;
        }
        pairedDeque[j] = key;
    }
}

void PmergeMe::insertionSortPairsVector(std::vector<std::pair<int, int> >& pairedVector) 
{
    for (size_t i = 1; i < pairedVector.size(); ++i) 
    {
        std::pair<int, int> key = pairedVector[i];
        size_t j = i;
        while (j > 0 && pairedVector[j - 1].first > key.first) 
        {
            pairedVector[j] = pairedVector[j - 1];
            --j;
        }
        pairedVector[j] = key;
    }
}


void PmergeMe::separatePairs(const std::deque<std::pair<int, int> >& pairedDeque, std::deque<int>& mainList, std::deque<int>& pendingList) 
{
    std::deque<std::pair<int, int> > pairedDeque1 = pairedDeque;
    for (std::deque<std::pair<int, int> >::const_iterator it = pairedDeque.begin(); it != pairedDeque.end(); ++it) {
        mainList.push_back(it->first);    // Plus grand numéro
        pendingList.push_back(it->second); // Plus petit numéro
    }
    //displayPair(pairedDeque1);
    //display(mainList);
    //display(pendingList);
    //std::sort(mainList.begin(), mainList.end());

    // Assurez-vous de retirer tous les marqueurs (par exemple, -1 pour les éléments impairs)
    //pendingList.remove(-1);
}

void PmergeMe::separatePairsVector(const std::vector<std::pair<int, int> >& pairedVector, std::vector<int>& mainList, std::vector<int>& pendingList) 
{
    for (std::vector<std::pair<int, int> >::const_iterator it = pairedVector.begin(); it != pairedVector.end(); ++it) 
    {
        mainList.push_back(it->first);    // Plus grand numéro
        pendingList.push_back(it->second); // Plus petit numéro
    }
    display(mainList);
    //std::sort(mainList.begin(), mainList.end());

    // Assurez-vous de retirer tous les marqueurs (par exemple, -1 pour les éléments impairs)
    //pendingList.remove(-1);
}

void PmergeMe::insertWithBinarySearch(std::deque<int>& mainDeque, const int element) 
{
    // La fonction std::lower_bound trouve la position où l'élément devrait être inséré
    std::deque<int>::iterator it = std::lower_bound(mainDeque.begin(), mainDeque.end(), element);

    // Insérer l'élément à la position trouvée
    mainDeque.insert(it, element);
}

void PmergeMe::insertWithBinarySearchVector(std::vector<int>& mainVector, const int element) 
{
    // La fonction std::lower_bound trouve la position où l'élément devrait être inséré
    std::vector<int>::iterator it = std::lower_bound(mainVector.begin(), mainVector.end(), element);

    // Insérer l'élément à la position trouvée
    mainVector.insert(it, element);
}

void PmergeMe::insertAllWithBinarySearch(std::deque<int>& mainDeque, std::deque<int>& pendingDeque) 
{
    for (std::deque<int>::iterator it = pendingDeque.begin(); it != pendingDeque.end(); ++it) 
    {
        insertWithBinarySearch(mainDeque, *it);
    }
}

void PmergeMe::insertAllWithBinarySearchVector(std::vector<int>& mainVector, std::vector<int>& pendingVector) 
{
    for (std::vector<int>::iterator it = pendingVector.begin(); it != pendingVector.end(); ++it) 
    {
        insertWithBinarySearchVector(mainVector, *it);
    }
}



void PmergeMe::insertSmallestToFront(std::list<int>& mainList, std::list<int>& pendingList) 
{
    if (!pendingList.empty()) 
    {
        mainList.push_front(*std::min_element(pendingList.begin(), pendingList.end()));
        pendingList.remove(mainList.front());
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
    std::deque<int>::iterator it1, it2;
    for (it1 = arr.begin() + 1; it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin() && *(std::prev(it2)) > temp)
        {
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}

bool PmergeMe::isSorted(const std::deque<int>& myDeque) 
{
    if (myDeque.empty()) {
        return true;  // Un deque vide est considéré comme trié
    }

    std::deque<int>::const_iterator it = myDeque.begin();
    int prev = *it;
    ++it;

    while (it != myDeque.end()) {
        if (prev > *it) {
            return false;  // Le deque n'est pas trié
        }
        prev = *it;
        ++it;
    }

    return true;  // Tous les éléments sont dans l'ordre croissant
}


void PmergeMe::mergeInsertSortList(std::list<int>& arr)
{
    std::list<int>::iterator it1, it2;
    for (it1 = ++arr.begin(); it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin() && *(std::prev(it2)) > temp)
        {
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}
