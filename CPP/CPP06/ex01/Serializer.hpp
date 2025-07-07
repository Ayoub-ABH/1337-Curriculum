/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:49:14 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/06 16:58:35 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP

# define SERIALIZER_HPP

# include <iostream>

struct Data
{
	int     intNumber;
    float   floatNumber;
	long    longNumber;
	double  doubleNumber;
    char    caracter;
	bool    boolean;
};

class Serializer
{
	private :
		Serializer(void);
		~Serializer(void);
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);

	public :
		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif