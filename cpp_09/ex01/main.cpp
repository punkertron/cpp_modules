#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

#include <cstdlib> //exit
#include <cctype> //isdigit

const std::string Possible_Characters = " +-/*0123456789";

static void exit_error()
{
    std::cout << "Error" << std::endl;
    exit(EXIT_FAILURE);
}

static bool is_bad_input(std::string str)
{
    for (std::size_t i = 0, n = str.size(); i < n; ++i)
    {
        if (Possible_Characters.find(str[i]) == std::string::npos)
            return true;
    }
    return false;
}

double operation_execute(char c, double first, double second)
{
    switch (c)
    {
    case '+':
        return first + second;
    case '-':
        return first - second;
    case '/':
        if (second == 0)
            exit_error();
        return first / second;
    case '*':
        return first * second;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        exit_error();
    std::string input(argv[1]);
    if (is_bad_input(input))
        exit_error();

    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

    std::stack<double> nums;
    double second, result;

    for (size_t i = 0, n = input.size(); i < n; ++i)
    {
        if (std::isdigit(input[i]))
            nums.push(input[i] - '0');
        else
        {
            if (nums.size() < 2)
                exit_error();
            second = nums.top();
            nums.pop();
            result = operation_execute(input[i], nums.top(), second);
            nums.pop();
            nums.push(result);
        }
    }
    if (nums.size() != 1)
        exit_error();
    std::cout << nums.top() << std::endl;

    return 0;
}
