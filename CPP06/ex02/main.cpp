/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:23:48 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:23:50 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	std::srand(std::time(NULL));
	int random = std::rand() % 3;
	Base *base = NULL;

	switch (random)
	{
	case 0:
		base = new A;
		std::cout << "A class generate." << std::endl;
		break;
	case 1:
		base = new B;
		std::cout << "B class generate." << std::endl;
		break;
	case 2:
		base = new C;
		std::cout << "C class generate." << std::endl;
		break;
	}
	return base;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A Pointer identify." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B Pointer identify." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C Pointer identify." << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A Reference identify." << std::endl;
	}
	catch(const std::exception& e){ }

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B Reference identify." << std::endl;
	}
	catch(const std::exception& e){ }

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C Reference identify." << std::endl;
	}
	catch(const std::exception& e){ }	
}

int		main(void)
{
	std::cout << "------------base generate------------" << std::endl;
	Base *base = generate();
	std::cout << "------------base pointer-------------" << std::endl;
	identify(base);
	std::cout << "------------base reference-----------" << std::endl;
	identify(*base);
	delete base;
	return 0;
}