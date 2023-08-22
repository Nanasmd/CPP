/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:01:50 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:02:06 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor called." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called." << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy Constructor called." << std::endl;
	*this = src;
}

Brain &Brain::operator=(Brain const &src)
{
	std::cout << "Brain equal operator called." << std::endl;
	if (this != &src)
	{
		for (int i = 0;i < 100; i++)
			ideas[i] = src.ideas[i];
	}
	return *this;
}

void Brain::setIdeas(int i, std::string idea)
{
	ideas[i] = idea;
}

void Brain::printIdeas(void) const
{
	for (int i = 0 ; i < 100; i++)
		if (ideas[i].length())
			std::cout << "print[" << i << "] => "<< ideas[i] << std::endl;
}