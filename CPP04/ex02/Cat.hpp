/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:02:58 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:03:06 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal{
public:
	Cat();
	~Cat();
	Cat(Cat const &src);
	Cat &operator=(Cat const &src);
	virtual void	makeSound() const;
	void setIdeas(int i, std::string idea);
	void printIdeas() const;
private:
	Brain *brain;
};

#endif