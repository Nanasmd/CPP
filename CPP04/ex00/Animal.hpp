/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:51:55 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:52:00 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class Animal{
protected:
	std::string type;

public:
	Animal();
	virtual ~Animal(void);
	Animal(Animal const &src);
	Animal &operator=(Animal const &src);
	std::string getType() const;
	virtual void	makeSound() const;
};

#endif