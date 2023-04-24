#include "BitcoinExchange.hpp"
#include <fstream>

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
    }
    return *this;
}

DataBase::DataBase(const DataBase &a)
{
    *this = a;
}

DataBase::DataBase(const std::string &input):
    m_input(input)
{
    ;
}
