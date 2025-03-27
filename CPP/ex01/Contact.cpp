/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:18:56 by nsan              #+#    #+#             */
/*   Updated: 2025/03/25 17:18:56 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string first_n){
    _first = first_n;
}

std::string Contact::getFirst(){
    return (_first);
}

void Contact::setLastName(std::string last_n){
    _last = last_n;
}
std::string Contact::getLast(){
    return (_last);
}

void Contact::setNickName(std::string nick_n){
    _nick = nick_n;
}
std::string Contact:: getNick(){
    return (_nick);
}

void Contact::setPhone(std::string phone_num){
    _phone = phone_num;
}
std::string Contact:: getPhone(){
    return (_phone);
}

void Contact::setSecret(std::string secret){
    _secret = secret;
}
std::string Contact:: getSecret(){
    return (_secret);
}

void Contact :: addContent(std::string first, std::string last, std::string nick, std::string phone, std::string secret){
    _first = first;
    _last = last;
    _nick = nick;
    _phone = phone;
    _secret = secret;
}
