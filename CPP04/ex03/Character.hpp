/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:05:33 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:05:39 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#define SLOTS 4

class Character: public ICharacter
{
	private:
		std::string		name;
		AMateria		*inven[SLOTS];
	public:
		Character();
		~Character();
		Character(std::string const _name);
		Character &operator=(Character const &src);
		Character(Character const &src);

	 	std::string const & getName() const;
	 	void equip(AMateria* m);
	 	void unequip(int idx);
	 	void use(int idx, ICharacter& target);
};

#endif