/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:51:11 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/12 14:52:32 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();
    Point(const Point &point);
    Point(const float &x, const float &y);
    ~Point();
    Point &operator=(const Point &point);
    float getX(void) const;
    float getY(void) const;
    static float signThree(const Point &a, const Point &b, const Point &c);
};

std::ostream &operator<<(std::ostream &o, const Point &point);
bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif
