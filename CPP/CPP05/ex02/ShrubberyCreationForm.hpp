/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:50:50 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/02 11:34:41 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FROM_HPP

#define SHRUBBERY_CREATION_FROM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
    private:
        std::string target;    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& SCForm);
        ShrubberyCreationForm(std::string otherTarget);
        ~ShrubberyCreationForm();

        
        void	execute(Bureaucrat const & executor) const;
        const   std::string& getTarget() const;
        
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& SCForm);
};

#endif