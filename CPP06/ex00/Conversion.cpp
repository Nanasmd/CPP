/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:19:39 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:19:41 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.hpp"

void	toChar(double value)
{
	std::cout << "char: ";

	if (value >= 32 && value < 127)
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else if (value < 0 || value > 127 || std::isnan(value) == 0)
		std::cout << "Non displayable" << std::endl;
	else if (std::isnan(value))
		std::cout << "impossible" << std::endl;
}

void	toInt(double value)
{
	std::cout << "int: ";

	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
		std::cout << static_cast<int>(value) << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	toFloat(double value)
{
	std::cout << "float: ";
	if (!std::isinf(value))
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	else if (std::isinf(value) || std::isnan(value))
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void	toDouble(double value)
{
	std::cout << "double: ";

	if (!std::isinf(value))
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value)<< std::endl;
	else if (std::isinf(value) || std::isnan(value))
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;

}

int		valueCheck(char *pEnd)
{
	if (!pEnd || !(*pEnd))
		return 0;
	int i = 1;
	while(pEnd[i])
	{
		if (!std::isspace(pEnd[i]))
			return 1;
		i++;
	}
	if (pEnd[0] != 'f')
		return 1;
	return 0;
}

void	stringConversion(char *argv)
{
	double value;
	char *pEnd;

	if (std::strlen(argv) == 1 && !std::isdigit(*argv))
		value = static_cast<double>(*argv);
	else {
		value = std::strtod(argv, &pEnd);
		if (valueCheck(pEnd))
		{
			std::cout << "input value Error" << std::endl;
			return;
		}
	}
	toChar(value);
	toInt(value);
	toFloat(value);
	toDouble(value);
}