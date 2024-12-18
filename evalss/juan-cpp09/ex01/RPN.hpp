#pragma once
#include "stack"

#include<iostream>

class RPN {
private:
  std::stack<int> polish;

public:
  RPN();
  RPN(const RPN &_src);
  ~RPN();
  RPN &operator=(const RPN &_src);

  // ___________ search operation.
  int checkOperation(const int &op1, const int &op2, const char &operation);

  // ___________ Handle input.
  void stackTokenCreation(const std::string &_str);

  // _________ get resutl
    int getResult();
  
};
