#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stdio.h>
# include <iostream>
# include <deque>
# include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &a);
		~MutantStack();
		MutantStack&	operator=(const MutantStack &copy);

		typedef typename std::deque<T>::iterator			iterator;
		typedef typename std::deque<T>::reverse_iterator	reverse_iterator;
		iterator			begin();
		iterator			end();
		reverse_iterator	rbegin();
		reverse_iterator	rend();
};

# include "MutantStack.tpp"

#endif