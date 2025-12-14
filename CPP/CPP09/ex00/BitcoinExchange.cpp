/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:04:44 by aait-bab          #+#    #+#             */
/*   Updated: 2025/12/03 18:04:45 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream dataFile("data.csv");
    std::string   line;
    

    if (!dataFile.is_open())
    {
        std::cerr << "Error: could not open data.csv file." << std::endl;
        return;
    }
    std::getline(dataFile, line);
    while (std::getline(dataFile, line))
    {
        std::stringstream ss(line);
        int year,month,day;
        char dash,dash1,comma;
        double value;
        ss>>year>>dash>>month>>dash1>>day>>comma>>value;
        int key = year * 10000 + month * 100 + day;
        linesMap[key] = value;
    }
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

int BitcoinExchange::getDaysOfMonth(int month, int year)
{
    if (month == 2)
        return (isLeapYear(year) ? 29 : 28);
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


bool BitcoinExchange::parseDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }
    if (day > getDaysOfMonth(month, year))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }
    int key = year * 10000 + month * 100 + day;
    if (key < linesMap.begin()->first || key > linesMap.rbegin()->first)
    {
        std::cerr << "Error: no data available for date => " << date << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::parseValue(const std::string &value)
{
    char* end;
    double val = strtod(value.c_str(), &end);
    if (*end != '\0' || end == value.c_str())
    {
        std::cerr << "Error: bad input => " << value << std::endl;
        return false;
    }
    if (val < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}


void BitcoinExchange::predict(const std::string &pathfile)
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
        size_t delimiterPos = line.find('|');
        if (delimiterPos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, delimiterPos - 1);
        std::string value = line.substr(delimiterPos + 2);
        std::cout << date << std::endl;
        std::cout << value << std::endl;
        if  (parseDate(date) && parseValue(value))
        {
            int year = atoi(date.substr(0, 4).c_str());
            int month = atoi(date.substr(5, 2).c_str());
            int day = atoi(date.substr(8, 2).c_str());
            int key = year * 10000 + month * 100 + day;
            if (linesMap.find(key) == linesMap.end())
            {
                std::map<int, double>::iterator it = linesMap.lower_bound(key);
                if (it != linesMap.begin())
                    --it;
                key = it->first;
            }
            double btcValue = linesMap[key];
            double inputValue = strtod(value.c_str(), NULL);
            double result = btcValue * inputValue;
            std::cout << date << " => " << inputValue << " = " << result << std::endl;
        }
    }
}

BitcoinExchange::~BitcoinExchange()
{

}
