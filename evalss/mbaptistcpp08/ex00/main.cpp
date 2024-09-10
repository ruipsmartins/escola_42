#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main( void ) {

    std::vector<int> vec;
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);
    vec.push_back(400);
    vec.push_back(500);

    int arr2[] = {20, 21, 22, 23, 24, 25};
    std::list<int> lst(arr2, arr2 + sizeof(arr2) / sizeof(int));

    int arr3[] = {10, 20, 30, 40, 50};
    std::deque<int> deq;
    deq.assign(arr3, arr3 + 5); 
    

    try {
        std::cout << "Searching vectors: " << *easyfind(vec, 300) << " Exist\n";
        std::cout << "Searching vectors: " << *easyfind(vec, 301) << " Exist\n";
    }
    catch(const std::exception &e) {
        std::cerr << "Vector " << e.what() << "\n";
    }
    std::cout << "\n";

    try {
        std::cout << "Searching lists: " << *easyfind(lst, 29) << " Exist\n";
        std::cout << "Searching lists: " << *easyfind(lst, 21) << " Exist\n";
    }
    catch(const std::exception &e) {
        std::cerr << "List " << e.what() << "\n";
    }
    std::cout << "\n";

    try {
        std::cout << "Searching deque: " << *easyfind(deq, 10) << " Exist\n";
        std::cout << "Searching deque: " << *easyfind(deq, 5) << " Exist\n";
    }
    catch(const std::exception &e) {
        std::cerr << "Deque " << e.what() << "\n";
    }
    std::cout << "\n";

    return 0;
}