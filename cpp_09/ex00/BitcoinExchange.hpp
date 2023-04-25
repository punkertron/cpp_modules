#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <vector>

class DataBase
{
private:
    std::vector<std::pair<std::string, float> > m_data;
    std::string m_data_file;
    std::string m_input;

    DataBase();

public:
    ~DataBase();

    DataBase &operator=(const DataBase &a);
    DataBase(const DataBase &a);
    DataBase(const std::string &data_file, const std::string &input);
};

#endif //BITCOINEXCHANGE_HPP