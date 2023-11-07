/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:49:17 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 14:49:18 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// Constructors
		Ice(void);
		Ice(Ice const & src);
		~Ice(void);

		// Operators
		Ice & operator = (Ice const & src);
		
		// Member Functions
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
