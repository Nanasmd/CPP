/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:49:39 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 14:49:40 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <cstring>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*storage[4];
		int			storageCount;	
	
	public:
		// Constructors
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		~MateriaSource(void);

		// Operators
		MateriaSource & operator = (MateriaSource const & src);

		// Member Functions
		void	learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif
