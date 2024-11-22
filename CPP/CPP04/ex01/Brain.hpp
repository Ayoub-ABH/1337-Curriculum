/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:16:00 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/21 17:19:26 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private: 
        std::string ideas[100];
    public:
        Brain();
        Brain(Brain& brain);
        Brain& operator = (Brain& brain);
        ~Brain();
};

#endif