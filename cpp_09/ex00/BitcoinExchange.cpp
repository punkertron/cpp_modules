#include <fstream>
#include <iostream>
#include <cstdlib>

#include "BitcoinExchange.hpp"

DataBase::DataBase()
{
    ;
}

DataBase::~DataBase()
{
    ;
}

DataBase &DataBase::operator=(const DataBase &a)
{
    if (this != &a)
    {
        this->m_data = a.m_data;
        this->m_input = a.m_input;
        this->m_data_file = a.m_data_file;
    }
    return *this;
}

DataBase::DataBase(const DataBase &a)
{
    *this = a;
}

DataBase::DataBase(const std::string &data_file, const std::string &input):
    m_data_file(data_file), m_input(input)
{
    std::ifstream in_data;

    in_data.open(data_file.c_str());

    if (!in_data.is_open())
    {
        std::cerr << "Error: could not open data file." << std::endl;
        return ;
    }

    std::string temp;
    std::size_t pos;
    while (!in_data.fail())
    {
        getline(in_data, temp);
        pos = temp.find(",");
        m_data.push_back(std::make_pair(temp.substr(0, pos), std::atof(temp.substr(pos + 1).c_str())));
    }
    std::cout << m_data.size() << std::endl;

    std::vector<std::pair<std::string, float> >::iterator it = m_data.begin();
    for (size_t i = 0; i < m_data.size(); ++i)
    {
        std::cout << it->first << ' ' << it->second << std::endl;
        ++it;
    }

    in_data.close();
}
