/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:03:38 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:03:40 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: virtual public Animal{
public:
	Dog();
	~Dog();
	Dog(Dog const &src);
	Dog &operator=(Dog const &src);
	virtual void	makeSound() const;
	void setIdeas(int i, std::string idea);
	void printIdeas() const;
private:
	Brain *brain;
};

#endif