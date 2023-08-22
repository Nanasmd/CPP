/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:53:54 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:54:00 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int		main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* Wronganimal = new WrongAnimal();
	const WrongAnimal* Wrongcat = new WrongCat();
	std::cout << Wrongcat->getType() << " " << std::endl;
	Wrongcat->makeSound();
	Wronganimal->makeSound();

	delete meta;
	delete j;
	delete i;
	delete Wronganimal;
	delete Wrongcat;
}