#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cstdlib>

RPN::RPN() 
{}

RPN::~RPN()
{}

RPN::RPN(const RPN &rhs)
{
    *this = rhs;
}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
        _stack = rhs._stack;
    }
    return *this;
}

bool RPN::isOperator(const char& c) const 
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::applyOperator(const char& op) 
{
    if (_stack.size() < 2) throw std::runtime_error("Insufficient values in expression");

    double val2 = _stack.top();
    _stack.pop();
    double val1 = _stack.top();
    _stack.pop();

    switch (op) 
    {
        case '+': _stack.push(val1 + val2); break;
        case '-': _stack.push(val1 - val2); break;
        case '*': _stack.push(val1 * val2); break;
        case '/':
            if (val2 == 0) throw std::runtime_error("Division by zero");
            _stack.push(val1 / val2);
            break;
        default: throw std::runtime_error("Unknown operator");
    }
}

double RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) 
    {
        if (isOperator(token[0]) && token.length() == 1) 
        {
            applyOperator(token[0]);
        } else 
        {
            _stack.push(atof(token.c_str()));
        }
    }

    if (_stack.size() != 1) throw std::runtime_error("Invalid expression");

    return _stack.top();
}
