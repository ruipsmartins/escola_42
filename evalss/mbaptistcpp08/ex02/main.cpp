#include "MutantStack.hpp"
#include <list>

void testComparisonWithList() {

    MutantStack<int> mstack;
    std::list<int> lst;

    mstack.push(5);
    mstack.push(10);
    mstack.push(15);

    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);

    // Compare MutantStack with std::list
    std::cout << "MutantStack contents:" << "\n";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << "\n";
    }

    std::cout << "std::list contents:" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << "\n";
    }
}

void testEmptyStack() {
    MutantStack<int> mstack;

    try {
        mstack.pop();
    } catch (const std::exception& e) {
        std::cout << "Exception on pop: " << e.what() << "\n";
    }

    try {
        std::cout << "Top element of empty stack: " << mstack.top() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Exception on top: " << e.what() << "\n";
    }
}

void testCopyAndAssignment() {
    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);

    // Test copy constructor
    MutantStack<int> copy(original);
    std::cout << "Copy stack:" << "\n";
    for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it) {
        std::cout << *it << "\n";
    }

    // Test assignment operator
    MutantStack<int> assigned;
    assigned = original;
    std::cout << "Assigned stack:" << "\n";
    for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it) {
        std::cout << *it << "\n";
    }
}

int main ()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    try {
        testCopyAndAssignment();
        testComparisonWithList();
        testEmptyStack();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
