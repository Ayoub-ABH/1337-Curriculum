/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:04:37 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/02 10:16:40 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP

#define INTERN_HPP

#include <iostream>
#include <exception>

class AForm;

class Intern
{
    public:
        Intern();
        Intern(const std::string name, int grade);
        Intern(const Intern& intern);
        ~Intern();
        
        AForm	*makeForm(std::string name, std::string target);
		Intern&         operator=(const Intern& Intern);
    private:
        AForm *newRRForm(std::string target);
        AForm *newSCForm(std::string target);
        AForm *newPPForm(std::string target);
};

std::ostream&	operator<<(std::ostream &out, const Intern& intern);

#endif