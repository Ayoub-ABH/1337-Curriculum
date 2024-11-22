/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:40:51 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/22 10:41:13 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void f()
{
    system("leaks a.out");
}
int main()
{
    atexit(f);
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	j->makeSound();
	j->makeSound();
	delete j;
	delete i;

	return 0;
}
