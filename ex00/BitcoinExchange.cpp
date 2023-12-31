#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cfloat>

Btc::Btc(const std::string& exchangeRateFile) 
{
    std::ifstream file(exchangeRateFile.c_str());
    if (!file.is_open()) 
    {
        throw std::runtime_error("Cannot open exchange rate file");
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) 
    {
        std::istringstream iss(line);
        std::string date;
        double rate;
        std::getline(iss, date, ',');
        iss >> rate;
        rates[date] = rate;
    }
}

Btc::~Btc()
{

}

Btc::Btc(const Btc &rhs)
{
    *this = rhs;
}

Btc &Btc::operator=(const Btc &rhs)
{
    if (this != &rhs)
    {
        rates = rhs.rates;
    }
    return *this;
}

bool Btc::isValidDate(const std::string& date) {
    if (date.length() != 11) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    int year, month, day;
    try 
    {
        year = std::atoi(date.substr(0, 4).c_str());
        month = std::atoi(date.substr(5, 2).c_str());
        day = std::atoi(date.substr(8, 2).c_str());
    } catch (...) 
    {
        return false;
    }
    if (year < 1900 || year > 2100) 
        return false;
    if (month < 1 || month > 12) 
        return false;
    if (day < 1 || day > 31) 
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
        return false;
    if (month == 2) 
    {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 29 || (day > 28 && !isLeapYear)) return false;
    }

    return true;
}

void Btc::readInput(const std::string& filename) 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) 
    {
        throw std::runtime_error("⚠️ Cannot open input file ⚠️");
    }
    std::string line;
    if (!std::getline(file, line)) 
    {
        throw std::runtime_error("⚠️ Input file is empty or not readable ⚠️");
    }
    //std::getline(file, line);
    while (std::getline(file, line)) 
    {
        std::istringstream iss(line);
        std::string date;
        double amount = 0;
        std::getline(iss, date, '|');
        iss >> amount;
        std::map<std::string, double>::iterator rateIt = rates.lower_bound(date);
        if (!isValidDate(date))
        {
            std::cout << red << "⚠️ Error: bad input => " << redbg << date << reset << std::endl;
            continue;
        }
        if (amount == 0)
        {
            std::cout << red << "⚠️ Error: amount missing => " << redbg << date << reset << std::endl;
            continue;
        }
        if (amount < 0)
        {
            std::cout << red << "⚠️ Error: not a positive number." << reset << std::endl;
            continue;
        }
        if (amount > 1000.0)
        {
            std::cout << red << "⚠️ Error: too large number." << reset << std::endl;
            continue;
        }
        if (rateIt != rates.begin() && (rateIt == rates.end() || rateIt->first != date)) 
        {
            --rateIt;
        }
        double rate = rateIt->second;
        double value = amount * rate;
        std::cout << green << std::left << std::setw(12) << date << " => "
          << std::right << std::setw(6) << std::fixed << std::setprecision(2) << amount 
          << " = " << greenbg << value << reset << std::endl;    }
}
