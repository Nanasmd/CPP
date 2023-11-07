/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:49:10 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 14:49:11 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// Constructors
		Cure(void);
		Cure(Cure const & src);
		~Cure(void);
		
		// Operators
		Cure & operator = (Cure const & src);
		
		// Member Functions
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
