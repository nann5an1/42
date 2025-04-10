/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:03:50 by nsan              #+#    #+#             */
/*   Updated: 2025/04/10 18:20:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
    // std::cout << a-- << std::endl;  
    // std::cout << --a << std::endl;
    // std::cout << Fixed::min( a, b ) << std::endl;
    // Fixed const c(Fixed( 10.10f ) + Fixed( 2 ));
    // Fixed const d(Fixed( 10.10f ) - Fixed( 20 ));
    // std::cout << "value of c: " << c << std::endl;
    // std::cout << "value of d: " << d << std::endl;
    // Fixed g,h,i, j, k;
    // g = b / a;
    // h = a + b;
    // h =  b + a;
    // i = h - b;
    // j = h * i;
    // k =  b / Fixed(0.0f);
    // a = a + b;
    // std::cout << "value of a: " << a << std::endl;
    // std::cout << "value of g: " << g << std::endl;
    // std::cout << "value of h: " << h << std::endl;
    // std::cout << "value of i: " << i << std::endl;
    // std::cout << "value of j: " << j << std::endl;
    // std::cout << "value of k: " << k << std::endl;
    return 0;
}