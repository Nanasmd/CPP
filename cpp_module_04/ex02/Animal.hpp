/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:21:13 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 14:21:14 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		// Constructors
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);
		
		// Operators
		Animal &operator=(Animal const &src);

		// Getters and Setters
		std::string getType(void) const;
		void setType(std::string const type);
	
		// Member functions
		virtual void makeSound(void) const = 0;
};

#endif
