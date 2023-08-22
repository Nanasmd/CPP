/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:03:46 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:03:52 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int		main()
{
	std::cout << "memory Leak" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "array animal" << std::endl;
	int n = 8;
	Animal *animals[n];

	for (int i = 0 ;i < n ;i++){
		std::cout << "[" << i << "] create ::";
		if (i < n / 2){
			std::cout << "Cat ";
			animals[i] = new Cat();
			animals[i]->makeSound();
		}
		else{
			std::cout << "Dog ";
			animals[i] = new Dog();
			animals[i]->makeSound();
		}
	}
	for (int i = 0 ;i < n ;i++)
	{
		std::cout << "[" << i << "] delete ::";
		delete animals[i];
	}
	std::cout << std::endl;
	std::cout << "Cat or Dog copy deep" << std::endl;
	Cat cat;
	Dog dog;
	Cat copycat = cat;
	Dog copydog = dog;
	Cat deepcat(copycat);
	Dog deepdog(copydog);
	deepcat.setIdeas(0, "hi!");
	deepcat.setIdeas(1, "im cat!");
	deepcat.setIdeas(2, "bye!!");
	deepcat.printIdeas();

	deepdog.setIdeas(0, "hi!");
	deepdog.setIdeas(1, "im dog!");
	deepdog.setIdeas(2, "bye!!");
	deepdog.printIdeas();
}