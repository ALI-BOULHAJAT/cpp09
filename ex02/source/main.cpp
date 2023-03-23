#include "../include/PmergeMe.hpp"

int main (int ac, char **av) {
    std::list<int> data;
    try 
    {
        if (ac < 2)
            throw std::runtime_error("Error: No Arguments");
        save_num(av,data);
        check_duplicate(data);
        fill_sort_vector(data);
        fill_sort_deque(data);
        
    }
    catch(const std::runtime_error& error)
    {
        std::cerr << RED << error.what() << END_CLR << std::endl;
        return (1);
    }
    return (0);
}

