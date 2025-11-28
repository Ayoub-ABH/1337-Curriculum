
#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream> 
#include <fstream>
#include <map>


class BitcoinExchange
{
private:
    std::map<int, double>    linesMap;
    std::string              pathFile;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& btcExg);

    BitcoinExchange& operator=(const BitcoinExchange& btcExg);

    void parseFile(const std::string &pathfile);
    bool parseDate(const std::string &date);
    bool parseValue(const std::string &value);

    void predict();

    ~BitcoinExchange();
};




#endif
