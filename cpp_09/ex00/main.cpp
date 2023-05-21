#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <cstdlib> //exit
#include <climits>

struct s_input {
    int year;
    int month;
    int day;
    float val;
};

static bool is_leap_year(int year)
{
    bool res = false;

    if (year % 400 == 0)
        res = true;
    else if (year % 100 == 0)
        res = false;
    else if (year % 4 == 0)
        res = true;
    return res;
}

static bool is_bad_input(const std::string &temp, struct s_input &input)
{
    if (temp.length() < 14
        || temp.find(" | ") == std::string::npos
        || sscanf(temp.substr(0, temp.find(" ")).c_str(), "%d-%d-%d", &input.year, &input.month, &input.day) < 3
        || sscanf(temp.substr(temp.find(" | ") + 3).c_str(), "%f", &input.val) < 1)
    {
        std::cout << "Error: bad input => " << temp << '.' << std::endl;
        return true;
    }
    if (input.year < 1 || input.month > 12 || input.month < 1 || input.day < 0
        || (is_leap_year(input.year) && input.month == 2 && input.day > 29)
        || (!is_leap_year(input.year) && input.month == 2 && input.day > 28)
        || ((input.month == 1 || input.month == 3 || input.month == 5 || input.month == 7
            || input.month == 8 || input.month == 10) && input.day > 31)
        || ((input.month == 4 || input.month == 6 || input.month == 8 || input.month == 11)
            && input.day > 30))
    {
        std::cout << "Error: bad input => " << temp.substr(0, temp.find(" ")) << '.' << std::endl;
        return true;
    }
    if (input.year <= 2009 || (input.year == 2009 && input.month == 1 && input.day == 1))
    {
        std:: cout << "Error: first day is 2009-01-02." << std:: endl;
        return true;
    }
    if (input.val < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return true;
    }
    if (input.val > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return true;
    }

    return false;
}

static void print_res(unsigned long long inp, float rate, float val)
{
    int day = inp % 100;
    int month = (inp / 100) % 100;
    int year = inp / 10000;
    std::cout << year << '-';
    if (month < 10)
        std::cout << '0';
    std::cout << month << '-';
    if (day < 10)
        std::cout << '0';
    std::cout << day
        << " => " << val << " = " << val * rate << std::endl;
}

static void main_calc(const std::map<unsigned long long, float> &data, const char *input_file)
{
    std::ifstream in_data;

    in_data.open(input_file);
    if (!in_data.is_open())
    {
        std::cerr << "Error: could not open data file." << std::endl;
        exit (EXIT_FAILURE);
    }

    struct s_input input;

    std::string temp;
    unsigned long long inp;
    std::map<unsigned long long, float>::const_iterator it;
    while (getline(in_data, temp))
    {
        if (is_bad_input(temp, input))
            continue ;
        inp = input.year * 10000 + input.month * 100 + input.day;
        it = data.find(inp);
        if (it != data.end())
        {
            print_res(inp, it->second, input.val);
        }
        else
        {
            while (--inp && (it = data.find(inp)) == data.end())
            {
                ;
            }
            print_res(inp, it->second, input.val);
        }
    }

    in_data.close();
}

static void get_data(std::map<unsigned long long, float> &data, const char *input_file)
{
    std::ifstream in_data;

    in_data.open(input_file);

    if (!in_data.is_open())
    {
        std::cerr << "Error: could not open database" << std::endl;
        exit (EXIT_FAILURE);
    }

    std::string temp;
    getline(in_data, temp);

    int year, month, day;
    float val;
    while (getline(in_data, temp))
    {
        sscanf(temp.c_str(), "%d-%d-%d,%f", &year, &month, &day, &val);
        data[year * 10000 + month * 100 + day] = val;
    }

    in_data.close();
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    std::map<unsigned long long, float> data;
    get_data(data, "data.csv");

    main_calc(data, argv[1]);

    return 0;
}
