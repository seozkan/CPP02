/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:13:03 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/12 14:14:06 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
    if (LOG)
        std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const Fixed &fixed)
{
    if (LOG)
        std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int n) : _n(n << _m)
{
    if (LOG)
        std::cout << "Int constructor called" << std::endl;
    return;
}

Fixed::Fixed(const float f) : _n((int)roundf(f * (1 << _m)))
{
    if (LOG)
        std::cout << "Float constructor called" << std::endl;
    return;
}

Fixed::~Fixed()
{
    if (LOG)
        std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (LOG)
        std::cout << "Assignation operator called" << std::endl;
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
    if (LOG)
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

bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->_n > fixed._n);
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->_n < fixed._n);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->_n >= fixed._n);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->_n <= fixed._n);
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->_n == fixed._n);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->_n != fixed._n);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed &Fixed::operator++(void)
{
    ++(this->_n);
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    --(this->_n);
    return (*this);
}

Fixed Fixed::operator++(int n)
{
    Fixed temp(*this);

    if (n >= 0)
    {
        for (int i = 0; i <= n; i++)
            ++(*this);
    }
    else
    {
        for (int i = 0; i <= (-n); i++)
            --(*this);
    }
    return (temp);
}

Fixed Fixed::operator--(int n)
{
    Fixed temp(*this);

    if (n >= 0)
    {
        for (int i = 0; i <= n; i++)
            --(*this);
    }
    else
    {
        for (int i = 0; i <= (-n); i++)
            ++(*this);
    }
    return (temp);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    if (LOG)
        std::cout << "Static min function called" << std::endl;
    if (fixed1 <= fixed2)
        return (fixed1);
    return (fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    if (LOG)
        std::cout << "Static max function called" << std::endl;
    if (fixed1 >= fixed2)
        return (fixed1);
    return (fixed2);
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
    if (LOG)
        std::cout << "Static const min overload called" << std::endl;
    if (fixed1 <= fixed2)
        return (fixed1);
    return (fixed2);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
    if (LOG)
        std::cout << "Static const max overload called" << std::endl;
    if (fixed1 >= fixed2)
        return (fixed1);
    return (fixed2);
}