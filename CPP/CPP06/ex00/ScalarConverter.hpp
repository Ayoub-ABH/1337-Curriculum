/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:44:17 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/05 14:19:11 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cmath>

enum Type {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_PSEUDO,
    TYPE_INVALID
};


class ScalarConverter{
    public:
        static void convert(std::string str);
        static Type detectType(std::string str);
        static void convertFromChar(const std::string& str);
        static void convertFromInt(const std::string& str);
        static void convertFromFloat(const std::string& str);
        static void convertFromDouble(const std::string& str);
        static void convertFromPseudo(const std::string& str);
        
    private:
        ScalarConverter();                            
        ScalarConverter(const ScalarConverter&);     
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
};

#endif