#pragma once

#include <algorithm>
#include <ctime>
#include <iostream>
#include <list>
#include <vector>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class PmergeMe {

public:
  PmergeMe();
  PmergeMe(const PmergeMe &_src);
  PmergeMe &operator=(const PmergeMe &_src);
  ~PmergeMe();

  // ______________________ Check the input.
  void inputCheck(const std::string &val);
  void initialPairingList();
  void initialPairingVector();
  void mergeSortVector(int left, int right);
  void mergeSortList(std::list<int> &lst);
  void mergeVector(int left, int mid, int right);

  //____________________ Time Manager.
  void runTimeManager();

  std::list<int> getList();
  std::vector<int> getVector();

private:
  std::vector<int> _sortVector;
  std::list<int> _sortList;
};