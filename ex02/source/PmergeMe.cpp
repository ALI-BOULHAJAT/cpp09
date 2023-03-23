#include "../include/PmergeMe.hpp"

void trim(std::string& string, std::string value) {
	size_t first = string.find_first_not_of(value);
	string.erase(0, first);
	size_t last = string.find_last_not_of(value);
	size_t len = string.length() - (last - 1);
	string.erase(last + 1, len);
}

bool is_number(std::string number) {
    for (int i = 0; number[i]; i++) {
        if (!isdigit(number[i]))
        return false;
    }
    return true;
}

void check_duplicate(std::list<int> data) {
    std::list<int>::iterator bg_list;
    std::list<int>::iterator tmp_list;
    std::list<int>::iterator end_list = data.end();
    for (bg_list = data.begin(); bg_list != end_list; bg_list++) {
        tmp_list = bg_list;
        for (tmp_list++; tmp_list != end_list; tmp_list++) {
            if (*bg_list == *tmp_list)
                throw std::runtime_error("Error : duplicate");
        }
    }
}

void save_num(char **av, std::list<int> &data) {
    int index;
    int num;
    std::string number;

    for (int i = 1; av[i]; i++) {
        std::string str(av[i]);
        trim(str, " ");
        while ((index = str.find(" ")) && index != -1) {
            if (!is_number(str.substr(0, index)))
                throw std::runtime_error("Error : not a number");
            num = atoi((str.substr(0, index)).c_str());
            str.erase(0, index + 1);
            if (num >= 0 && num < 2147483647)
                data.push_back(num);
            else
                throw std::runtime_error("Error : not valid number");
            trim(str, " ");
        }
        if (!is_number(str))
            throw std::runtime_error("Error : not a number");
        num = atoi(str.c_str());
        if (num >= 0 && num < 2147483647)
            data.push_back(num);
        else throw std::runtime_error("Error : not valid number");
    }
}

////////////////// vactor //////////////////////////////////

std::vector<int> merge_vec(std::vector<int> left, std::vector<int> right) {
    std::vector<int> final_vec;
    while (left.size() && right.size()) {
        if (*left.begin() < *right.begin()) {
            final_vec.push_back(*left.begin());
            left.erase(left.begin());
        }
        else {
            final_vec.push_back(*right.begin());
            right.erase(right.begin());
        }
    }
    while (left.size()) {
        final_vec.push_back(*left.begin());
        left.erase(left.begin());
    }
    while (right.size()) {
        final_vec.push_back(*right.begin());
        right.erase(right.begin());
    }
    return final_vec;
}

void insert_vec(std::vector<int> &my_vec) {
    int tmp;
    if (my_vec.size() > 10) {
        int middle = my_vec.size() / 2;
        std::vector<int> left(my_vec.begin(), my_vec.begin() + middle);
        std::vector<int> right(my_vec.begin() + middle, my_vec.end());
        insert_vec(left);
        insert_vec(right);
        my_vec = merge_vec(left, right);
    }
    else {
       std::vector<int>::iterator it_bg = my_vec.begin();
        for (size_t i = 1; i < my_vec.size(); i++) {
        size_t j = i;
        while (j > 0 && *(it_bg + j - 1) > *(it_bg + j)) {
            tmp = *(it_bg + j - 1);
            *(it_bg + j - 1) = *(it_bg + j);
            *(it_bg + j) = tmp;
            j--;
        }
        }
    }

}

void fill_sort_vector(std::list<int> data) {
    std::vector<int> my_vec;
    double vector_time;
    std::list<int>::iterator it_bg;
    std::list<int>::iterator it_end = data.end();
    std::clock_t start_vec = std::clock();
    for (it_bg = data.begin(); it_bg != it_end; it_bg++) {
        my_vec.push_back(*it_bg);
    }
    insert_vec(my_vec);
    std::clock_t end_vec = std::clock();
    vector_time = (double(end_vec - start_vec) / CLOCKS_PER_SEC) * 1000;
}

////////////////// deque //////////////////////////////////

void fill_sort_deque(std::list<int> data) {
    std::deque<int> my_deque;
    double deque_time;
    
}