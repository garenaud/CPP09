#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

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
