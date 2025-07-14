/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:47:34 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/14 06:31:39 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

Type ScalarConverter::detectType(std::string str)
{
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
        return TYPE_PSEUDO;

    if (str.length() == 1 && !std::isdigit(str[0]))
        return TYPE_CHAR;

    size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    bool isInt = true;
    for (; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
        {
            isInt = false;
            break;
        }
    }
    if (isInt)
        return TYPE_INT;

    if (str.back() == 'f')
    {
        std::string core = str.substr(0, str.length() - 1);
        size_t j = (core[0] == '+' || core[0] == '-') ? 1 : 0;
        int dot_count = 0;
        for (; j < core.length(); ++j)
        {
            if (core[j] == '.')
                dot_count++;
            else if (!std::isdigit(core[j]))
                return TYPE_INVALID;
        }
        if (dot_count == 1)
            return TYPE_FLOAT;
    }

    int dot_count = 0;
    size_t k = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    for (; k < str.length(); ++k)
    {
        if (str[k] == '.')
            dot_count++;
        else if (!std::isdigit(str[k]))
            return TYPE_INVALID;
    }
    if (dot_count == 1)
        return TYPE_DOUBLE;

    return TYPE_INVALID;
}

void ScalarConverter::convertFromChar(const std::string &str)
{
    char chr = str[0];
    int intgr = static_cast<int>(chr);
    float flt = static_cast<float>(chr);
    double dbl = static_cast<double>(chr);

    if (intgr < 0 || intgr > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(chr))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << chr << "'" << std::endl;
    std::cout << "int: " << intgr << std::endl;
    std::cout << "float: " << flt << "f" << std::endl;
    std::cout << "double: " << dbl << std::endl;
}

void ScalarConverter::convertFromInt(const std::string &str)
{
    char *end;
    double intgr = std::strtod(str.c_str(), &end);
    char chr = static_cast<char>(intgr);

    if (intgr < 0 || intgr > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(chr))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << chr << "'" << std::endl;
        
    if (intgr > INT_MAX || intgr < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(intgr) << std::endl;
        
    if (intgr - static_cast<int>(intgr) == 0)
        std::cout << std::fixed << std::setprecision(1);
        
    std::cout << "float: " << static_cast<float>(intgr) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(intgr) << std::endl;    
}

void ScalarConverter::convertFromFloat(const std::string &str)
{
    char *end;
    double flt = std::strtod(str.c_str(), &end);
    char chr = static_cast<char>(flt);
    
    if (flt < 0 || flt > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(chr))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << chr << "'" << std::endl;
        
    if (flt > INT_MAX || flt < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(flt) << std::endl;
    if (flt - static_cast<int>(flt) == 0)
        std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(flt) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(flt) << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string &str)
{
    char *end;
    double dbl = std::strtod(str.c_str(), &end);
    char chr = static_cast<char>(dbl);
    
    if (dbl < 0 || dbl > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(chr))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << chr << "'" << std::endl;
    
    if (dbl > INT_MAX || dbl < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(dbl) << std::endl;
        
    if (dbl - static_cast<int>(dbl) == 0)
        std::cout << std::fixed << std::setprecision(1);
    
    std::cout << "float: " << static_cast<float>(dbl) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(dbl) << std::endl;
}

void ScalarConverter::convertFromPseudo(const std::string &str)
{
    std::string value = str;
    
    if (value == "+inff" || value == "-inff" || value == "nanf")
        value.pop_back();
    std::cout << "char: impossible\nint: impossible" << std::endl;
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    Type type = detectType(str);
    switch (type)
    {
        case TYPE_CHAR:
            convertFromChar(str);
            break;
        case TYPE_INT:
            convertFromInt(str);
            break;
        case TYPE_FLOAT:
            convertFromFloat(str);
            break;
        case TYPE_DOUBLE:
            convertFromDouble(str);
            break;
        case TYPE_PSEUDO:
            convertFromPseudo(str);
            break;
        default:
            std::cout << "Invalid literal." << std::endl;
    }
}
