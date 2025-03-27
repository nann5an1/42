/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:25:10 by nsan              #+#    #+#             */
/*   Updated: 2025/03/25 18:25:10 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string.h>


int promptInput(std::string prompt, std::string &input){
    while(input.empty())
    {
    std::cout << prompt; 
    std::getline(std::cin, input);
    if(std::cin.eof())
        return (1);
    }
    return (0);
}


int prompt_contact_add(PhoneBook &phonebook){
    Contact contact;
    std::string first, last, nick, phone, secret;

    if(promptInput("First Name >> ", first) || promptInput("Last Name >> ", last) || promptInput("NickName >> ", nick) \
    || promptInput("Phone Number >> ", phone) || promptInput("Darkest Secret >> ", secret))
        return (1);
    
    contact.addContent(first, last, nick, phone, secret);
    phonebook.addContact(contact);
    return (0);
}


int main(){
    PhoneBook phonebook;
    std::string num;
    std::string input;
    std::string index_input;
    std::cout <<  std::string(44, '-') << std::endl
                << std::string(14, '*')
                <<"NSAN'S PHONEBOOK" 
                << std::string(14, '*') << std::endl
                << std::string(44, '-') << std::endl;
    while (1){
            std::cout <<  "\n=== What would you like to do? ===" << std::endl;
            std::cout << "> ADD\n> SEARCH\n> EXIT\n" << std::endl;
            std::cout << "> ";
            std::getline(std::cin, input);
            if(std::cin.eof())
                return (1);
            if (input == "ADD"){
                std::cout << std::endl;
                if (prompt_contact_add(phonebook))
                    return (1);
            }
            else if(input == "SEARCH")
            {
                phonebook.displayPhoneBook();
                std::cout << std::string(56, '*');
                std::cout << "\n\n----Enter the index for full information.----\n";
                std::cout << "> ";
                std::getline(std::cin, index_input);
            
                if (index_input.length() == 1 && isdigit(index_input[0])) {
                    phonebook.index = index_input[0] - '0';
                    if(phonebook.index > 0 && phonebook.index < 9)
                        phonebook.displayContact();
                    else
                        std::cout << "Index must be from within the range [1-8]\n";
                } else {
                    std::cout << "Invalid index!\n";
                }
            }
            else if(input == "EXIT")
                return (1);
        }
    return (0);
}
