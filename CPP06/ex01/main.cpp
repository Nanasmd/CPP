/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:21:38 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:21:42 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

uintptr_t	serialize(Data* ptr)
{
	return	reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int		main(void)
{
	Data	ptr;
	ptr.str = "serialization";
	ptr.value = 1234;

	uintptr_t raw = serialize(&ptr);
	Data *deserial = deserialize(raw);
	std::cout << "---------serialize data------------" <<std::endl;
	std::cout << "str: " << ptr.str << std::endl;
	std::cout << "value: " << ptr.value << std::endl;
	std::cout << "ptr: " << &ptr << std::endl;
	std::cout << std::endl;
	std::cout << "---------deserialize data----------" <<std::endl;
	std::cout << "str: " << deserial->str << std::endl;
	std::cout << "value: " << deserial->value << std::endl;
	std::cout << "ptr: " << deserial << std::endl;
	return 0;
}