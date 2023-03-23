#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#define RED "\x1b[31m"
#define END_CLR "\033[0m"

void save_data(std::map <std::string, double > &db);
void calcul_excha(std::map <std::string, double > db, std::string in_file);

#endif