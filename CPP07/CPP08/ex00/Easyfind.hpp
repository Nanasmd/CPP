/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:28:17 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:28:19 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <iterator>
# include <algorithm>
# include <vector>
# include <list>

template<typename T>
int	 easyfind(T &container, int i)
{
	typename T::iterator it = std::find(container.begin(), container.end(), i);

	if (it == container.end())
		throw std::exception();
	return *it;
}

#endif