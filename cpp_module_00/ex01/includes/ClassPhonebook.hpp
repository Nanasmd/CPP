/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:14:59 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/10 16:42:31 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSPHONEBOOK_HPP
# define CLASSPHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "ClassContacts.hpp"

#define RESET		"\e[0m"
#define PINK		"\e[0;38;5;199m"
#define LILAC		"\e[0;38;5;13m"
#define PURPLE		"\e[0;38;5;93m"
#define BOLD_RED	"\e[1;31m"
#define BLUE		"\e[0;34m"
#define V_CYAN		"\e[0;38;5;44m"

class Phonebook
{
	public:

		Phonebook();
		~Phonebook();

		Contacts	contact[8];
};

/*
** main.cpp
*/
int			main(void);
std::string	print_welcome_message(std::string command);

/*
** add.cpp
*/
Contacts	add_new_contact(void);

/*
** search.cpp
*/
void		show_all_contacts(Contacts contact[8], int num_contacts);
void		choose_contact(Contacts contact[8], int num_contacts);
void		print_contacts(int id, std::string first_name,
				std::string last_name, std::string nickname);
std::string	trim(std::string info);

#endif
