/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:21:12 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:21:13 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP
# include <iostream>

struct Data
{
	std::string	str;
	int			value;
};

uintptr_t	serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif