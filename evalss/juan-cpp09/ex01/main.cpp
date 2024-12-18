#include <iostream>
#include <stdexcept>
#include "RPN.hpp"  // Ensure this includes the RPN class

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "❌ Error: Invalid number of arguments. Please provide an RPN expression." << std::endl;
        return 1;
    }

    try {
        RPN calculator;
        calculator.stackTokenCreation(argv[1]);
        int result = calculator.getResult();
        std::cout << "🎉 The result of the RPN expression is: " << result << " 🎉" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "🚨 " << e.what() << " 🚨" << std::endl;
        return 1;
    }

    return 0;
}
