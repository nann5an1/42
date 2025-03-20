/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:21:48 by marvin            #+#    #+#             */
/*   Updated: 2025/03/20 17:21:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// PhoneBook::PhoneBook(){ //initalize the constructor
//     str1 = "hello";
//     str2 = "world";
// }


void PhoneBook::addcontent(std::string content_arr[5])
{
    int isempty = 1; //is considered full
    for(int i = 0; i < 8; i++){
        if((phonecontacts[i][0]).empty()){
            isempty = 0;
            for(int j = 0; j < 5; j++)
                phonecontacts[i][j] = content_arr[j];
            break;
        }
    }
    if(isempty){
        for(int j = 0; j < 5; j++)
            phonecontacts[0][j] = content_arr[j];
    }
    PbDisplay();
}

void PhoneBook::PbDisplay() {
    for (int i = 0; i < 8; i++) {
        if (phonecontacts[i][0].empty()) break;
        for (int j = 0; j < 5; j++) {
            std::cout << phonecontacts[i][j]; 
            if (j < 4) std::cout << " | ";
        }
        std::cout << std::endl;
    }
}



// int main(int argc, char **argv){
//     (void)argc;
//     PhoneBook pb; //initialize object
//     // pb.display( argv[1]);
//     std::cout << pb.str1 << pb.str2;
// }