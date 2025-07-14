/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:23:56 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/14 07:35:57 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{}

Base *Base::generate(void)
{
	int		randNbr;
	Base	*base;

	std::srand(time(NULL));
	randNbr = std::rand() % 3;
	switch (randNbr)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			base = new C();
	}
	return base;
}

void Base::identify(Base* base)
{
	if (!base)
		std::cout << "You are passing a NULL pointer" << std::endl;
	else if (dynamic_cast<A*>(base))
		std::cout << "The object is of type A" << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << "The object is of type B" << std::endl;
	else if (dynamic_cast<C*>(base))
		std::cout << "The object is of type C" << std::endl;
	else
		std::cout << "The object is of an unknown type" << std::endl;
}


void	Base::identify(Base& base)
{
	try
	{
		A& a = dynamic_cast<A&>(base);
		(void)a;
		std::cout << "The object is of type A" << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}

	try
	{
		B& b = dynamic_cast<B&>(base);
		(void)b;
		std::cout << "The object is of type B" << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}

	try
	{
		C& c = dynamic_cast<C&>(base);
		(void)c;
		std::cout << "The object is of type C" << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}

	std::cout << "The object is of an unknown type" << std::endl;
}