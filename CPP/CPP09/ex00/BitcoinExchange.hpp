/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:04:47 by aait-bab          #+#    #+#             */
/*   Updated: 2025/12/03 18:04:48 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream> 
#include <fstream>
#include <map>
#include <sstream>



class BitcoinExchange
{
private:
    std::map<int, double>    linesMap;
    std::string              pathFile;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& btcExg);

    BitcoinExchange& operator=(const BitcoinExchange& btcExg);

    bool parseDate(const std::string &date);
    bool parseValue(const std::string &value);

    int getDaysOfMonth(int month, int year);
    bool isLeapYear(int year);

    void predict(const std::string &pathfile);

    ~BitcoinExchange();
};




#endif
