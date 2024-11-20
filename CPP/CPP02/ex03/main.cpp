/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:55:24 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/12 11:58:19 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main()
{
    Point p3(5.0f, 0);
    Point p1(0, 5.0f);
    Point p2(0, 0);
    Point p(1.0f, 1.0f);
    std::cout << "the Fixed p.x " << p.getX()  << " && p.y " << p.getY() << std::endl;
    std::cout << "the Fixed p1.x " << p1.getX() << " && p1.y " << p1.getY() << std::endl;
    std::cout << "the Fixed p2.x " << p2.getX() << " && p2.y " << p2.getY() << std::endl;
    std::cout << "the Fixed p3.x " << p3.getX() << " && p3.y " << p3.getY() << std::endl;
    std::cout << ">>>>>>>> " << (bsp(p3, p2, p1, p) ? "inside" : "outside") << " <<<<<<<<" << std::endl;
    return 0;
}