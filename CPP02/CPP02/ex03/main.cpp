/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:03:50 by nsan              #+#    #+#             */
/*   Updated: 2025/04/11 13:55:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point a(0, 1);
    Point b(0, 10);
    Point c(1, 5);
    Point point(1, 15);
    Point obj;
    bool result = obj.bsp(a, b, c, point);
    std::cout << result << std::endl;
    return 0;
}