#include "../include/BitcoinExchange.hpp"


int main(int ac, char **av) {
    std::map <std::string, double > db;
    try 
    {
        if (ac != 2)
            throw std::runtime_error("Error: could not open file.");
        else{
            save_data(db);
            calcul_excha(db, av[1]);
        }
    }
    catch(const std::runtime_error& error)
    {
        std::cerr << RED << error.what() << END_CLR << std::endl;
        return (1);
    }
    return (0);
}
