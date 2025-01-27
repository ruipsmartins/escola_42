#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <iostream>
# include <deque>
# include <vector>
# include <list>

template<typename T>
typename T::iterator easyfind(T& haystack, int needle)
{
	typename T::iterator i;
	i = std::find(haystack.begin(), haystack.end(), needle);
    return(i);
}

#endif