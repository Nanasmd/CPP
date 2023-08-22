/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:54:12 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:54:18 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
public:
	WrongCat();
	~WrongCat();
	WrongCat(WrongCat const &src);
	WrongCat &operator=(WrongCat const &src);
	virtual void	makeSound() const;
};

#endif