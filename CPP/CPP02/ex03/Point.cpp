/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:43:25 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/12 11:59:11 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed& x1, const Fixed& y1) : x(x1), y(y1) {}

Point::Point(const Point& point): x(point.x), y(point.y) {}

Point::~Point() {}

Point& Point::operator=(const Point& point)
{
    (void)point;
    return (*this);
}

Fixed  Point::getX() const
{
    return this->x;
}

Fixed  Point::getY() const
{
    return this->y;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed dX = point.getX() - c.getX();
    Fixed dY = point.getY() - c.getY();
    Fixed dX21 = c.getX() - b.getX();
    Fixed dY12 = b.getY() - c.getY();
    Fixed D = dY12 * (a.getX() - c.getX()) + dX21 * (a.getY() - c.getY());
    Fixed s = dY12 * dX + dX21 * dY;
    Fixed t = (c.getY() - a.getY()) * dX + (a.getX() - c.getX()) * dY;

    if (D < Fixed(0)) return s <= Fixed(0) && t <= Fixed(0) && s + t >= D;
    return s >= Fixed(0) && t >= Fixed(0) && s + t <= D;
}
