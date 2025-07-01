/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:40:51 by aait-bab          #+#    #+#             */
/*   Updated: 2025/04/20 16:24:54 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	Animal* animals[10];
	
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();

	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 10; i++)
    delete animals[i]; 

	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	Dog dog1;
	Dog dog2;
	dog1 = dog2;

	return 0;
}
