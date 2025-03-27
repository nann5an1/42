/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:07:30 by marvin            #+#    #+#             */
/*   Updated: 2025/03/20 18:07:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact{
    private:
        std::string _first;
        std::string _last;
        std::string _nick;
        std::string _phone;
        std::string _secret;
    public:
        void setFirstName(std::string first_n);
        void setLastName(std::string last_n);
        void setNickName(std::string nick_n);
        void setPhone(std::string phone);
        void setSecret(std::string secret);
        std::string getFirst();
        std::string getLast();
        std::string getNick();
        std::string getPhone();
        std::string getSecret();
        void addContent(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
};

#endif
