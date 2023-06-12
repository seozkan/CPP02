/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:50:53 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/12 14:11:08 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    float s1, s2, s3;

    s1 = Point::signThree(point, a, b);
    s2 = Point::signThree(point, b, c);
    s3 = Point::signThree(point, c, a);

    return ((s1 < 0 && s2 < 0 && s3 < 0) || (s1 > 0 && s2 > 0 && s3 > 0));
}