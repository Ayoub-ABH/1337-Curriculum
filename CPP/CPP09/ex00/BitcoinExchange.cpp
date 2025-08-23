
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}



BitcoinExchange::BitcoinExchange(const BitcoinExchange& btcExg)
{
    
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& btcExg)
{
    if (this == &btcExg)
        return *this;
    
    this->pathFile = btcExg.pathFile;
    

}

void BitcoinExchange::parseFile(const std::string &pathfile)
{


}

void BitcoinExchange::predict()
{

}

BitcoinExchange::~BitcoinExchange()
{

}
