/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:04:36 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/09 20:33:34 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _n;
    static const int _m = 8;

public:
    Fixed();
    Fixed(Fixed &fixed);
    ~Fixed();
    Fixed &operator=(Fixed &fixed);

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif