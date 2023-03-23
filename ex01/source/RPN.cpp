#include "../include/RPN.hpp"

bool is_oper(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

void calcul_stack(std::stack<int> &number, char opr) {
    int first;
    int last;

   if(number.size() >= 2 ) {
        last = number.top();
        number.pop();
        first = number.top();
        number.pop();
        if (opr == '+')
            number.push(first + last);
        else if (opr == '-')
            number.push(first - last);
        else if (opr == '*')
            number.push(first * last);
        else {
            if (last == 0){
                std::cout << "Infinity\n";
                exit (1); 
            }
            number.push(first / last);
        }
    }
    else {
        std::cout << "error\n";
        exit(1);
    }
}

void fill_stack(char *line, std::stack<int> &number) {
    for (size_t i = 0; line[i] ; ++i) {
        if (line[i] == ' ')
            continue;
        else if (isdigit(line[i]))
            number.push(atoi(std::string(1, line[i]).c_str()));
        else if (is_oper(line[i]))
            calcul_stack(number, line[i]);
        else {
            std::cout << "error\n";
            exit(1);
        }
    }
    if (number.size() == 1)
        std::cout << number.top() << std::endl;
    else {
        std::cout << "error\n";
        exit (1);
    }
}