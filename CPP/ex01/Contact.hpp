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
    public:
        void AddContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
    private:
        char col_width[10];
        std::string content_arr[5];
};

#endif

// char *first, char *last, char *nick, char *phone, char *secret