/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:50:25 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/02 13:28:45 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIAL_PARDON_FORM_HPP

#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        std::string target;
        int         gradeToSign;
        int         gradeToExecute;        
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& PPForm);
        PresidentialPardonForm(std::string otherTarget);
        ~PresidentialPardonForm();

        void	execute(Bureaucrat const & executor) const;
        const   std::string& getTarget() const;

        PresidentialPardonForm& operator=(const PresidentialPardonForm& PPForm);
};



#endif