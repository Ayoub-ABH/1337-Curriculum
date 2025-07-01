/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:50:50 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/01 18:27:35 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FROM_HPP

#define SHRUBBERY_CREATION_FROM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        std::string target;    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& SCForm);
        ShrubberyCreationForm(std::string otherTarget);
        ~ShrubberyCreationForm();

        const std::string& getTarget() const;
        void	execute(Bureaucrat const & executor) const;
        void    beSigned(const Bureaucrat& b);

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& SCForm);
};

#endif