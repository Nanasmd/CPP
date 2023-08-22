/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:19:54 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:19:56 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP
# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <cstring>
# include <cctype>
# include <iomanip>

void		stringConversion(char *argv);
void		toChar(std::string value);
void		toInt(std::string value);
void		toFloat(std::string value);
void		toDouble(std::string value);
#endif