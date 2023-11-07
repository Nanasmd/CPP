/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:37:02 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 14:54:44 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	mainHeader() 
{
	std::cout << "\033c";
	std::cout << "*****************************************" << std::endl;
	std::cout << "*         nasamadi's C++ ANIMALS        *" << std::endl;
	std::cout << "*****************************************" << std::endl << std::endl;
}

void	pressEnter(void)
{
	std::cout << std::endl << "press ENTER to continue" << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void titleHeader(const std::string& message)
{
    std::cout << "\033c";
	mainHeader();
    int standartSize = 34;
    int messageSize = message.length();
    int spaces = (standartSize - messageSize) / 2;

    std::cout << "************************************" << std::endl << "*";
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << message;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << "*" << std::endl << "************************************" << std::endl << std::endl;
}

int main()
{
	titleHeader("SUBJECT TEST");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
	pressEnter();

	titleHeader("COPY TEST");
	const Animal *original = new Dog();
	const Animal *pointToOriginal = original;

	std::cout << pointToOriginal->getType() << std::endl;
	pointToOriginal->makeSound();

	const Dog *otherOriginal = new Dog();
	const Dog *newCopy = new Dog(*otherOriginal);

	std::cout << otherOriginal->getType() << std::endl;
	otherOriginal->makeSound();

	std::cout << newCopy->getType() << std::endl;
	newCopy->makeSound();

	delete original;
	delete otherOriginal;
	delete newCopy;
	pressEnter();

	titleHeader("WRONG ANIMAL TEST");
	const WrongAnimal* cat = new WrongCat();
	cat->makeSound();
	delete cat;
}
