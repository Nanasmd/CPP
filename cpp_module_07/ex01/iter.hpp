/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:39:21 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/14 13:32:06 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
void printContent(T const &content) {
	std::cout << content << std::endl;
}

template <typename T, typename F>
void iter(T *array, int size, F f) {
	for (int i = 0; i < size; i++)
		f(array[i]);
}
