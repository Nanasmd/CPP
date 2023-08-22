/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:53:15 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:53:22 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog: public Animal{
public:
	Dog();
	~Dog();
	Dog(Dog const &src);
	Dog &operator=(Dog const &src);
	virtual void	makeSound() const;
};

#endif