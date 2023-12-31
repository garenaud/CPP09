#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) 
{
    if (argc < 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    try 
    {
        Btc btc("data.csv");
        btc.readInput(argv[1]);
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << std::endl;
    system("leaks Btc");
    return 0;
}
