/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:58:01 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/06 20:59:55 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void){}

Serializer::~Serializer(void){}

Serializer::Serializer(const Serializer&){}

Serializer& Serializer::operator=(const Serializer&)
{
    return *this;
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data *dataPtr = reinterpret_cast<Data *>(raw);
	return (dataPtr);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t uPtr = reinterpret_cast<uintptr_t >(ptr);
	return (uPtr);
}