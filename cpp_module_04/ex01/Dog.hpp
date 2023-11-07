/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:20:20 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 14:20:21 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
		
	public:
		// Constructors
		Dog(void);
		Dog(Dog const &src);	
		virtual ~Dog(void);
		
		// Operators
		Dog &operator=(Dog const &src);

		// Member functions
		void makeSound(void) const;

		// Getters
		Brain *getBrain(void) const;
};

#endif
