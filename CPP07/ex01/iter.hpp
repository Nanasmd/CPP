/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:25:55 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:25:57 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <cstring>

template <typename T>
void	execute(T const &var){
		std::cout << var;
}

template <typename T>
void	iter(T *addr, int len, void (*func)(T const &var)) {
	for(int i = 0 ;i < len; i++){
		(*func)(addr[i]);
		if (i + 1 == len)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}
}

#endif