/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:40:51 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/20 15:04:35 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// void f()
// {
//     system("leaks a.out");
// }

int main()
{
    // atexit(f);
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "---------------------------" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "---------------------------" << std::endl;
	delete j;
	delete i;
	delete meta;


    const WrongAnimal* Wanimal = new WrongAnimal();
	const WrongAnimal* c = new WrongCat();
    std::cout << "---------------------------" << std::endl;
	std::cout << Wanimal->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
    c->makeSound(); //will not output the cat sound!
	Wanimal->makeSound();
	std::cout << "---------------------------" << std::endl;

    delete Wanimal;
    delete c;
	return 0;
}
