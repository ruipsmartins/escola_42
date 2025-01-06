#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe():_odd(false){}

PmergeMe::PmergeMe(const PmergeMe& ref)
{
	*this = ref;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& ref)
{
	if (this != &ref)
	{
		_inp = ref._inp;
		_mainList = ref._mainList;
		_odd = ref._odd;
	}
	return *this;
}

PmergeMe::~PmergeMe(){}

int	PmergeMe::isBigVecSort()
{
	for (std::vector<int>::iterator it = _bigVec.begin(); it != _bigVec.end(); it++)
	{
		if ((it + 1) == _bigVec.end())
			return 1;
		if (*it < *(it + 1))
			return 0;
	}
	return 1;
}

void	PmergeMe::mergeVec()
{
	if (_inp.size() % 2 != 0)
	{
		_odd = true;
		_oddNbr = _inp.back();
		_inp.pop_back();
	}
	for (std::vector<int>::iterator it = _inp.begin(); it != _inp.end(); it += 2)
	{
		if ((it + 1) == _inp.end())
			break;
		if (*it < *(it + 1))
			std::iter_swap(it, (it + 1));
		_bigVec.push_back(*it);
		_smallVec.push_back(*(it + 1));
	}
	while (!isBigVecSort())
	{
		std::vector<int>::iterator itB = _bigVec.begin();
		std::vector<int>::iterator itS = _smallVec.begin();
		while (itB != _bigVec.end())
		{
			if ((itB + 1) == _bigVec.end())
				break;
			if (*itB < *(itB + 1))
			{
				std::iter_swap(itB, itB + 1);
				std::iter_swap(itS, itS + 1);
			}
			itB++;
			itS++;
		}
	}
}

void	PmergeMe::insertVec()
{
	const int	jacob[34] = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
	21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405,
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883,
	1431655765 };
	int	j = 0;
	while(jacob[j] < _smallVec.size())
	{
		j++;
		int jPos = jacob[j];
		if (jacob[j] > _smallVec.size())
			jPos = _smallVec.size();
		while (jacob[j - 1] < jPos)
		{
			std::vector<int>::iterator	it = _smallVec.begin() + jPos - 1;
			if (it != _smallVec.end())
				_bigVec.insert(findInsertVec(*it), *it);
			jPos--;
		}
	}
	if (_odd)
	{
		std::vector<int>::iterator	it = findInsertVec(_oddNbr);
		_bigVec.insert(it, _oddNbr);
	}
}

std::vector<int>::iterator	PmergeMe::findInsertVec(int in)
{
	for (std::vector<int>::iterator	it = _bigVec.begin(); it != _bigVec.end(); it++)
	{
		if (*it < in)
			return it;
	}
	return _bigVec.end();
}

int	PmergeMe::isBigListSort()
{
	std::list<int>::iterator nIt = _bigList.begin();
	nIt++;
	for (std::list<int>::iterator it = _bigList.begin(); it != _bigList.end(); it++)
	{
		if (nIt == _bigList.end())
			return 1;
		if (*it < *nIt)
			return 0;
		nIt++;
	}
	return 1;
}

void	PmergeMe::mergeList()
{
	for (std::vector<int>::iterator it = _inp.begin(); it != _inp.end(); it += 2)
	{
		if ((it + 1) == _inp.end())
			break;
		if (*it < *(it + 1))
			std::iter_swap(it, (it + 1));
		_bigList.push_back(*it);
		_smallList.push_back(*(it + 1));
	}
	while (!isBigListSort())
	{
		std::list<int>::iterator itB = _bigList.begin();
		std::list<int>::iterator itS = _smallList.begin();
		std::list<int>::iterator nItB = _bigList.begin();
		std::list<int>::iterator nItS = _smallList.begin();
		nItB++;
		nItS++;
		while (itB != _bigList.end())
		{

			if ((nItB) == _bigList.end())
				break;
			if (*itB < *nItB)
			{
				std::iter_swap(itB, nItB);
				std::iter_swap(itS, nItS);
			}
			itB++;
			itS++;
			nItB++;
			nItS++;
		}
	}
}

void	PmergeMe::insertList()
{
	const int	jacob[34] = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
	21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405,
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883,
	1431655765 };
	int	j = 0;
	while(jacob[j] < _smallList.size())
	{
		j++;
		int jPos = jacob[j];
		if (jacob[j] > _smallList.size())
			jPos = _smallList.size();
		while (jacob[j - 1] < jPos)
		{
			std::list<int>::iterator	it = _smallList.begin();
			for (int i = 0; i < jPos - 1; i++)
				it++;
			if (it != _smallList.end())
				_bigList.insert(findInsertList(*it), *it);
			jPos--;
		}
	}
	if (_odd)
	{
		std::list<int>::iterator	it = findInsertList(_oddNbr);
		_bigList.insert(it, _oddNbr);
	}
}

std::list<int>::iterator	PmergeMe::findInsertList(int in)
{
	for (std::list<int>::iterator	it = _bigList.begin(); it != _bigList.end(); it++)
	{
		if (*it < in)
			return it;
	}
	return _bigList.end();
}

void	PmergeMe::checkInp(const std::string& inp)
{
	long int	res;
	std::vector<int>::iterator	it = _inp.begin();
	std::vector<int>::iterator ite = _inp.end();
	for (int i = 0; inp[i]; i++)
	{
		if (!isdigit(inp[i]))
			throw std::invalid_argument("Error: Is not a digit");
	}
	res = atol(inp.c_str());
	if (res > INT_MAX || res < 0)
		throw std::invalid_argument("Error: Number invalid");
	if (std::find(it, ite, res) != ite)
		throw std::invalid_argument("Error: Repeated number");
	_inp.push_back(res);
}

void	PmergeMe::startAlg()
{
	std::vector<int>::iterator	inp_it = _inp.begin();
	clock_t	vStart;
	clock_t	vEnd;
	clock_t lStart;
	clock_t	lEnd;
	double	vTime;
	double	lTime;

	std::cout << "Before: ";
	while (inp_it != _inp.end())
		std::cout << *inp_it++ << " ";
	std::cout << std::endl;

	vStart = clock();
	mergeVec();
	insertVec();
	vEnd = clock();

	lStart = clock();
	mergeList();
	insertList();
	lEnd = clock();

	vTime = (static_cast<double>(vEnd - vStart) / CLOCKS_PER_SEC);
	lTime = (static_cast<double>(lEnd - lStart) / CLOCKS_PER_SEC);
	std::vector<int>::reverse_iterator	end_it = _bigVec.rbegin();
	std::cout << "After(std::vector): ";
	while (end_it != _bigVec.rend())
		std::cout << *end_it++ << " ";
	std::cout << std::endl << "After(std::list): ";
	std::list<int>::reverse_iterator	lIt = _bigList.rbegin();
	while (lIt != _bigList.rend())
		std::cout << *lIt++ << " ";
	std::cout << std::fixed;
	std::cout << std::endl << "Time to process a range of " << _inp.size() << " elements with std::vector: " << vTime << std::endl;
	std::cout << "Time to process a range of " << _inp.size() << " elements with std::list: " << lTime << std::endl;

	
}