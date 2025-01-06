#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <iomanip>
# include <algorithm>
# include <vector>
# include <list>
# include <climits>
# include <ctime>

class PmergeMe
{
private:
	std::vector<int>	_inp;
	std::vector<int>	_bigVec;
	std::vector<int>	_smallVec;
	std::list<int>		_mainList;
	std::list<int>		_bigList;
	std::list<int>		_smallList;
	bool				_odd;
	int					_oddNbr;
public:
	PmergeMe();
	PmergeMe(const PmergeMe& ref);
	PmergeMe& operator=(const PmergeMe& ref);
	~PmergeMe();

	void	checkInp(const std::string& inp);
	void	startAlg();

	void	mergeVec();
	void	insertVec();
	int		isBigVecSort();
	std::vector<int>::iterator	findInsertVec(int in);

	void	mergeList();
	void	insertList();
	int		isBigListSort();
	std::list<int>::iterator	findInsertList(int in);
};

#endif