/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:50:50 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/02 13:28:49 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBO_TO_MY_REQUEST

#define ROBO_TO_MY_REQUEST

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        std::string target;    
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& RTMRForm);
        RobotomyRequestForm(std::string otherTarget);
        ~RobotomyRequestForm();

        void	execute(Bureaucrat const & executor) const;
        const   std::string& getTarget() const;

        RobotomyRequestForm& operator=(const RobotomyRequestForm& RTMRForm);
};

#endif