
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}



BitcoinExchange::BitcoinExchange(const BitcoinExchange& btcExg)
{
    *this = btcExg;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& btcExg)
{
    if (this == &btcExg)
        return *this;
    
    this->pathFile = btcExg.pathFile;
    this->linesMap = btcExg.linesMap;
    return *this;
}

bool BitcoinExchange::parseDate(const std::string &date)
{
    
    return true;
}

bool BitcoinExchange::parseValue(const std::string &value)
{
    
    return true;
}

void BitcoinExchange::parseFile(const std::string &pathfile)
{
    std::ifstream file(pathfile);
    std::string   line;
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::getline(file, line);
    while(std::getline(file, line))
    {
        std::string date = line.substr(0, line.find('|') - 1);
        std::string value = line.substr(line.find('|') + 2);
        if  (parseDate(date) && parseValue(value))
        {
            std::cout << "Date: " << date << " Value: " << value << std::endl;
        }
    }

}

void BitcoinExchange::predict()
{

}

BitcoinExchange::~BitcoinExchange()
{

}
