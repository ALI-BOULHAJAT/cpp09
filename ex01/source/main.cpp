#include "../include/RPN.hpp"

#include <sstream>

int main (int ac, char **av) {
    std::stack<int> number;
    if (ac != 2) {
        std::cout << "error argument" << std::endl;
        exit(1);
    }
    else
        fill_stack(av[1], number);
    return (0);
}