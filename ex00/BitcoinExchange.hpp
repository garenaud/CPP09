#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class Btc {
private:
    std::map<std::string, double> rates;
    bool isValidDate(const std::string &date);
public:
    Btc(const std::string& exchangeRateFile);
    ~Btc();
    Btc(const Btc &rhs);
    Btc &operator=(const Btc &rhs);
    void readInput(const std::string& filename);
};

#endif