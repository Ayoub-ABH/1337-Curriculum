
#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream> 
#include <fstream>
#include <vector>


class BitcoinExchange
{
private:
    std::vector<std::string>    lines;
    std::string                 pathFile;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& btcExg);

    BitcoinExchange& operator=(const BitcoinExchange& btcExg);

    void parseFile(const std::string &pathfile);

    void predict();

    ~BitcoinExchange();
};




#endif
