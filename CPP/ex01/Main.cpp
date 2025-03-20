/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:13:57 by marvin            #+#    #+#             */
/*   Updated: 2025/03/20 18:13:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string.h>

int prompt_contact_add(){
    Contact contact;
    std::string first;
    std::string last;
    std::string nick;
    std::string phone;
    std::string secret;

    std::cout << "First Name >> ";
    std::getline(std::cin, first);
    // if(first.empty()) return (1);

    std::cout << "Last Name >> ";
    std::getline(std::cin, last);
    // if(last.empty()) return (1);

    std::cout << "Nick Name >> ";
    std::getline(std::cin, nick);
    // if(nick.empty()) return (1);

    std::cout << "Phone Number >> ";
    std::getline(std::cin, phone);
    // if(phone.empty()) return (1);

    std::cout << "Darkest Secret >> ";
    std::getline(std::cin, secret);
    // if(secret.empty()) return (1);
    
    contact.AddContact(first, last, nick, phone, secret);
    return (0);
}

int main(int argc, char **argv){
    PhoneBook pb;
    while(1)
    {
        if (strcmp(argv[1], "ADD"))
            prompt_contact_add();
        else if(strcmp(argv[1], "EXIT"))    
            return (1);
                // return (std::cout << "Empty Field NOT Allowed" << std::endl, 1);
    }
    return (0);
}