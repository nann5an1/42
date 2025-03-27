/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:25:20 by nsan              #+#    #+#             */
/*   Updated: 2025/03/25 18:25:20 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact(Contact contact){
   if(_index == 8)
      _index = 0;
   _contact_arr[_index] = contact;
   _index++;
}


void PhoneBook::printOut(int i, int flag){
   if(!_contact_arr[i].getFirst().empty()){
      std::cout
      << std::setw(10) << i + 1 << '|'
      << std::setw(10) << (_contact_arr[i].getFirst().length() > 10 ? _contact_arr[i].getFirst().substr(0, 9) + '.' :  _contact_arr[i].getFirst()) <<  '|'
      << std::setw(10) << (_contact_arr[i].getLast().length() > 10 ? _contact_arr[i].getLast().substr(0, 9) + '.' :  _contact_arr[i].getLast()) <<  '|'
      << std::setw(10) << (_contact_arr[i].getNick().length() > 10 ? _contact_arr[i].getNick().substr(0, 9) + '.' :  _contact_arr[i].getNick());
      if (flag == 0) {
      std::cout << '|' 
               << std::setw(10) 
               << (_contact_arr[i].getPhone().length() > 10 ? _contact_arr[i].getPhone().substr(0, 9) + '.' :  _contact_arr[i].getPhone()) 
               << '\n';
      } 
      else {
      std::cout << '|' << std::setw(10) 
               << (_contact_arr[i].getPhone().length() > 10 ? _contact_arr[i].getPhone().substr(0, 9) + '.' :  _contact_arr[i].getPhone()) 
               << '|';
      std::cout << std::setw(10) 
               << (_contact_arr[i].getSecret().length() > 10 ? _contact_arr[i].getSecret().substr(0, 9) + '.' :  _contact_arr[i].getSecret()) 
               << '\n';
      }
   }
   else
      std::cout << "\n  Index doesn't exist. Try Again!\n";
}

void PhoneBook::displayPhoneBook(){
   if(!_contact_arr[0].getFirst().empty()){
      std::cout << std::string(56, '*') << std::endl;
      std::cout
               << std::setw(10) << "Index" << '|'
               << std::setw(10) << "FirstName" << '|'
               << std::setw(10) << "LastName" << '|'
               << std::setw(10) << "NickName" << '|'
               << std::setw(10) << "Phone Num\n";
      std::cout << std::string(56, '*') << std::endl;
      for(int i = 0; i < 8; i++){
         if(_contact_arr[i].getFirst().empty())
            break;
         printOut(i, 0);
      }
   }
   else
      std::cout << "No contacts in the phonebook! Add some contacts.\n";
}


void PhoneBook::displayContact(){
   if(!_contact_arr[index - 1].getFirst().empty()){
      std::cout << std::string(72, '-') << std::endl;
      std::cout
               << std::setw(10) << "Index" << '|'
               << std::setw(10) << "First Name" << '|'
               << std::setw(10) << "Last Name" << '|'
               << std::setw(10) << "NickName" << '|'
               << std::setw(10) << "Phone Num:" << '|'
               << std::setw(10) << "Darkest Secr:\n";
      std::cout << std::string(72, '-') << std::endl;
   }
   printOut(index - 1, 1);
}

