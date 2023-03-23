#include "../include/BitcoinExchange.hpp"

void trim(std::string& string, std::string value) {
	size_t first = string.find_first_not_of(value);
	string.erase(0, first);
	size_t last = string.find_last_not_of(value);
	size_t len = string.length() - (last - 1);
	string.erase(last + 1, len);
}

std::string intToString(int num) {
    std::stringstream ss;
    ss << num;
    return ss.str();
}

void save_data(std::map <std::string, double > &db) {
    std::ifstream   file_db;
    std::string     line;
    std::string     date;
    int             index;
    double             price;
    int             line_num;

    file_db.open("file/data.csv");
    if (file_db.is_open()) {
        std::getline(file_db, line);
        line_num = 1;
        while (std::getline(file_db, line)) {
            line_num++;
            index = line.find(",");
            if (index == -1){
                throw std::runtime_error("error in db file in line " + intToString(line_num));
            }
            date = line.substr(0, index);
            line.erase(0, index + 1);
            price = atof(line.c_str());
            db.insert(std::make_pair(date, price));
        }
    }
    else
        throw std::runtime_error("error opening db file"); 
}

bool leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
        } else
            return true;
    }
    return false;
}

bool valid_date(std::string date) {
    int year, month, day;

    if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    if (year >= 1900 && year <= 9999 && month >= 1 && month <= 12) {
        if (month == 2) {
            if (leap_year(year) && day >= 1 && day <= 29) {
                return true;
            } else if (!leap_year(year) && day >= 1 && day <= 28) {
                return true;
            }
        } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day >= 1 && day <= 30) {
            return true;
        } else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day >= 1 && day <= 31) {
            return true;
        }
    }
    std::cout << "Error: bad input => " << date << std::endl;
    return false;
}


/////////////////////////////

void calcul_res(std::map <std::string, double > db, std::string date, double n_coin) {
    if (n_coin < 0)
        std::cout << "Error: not a positive number." << std::endl;
    else if ( n_coin > 1000)
        std::cout << "Error: too large a number." << std::endl;
    else
        std::cout << date << " => " << n_coin << " = " << (n_coin * db.lower_bound(date)->second) << std::endl;

}

void calcul_excha(std::map <std::string, double > db, std::string in_file) {
    std::ifstream fd_file;
    std::string line;
    std::string date;
    double n_coin;
    int index;

    (void)db;
    (void)in_file;

    fd_file.open(in_file);
    if (fd_file.is_open()) {
        std::getline(fd_file, line);
        while (std::getline(fd_file, line)) {
            trim(line, " ");
            if (!line.length())
                continue;
            index = line.find("|");
            if (index == -1){
                std::cout << "Error: bad input => " + line << std::endl;
                continue;
            }
            date = line.substr(0, index);
            trim(date, " ");
            line.erase(0, index + 1);
            trim(line, " ");
            n_coin = atof(line.c_str());
            if (valid_date(date))
                calcul_res(db, date, n_coin);
        }
    }
    else
        throw std::runtime_error("Error: could not open file."); 
}
