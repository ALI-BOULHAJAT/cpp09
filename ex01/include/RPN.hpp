#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <vector>
#include <stack>

bool is_oper(char c);
void fill_stack(char *line, std::stack<int> &number);
void calcul_stack(std::stack<int> &number, char opr);


#endif