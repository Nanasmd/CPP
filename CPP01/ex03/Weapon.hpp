/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:42:51 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/17 22:42:58 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_WEAPON_HPP_
# define EX03_WEAPON_HPP_

#include <string>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon();

		void setType(std::string type);
		std::string getType() const;

	private:
		std::string _type;
};

#endif