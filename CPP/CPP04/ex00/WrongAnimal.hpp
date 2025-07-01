/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:57:03 by aait-bab          #+#    #+#             */
/*   Updated: 2025/04/20 13:18:40 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& animal);
		WrongAnimal&	operator=(const WrongAnimal& animal);
		void			makeSound(void) const;
		std::string     getType(void) const;
};

#endif