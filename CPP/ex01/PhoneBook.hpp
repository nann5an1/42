/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:25:37 by nsan              #+#    #+#             */
/*   Updated: 2025/03/25 18:25:37 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook{ //class declaration
    private:
        Contact _contact_arr[8];
        int _index;
        void printOut(int index, int flag);
    public:
        PhoneBook() : _index(0){};
        int index;
        void addContact(Contact contact);
        void displayPhoneBook();
        void displayContact();
};

#endif