/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:52:44 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:52:51 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat: public Animal{
public:
	Cat();
	~Cat();
	Cat(Cat const &src);
	Cat &operator=(Cat const &src);
	virtual void	makeSound() const;
};

#endif