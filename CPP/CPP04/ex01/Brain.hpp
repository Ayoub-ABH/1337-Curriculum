/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:16:00 by aait-bab          #+#    #+#             */
/*   Updated: 2025/04/20 13:47:42 by aait-bab         ###   ########.fr       */
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
        Brain(const Brain& brain);
        Brain& operator = (const Brain& brain);
        ~Brain();
};

#endif