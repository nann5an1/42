/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:05:51 by marvin            #+#    #+#             */
/*   Updated: 2025/03/20 18:05:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void Contact :: AddContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret){
    PhoneBook phonebook;

    content_arr[0] = first;
    content_arr[1] = last;
    content_arr[2] = nick;
    content_arr[3] = phone;
    content_arr[4] = secret;
    phonebook.addcontent(content_arr);
    // std::cout << first << content_arr[4];
}
