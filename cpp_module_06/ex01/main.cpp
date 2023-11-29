/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:38:03 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/08 13:31:23 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

void	mainHeader() 
{
	std::cout << "\033c";
	std::cout << PINK << "********************************************" << RESET << std::endl;
	std::cout << PINK << "*         nasamadi's C++ SERIALIZER        *" << RESET << std::endl;
	std::cout << PINK << "********************************************" << RESET << std::endl << std::endl;
}

void	pressEnter(void)
{
	std::cout << std::endl << GREEN << "press ENTER to continue" << RESET << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void titleHeader(const std::string& message)
{
    std::cout << "\033c";
	mainHeader();
    int standardSize = 34;
    int messageSize = message.length();
    int spaces = (standardSize - messageSize) / 2;

    std::cout << LILAC << "************************************" << std::endl << "*" << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << LILAC << message << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << LILAC << "*" << std::endl << "************************************" << RESET << std::endl;
}

int	main()
{
	titleHeader("CREATE DATA STRUCTS");
	Data player1;
	Data player2;
	Data player3;

	player1.name = "Harry Potter";
	player1.age = 31;
	player1.next = &player2;

	player2.name = "Drago Malfoy";
	player2.age = 30;
	player2.next = &player3;

	player3.name = "Hermione Granger";
	player3.age = 30;
	player3.next = NULL;

	std::cout << YELLOW << "===== player 1 =====" << RESET << std::endl << std::endl;
	std::cout << "address: " << &player1 << std::endl;
	std::cout << "name   : " << player1.name << std::endl;
	std::cout << "age    : " << player1.age << std::endl;
	std::cout << "next   : " << player1.next << std::endl << std::endl;

	std::cout << YELLOW << "===== player 2 =====" << RESET << std::endl << std::endl;
	std::cout << "address: " << &player2 << std::endl;
	std::cout << "name   : " << player2.name << std::endl;
	std::cout << "age    : " << player2.age << std::endl;
	std::cout << "next   : " << player2.next << std::endl << std::endl;

	std::cout << YELLOW << "===== player 3 =====" << RESET<< std::endl << std::endl;
	std::cout << "address: " << &player3 << std::endl;
	std::cout << "name   : " << player3.name << std::endl;
	std::cout << "age    : " << player3.age << std::endl;
	std::cout << "next   : " << player3.next << std::endl;

	pressEnter();

	titleHeader("SERIALIZE PLAYER 1");
	uintptr_t serializedPlayer1 = Serializer::serialize(&player1);

	std::cout << YELLOW << "===== player 1 =====" << RESET << std::endl << std::endl;
	std::cout << "Original address  : " << &player1 << std::endl;
	std::cout << "serialized address: " << serializedPlayer1 << std::endl;
	std::cout << std::endl;

	std::cout << "Original name   : " << player1.name << std::endl;
	std::cout << "Deserialize name: " << Serializer::deserialize(serializedPlayer1)->name << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player1.name == Serializer::deserialize(serializedPlayer1)->name)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << std::endl;

	std::cout << "Original age   : " << player1.age << std::endl;
	std::cout << "Deserialize age: " << Serializer::deserialize(serializedPlayer1)->age << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player1.age == Serializer::deserialize(serializedPlayer1)->age)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << std::endl;

	std::cout << "Original next   : " << player1.next << std::endl;
	std::cout << "Deserialize next: " << Serializer::deserialize(serializedPlayer1)->next << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player1.next == Serializer::deserialize(serializedPlayer1)->next)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;

	pressEnter();

	titleHeader("SERIALIZE PLAYER 2");

	uintptr_t serializedPlayer2 = Serializer::serialize(&player2);

	std::cout << YELLOW << "===== player 2 =====" << RESET << std::endl << std::endl;
	std::cout << "Original address  : " << &player2 << std::endl;
	std::cout << "serialized address: " << serializedPlayer2 << std::endl;
	std::cout << std::endl;

	std::cout << "Original name   : " << player2.name << std::endl;
	std::cout << "Deserialize name: " << Serializer::deserialize(serializedPlayer2)->name << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player2.name == Serializer::deserialize(serializedPlayer2)->name)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << std::endl;

	std::cout << "Original age   : " << player2.age << std::endl;
	std::cout << "Deserialize age: " << Serializer::deserialize(serializedPlayer2)->age << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player2.age == Serializer::deserialize(serializedPlayer2)->age)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << std::endl;

	std::cout << "Original next   : " << player2.next << std::endl;
	std::cout << "Deserialize next: " << Serializer::deserialize(serializedPlayer2)->next << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player2.next == Serializer::deserialize(serializedPlayer2)->next)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	
	pressEnter();

	titleHeader("SERIALIZE PLAYER 3");

	uintptr_t serializedPlayer3 = Serializer::serialize(&player3);

	std::cout << YELLOW << "===== player 3 =====" << RESET<< std::endl << std::endl;
	std::cout << "Original address  : " << &player3 << std::endl;
	std::cout << "serialized address: " << serializedPlayer3 << std::endl;
	std::cout << std::endl;

	std::cout << "Original name   : " << player3.name << std::endl;
	std::cout << "Deserialize name: " << Serializer::deserialize(serializedPlayer3)->name << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player3.name == Serializer::deserialize(serializedPlayer3)->name)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << std::endl;

	std::cout << "Original age   : " << player3.age << std::endl;
	std::cout << "Deserialize age: " << Serializer::deserialize(serializedPlayer3)->age << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player3.age == Serializer::deserialize(serializedPlayer3)->age)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << std::endl;

	std::cout << "Original next   : " << player3.next << std::endl;
	std::cout << "Deserialize next: " << Serializer::deserialize(serializedPlayer3)->next << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player3.next == Serializer::deserialize(serializedPlayer3)->next)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;

	pressEnter();
}
