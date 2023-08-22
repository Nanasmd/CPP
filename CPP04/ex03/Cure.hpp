/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:06:06 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:06:08 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "ICharacter.hpp" 

class Cure: public AMateria
{
public:
	Cure();
	~Cure();
	Cure(Cure const &src);
	Cure &operator=(Cure const &src);
	AMateria* clone() const;
	void use(ICharacter& target);
};
#endif