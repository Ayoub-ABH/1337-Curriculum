/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:32:22 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/14 07:00:43 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base b_obj;
	Base *b_ptr;
	A a;
	B b;
	C c;
	
	b_ptr = b_obj.generate();
	
	b_obj.identify(b_ptr);
	b_obj.identify(NULL);
	
	delete(b_ptr);
	
	b_obj.identify(a);
	b_obj.identify(b);
	b_obj.identify(b_obj);
}