#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iterator>

class NotFoundException : public std::exception {
    public:
        const char *what() const throw() {
            return "... not Found";
        }
};

template <typename Template>
typename Template::iterator easyfind(Template &container, int value)
{
    typename Template::iterator idx = std::find(container.begin(), container.end(), value);
    if (idx == container.end())
        throw NotFoundException();
    return idx;
};


#endif