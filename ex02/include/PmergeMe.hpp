#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#define RED "\x1b[31m"
#define END_CLR "\033[0m"

void save_num(char **av, std::list<int> &data);
void fill_sort_vector(std::list<int> data);
void check_duplicate(std::list<int> data);

#endif