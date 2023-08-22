/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:25:14 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:25:16 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename T>
void	swap(T &x, T &y) {
	T temp;

	temp = x;
	x = y;
	y = temp;
}

template <typename T>
T min(T const x, T const y) {
	if (x < y)
		return x;
	return y;
}

template <typename T>
T max(T const x, T const y) {
	if (x > y)
		return x;
	return y;
}
#endif