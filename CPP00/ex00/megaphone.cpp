/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:23:14 by nsan              #+#    #+#             */
/*   Updated: 2025/03/26 17:23:14 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv){
    const char *def = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    if (argc > 1){
        for(int count = 1; count < argc; count++){
            for(char *arg = argv[count] ;*arg; arg++)
                std::cout <<  (char)(std::toupper((int)(*arg)));
        }
    }
    else
        std::cout << def;
    std::cout << std::endl;
    return (0);
}