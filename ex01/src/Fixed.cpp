/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:36:12 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/11 10:53:25 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int i) : _n(i << _m)
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(const float f) : _n((int)roundf(f * (1 << _m)))
{
	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_n = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_n);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_n / (1 << _m));
}

int Fixed::toInt(void) const
{
	return ((int)(roundf((float)_n / (1 << _m))));
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}