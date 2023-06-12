/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:51:02 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/12 14:47:49 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

int main(void)
{
    Point a(2, 0);
    Point b(4, 2);
    Point c(6, 0);
    Point p1(1, 1);
    Point p2(4, 1);

    std::cout << "a" << a << " b" << b << " c" << c << std::endl;
    std::cout << "Is p1" << p1 << " in (a,b,c) ? " << std::boolalpha << bsp(a, b, c, p1) << std::endl;
    std::cout << "Is p2" << p2 << " in (a,b,c) ? " << std::boolalpha << bsp(a, b, c, p2) << std::endl;
    std::cout << "Is a" << a << " in (a,b,c) ? " << std::boolalpha << bsp(a, b, c, a) << std::endl;
    return 0;
}
