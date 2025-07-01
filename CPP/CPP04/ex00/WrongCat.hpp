/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:57:33 by aait-bab          #+#    #+#             */
/*   Updated: 2025/04/20 13:21:35 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#ifndef WRONGCAT_HPP

# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat& animal);
		WrongCat&	operator=(const WrongCat& animal);
		void		makeSound(void) const;
};

#endif