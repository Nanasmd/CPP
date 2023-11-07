/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:23:23 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 14:23:24 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string	type;
	
	public:
		// Constructors
		AMateria(void);
		AMateria(std::string const & type);
		virtual ~AMateria(void);

		// Getters
		std::string const & getType() const;

		// Member Functions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
