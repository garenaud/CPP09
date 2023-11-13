#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

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
