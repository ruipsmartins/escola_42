#include "Span.hpp"

int main()
{
    try{
        Span sp1 = Span(5);
        sp1.addNumber(6);
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);
        // sp1.printNumbers();
        std::cout << "sp1 Shortest span: " << sp1.shortestSpan() << "\n";
        std::cout << "sp1 Longest span: "<< sp1.longestSpan() << "\n\n";


        Span sp2(10);
        sp2.addNumber(10);
        sp2.addNumber(20);
        sp2.addNumber(21);
        sp2.addNumber(70);
        // sp2.printNumbers();
        std::cout << "sp2 Shortest span: " << sp2.shortestSpan() << "\n";
        std::cout << "sp2 Longest span: " << sp2.longestSpan() << "\n\n";


        int range = 1000;
        int nbr1[range];
        for (int i = 0; i < range; i++){
            nbr1[i] = rand() % 100;
        }
        std::vector<int> vect1( nbr1, nbr1 + sizeof( nbr1 ) / sizeof( int ) );

        Span sp3(range);
        sp3.addNumbersRange(vect1);
        sp3.printNumbers();
        std::cout << "sp3 Shortest span: " << sp3.shortestSpan() << "\n";
        std::cout << "sp3 Longest span: " << sp3.longestSpan() << "\n\n";

    }
    catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }


    return 0;
}