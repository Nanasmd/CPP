/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:39:49 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/09 15:16:17 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Not found");
		}
};

template <typename T>
void easyfind(T const &container, int value)
{
	typename T::const_iterator it;
	
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	else
		std::cout << "\t" << "Found " << *it << std::endl;
}
