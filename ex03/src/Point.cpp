/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:51:06 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/12 14:31:40 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	return;
}

Point::Point(const Point &point) : _x(point._x), _y(point._y)
{
	return;
}

Point::Point(const float &floatX, const float &floatY) : _x(Fixed(floatX)), _y(Fixed(floatY))
{
	return;
}

Point::~Point()
{
	return;
}

Point &Point::operator=(const Point &point)
{
	(void)point;

	return (*this);
}

float Point::signThree(const Point &a, const Point &b, const Point &c)
{
	Fixed fixed;

	fixed = (a._x - c._x) * (b._y - c._y) - (b._x - c._x) * (a._y - c._y);
	return (fixed.toFloat());
}

float Point::getX(void) const
{
	return (this->_x.toFloat());
}

float Point::getY(void) const
{
	return (this->_y.toFloat());
}

std::ostream &operator<<(std::ostream &o, const Point &point)
{
	o << "(" << point.getX() << "," << point.getY() << ")";
	return (o);
}