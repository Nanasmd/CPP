/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:22:13 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 14:55:37 by nasamadi         ###   ########.fr       */
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
	titleHeader("INITIALIZE DEFINED OBJECTS");
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound();
	j->makeSound();
	
	delete j;
	delete i;
	pressEnter();

	titleHeader("INITIALIZE ABSTRACT OBJECTS");
	std::cout << "You can't initialize an abstract object." << std::endl;
	// Animal test;
	pressEnter();

	titleHeader("ANIMAL ARRAY TEST");

	Animal	*animals[6] =
	{
		new Dog(), new Dog(), new Dog(),
		new Cat(), new Cat(), new Cat()
	};

	for (int i = 0; i < 6; i++)
	{
		std::cout << std::endl << "Destroy Animal " << i + 1 << std::endl;	
		delete animals[i];
	}
	pressEnter();

	titleHeader("BASIC COPY TEST");
	{
		Dog basic;
		Dog tmp = basic;
		
		std::cout << std::endl << "Basic's Brain Adress: " << basic.getBrain() << std::endl;
		std::cout << "Tmp's Brain Adress  : " << tmp.getBrain() << std::endl << std::endl;
	}
	pressEnter();

	titleHeader("CAT DEEP COPY TEST");
	Cat *original = new Cat();
	Cat *copy = new Cat(*original);

	std::cout << std::endl << "Original's Brain Adress: " << original->getBrain() << std::endl;
	original->getBrain()->showIdeas();
	delete original;
	
	std::cout << std::endl << "Copy's Brain Adress: " << copy->getBrain() << std::endl;
	copy->getBrain()->showIdeas();
	delete copy;
	pressEnter();
	
	titleHeader("DOG DEEP COPY TEST");
	Dog *originalDog = new Dog();
	Dog *copyDog = new Dog(*originalDog);
	
	std::cout << std::endl << "Original's Brain Adress: " << originalDog->getBrain() << std::endl;
	originalDog->getBrain()->showIdeas();
	delete originalDog;

	std::cout << std::endl << "Copy's Brain Adress: " << copyDog->getBrain() << std::endl;
	copyDog->getBrain()->showIdeas();
	delete copyDog;
	pressEnter();
}
