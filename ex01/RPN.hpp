#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
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

class RPN {
public:
    RPN();
    ~RPN();
    RPN &operator=(const RPN &rhs);
    RPN(const RPN &rhs);
    double calculate(const std::string& expression);

private:
    std::stack<double> _stack;
    bool isOperator(const char& c) const;
    void applyOperator(const char& op);
};

#endif // RPN_HPP
