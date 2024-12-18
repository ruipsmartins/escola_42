#include "RPN.hpp"
#include <cstdlib>
#include <sstream>
#include <stdexcept>

//______________ Constructors
RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &_src) { *this = _src; }

//______________ Overload Operator

RPN &RPN::operator=(const RPN &_src) {
  if (this != &_src)
    *this = _src;
  return *this;
}

int RPN::checkOperation(const int &op1, const int &op2, const char &operation) {
  switch (operation) {
  case '+':
    return (op1 + op2);
  case '-':
    return (op1 - op2);
  case '*':
    return (op1 * op2);
  case '/':
    if (op2 == 0)
      throw(std::runtime_error(
          " 📐e = ∑∞ⁿ⁼⁰ ¹ₙ🤓 Invalid Division by /0 not valid 🧮"));
    return (op1 / op2);
  default:
    throw(std::runtime_error(" ❌ ❌Invalid Math expression 🤔"));
  }
}

void RPN::stackTokenCreation(const std::string &_str) {
  {
    std::istringstream tokens(_str);
    std::string token;

    while (tokens >> token) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        if (polish.size() < 2)
          throw(std::runtime_error("Error Invalid Expression "));
        int op2 = polish.top();
        polish.pop();
        int op1 = polish.top();
        polish.pop();
        // Perfom operation.
        int result = checkOperation(op1, op2, token[0]);
        polish.push(result);
      } else {
        // check if is numb.
        char *end;
        int num = std::strtol(token.c_str(), &end, 10);
        if (*end != '\0')
          throw(
              std::runtime_error(" 📐e = ∑∞ⁿ⁼⁰ ¹ₙ Error not valid ❌"));
        std::cout << "_________ ADD NUMBER  " << num << std::endl;
        polish.push(num);
      }
    }
    if (polish.size() != 1)
      throw std::runtime_error("Error: Invalid expression");
  }
}
int RPN::getResult() {
  if (polish.empty())
    throw(std::runtime_error("Not result available"));
  return polish.top();
}