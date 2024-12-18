#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <list>
#include <sstream>
#include <stdexcept>

// ______ Utilities.

template <typename T> void print(const T &container) {
  std::cout << "[";
  for (typename T::const_iterator it = container.begin(); it != container.end();
       ++it) {
    typename T::const_iterator itCheck = it;
    std::cout << *it;
    if (++itCheck != container.end())
      std::cout << ",";
  }
  std::cout << "]" << std::endl;
}

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &_src) { *this = _src; }
PmergeMe &PmergeMe::operator=(const PmergeMe &_src) {
  if (this != &_src)
    return (*this);
  return (*this);
}

//_______________ check input.

void PmergeMe::inputCheck(const std::string &val) {

  int value;
  char *end;

  value = std::strtol(val.c_str(), &end, 10);
  if (*end != '\0' || (value < 0))
    throw(std::runtime_error("Error not valid number"));
  _sortVector.push_back(value);
  _sortList.push_back(value);
}

void PmergeMe::initialPairingVector() {
  for (size_t i = 0; i + 1 < _sortVector.size(); i += 2)
    if (_sortVector[i] > _sortVector[i + 1])
      std::swap(_sortVector[i], _sortVector[i + 1]);
}

void PmergeMe::initialPairingList() {
  for (std::list<int>::iterator it = _sortList.begin(); it != _sortList.end();
       ++it) {
    std::list<int>::iterator swapIt = it;
    std::list<int>::iterator nexNode = ++it;
    if (nexNode == _sortList.end())
      break;
    if (*swapIt > (*nexNode))
      std::iter_swap(swapIt, nexNode);
  }
}

void PmergeMe::mergeVector(int left, int mid, int right) {
  std::vector<int> leftVector(_sortVector.begin() + left,
                              _sortVector.begin() + mid + 1);
  std::vector<int> rightVector(_sortVector.begin() + mid + 1,
                               _sortVector.begin() + right + 1);
  // if (mid == (_sortVector.size() / 2)) {

  //   std::cout << "Print Vector Left > " << std::endl;
  //   print(leftVector);
  //   std::cout << "Print Vector Right > " << std::endl;
  //   print(rightVector);
  // }

  size_t i = 0, j = 0, k = left;

  while (i < leftVector.size() && j < rightVector.size()) {
    (leftVector[i] <= rightVector[j]) ? _sortVector[k++] = leftVector[i++]
                                      : _sortVector[k++] = rightVector[j++];
  }
  // fill the rest of the values that are in the vector.
  while (i < leftVector.size())
    _sortVector[k++] = leftVector[i++];
  while (j < rightVector.size())
    _sortVector[k++] = rightVector[j++];
}

void PmergeMe::mergeSortVector(int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSortVector(left, mid);
    mergeSortVector(mid + 1, right);
    mergeVector(left, mid, right);
  }
}

void PmergeMe::mergeSortList(std::list<int> &lst) {
  if (lst.size() <= 1)
    return;
  std::list<int> rightList;
  std::list<int> leftList;
  std::list<int>::iterator it = lst.begin();
  for (size_t i = 0; i < lst.size() / 2; ++i, ++it)
    leftList.push_back(*it);
  for (; it != lst.end(); ++it)
    rightList.push_back(*it);

  mergeSortList(leftList);
  mergeSortList(rightList);
  lst.clear();
  leftList.merge(rightList);
  lst = leftList;
}

void PmergeMe::runTimeManager() {
  clock_t startTme = clock();
  mergeSortVector(0, _sortVector.size() - 1);
  clock_t finishTime = clock();
  double durationVec =
      static_cast<double>(finishTime - startTme) / CLOCKS_PER_SEC;
  clock_t startTmeL = clock();
  mergeSortList(_sortList);
  clock_t finishTimeL = clock();
  double durationList =
      static_cast<double>(finishTimeL - startTmeL) / CLOCKS_PER_SEC;
  std::cout << GREEN << "AFTER  : ";
  print(_sortVector);

  std::cout << CYAN << "Time to process with std::vector : " << durationVec << " seconds"
            << std::endl;

  std::cout<<MAGENTA<< "Time to process with std::list   : " << durationList << " seconds"
            << std::endl;
}
std::list<int> PmergeMe::getList() { return (_sortList); }

std::vector<int> PmergeMe::getVector() { return (_sortVector); }