/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:37:46 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/08 14:13:02 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <limits>
#include <iomanip>
#include <cmath>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define PURPLE	"\033[35m"
#define PINK		"\e[0;38;5;199m"
#define LILAC		"\e[0;38;5;13m"
#define BOLD_RED	"\e[1;31m"
#define V_CYAN		"\e[0;38;5;44m"

#define NAN_INF	1
#define ERROR	2
#define CHAR	3
#define INT		4
#define FLOAT	5
#define DOUBLE	6

#define SIGNAL		"+-"
#define DIGIT_SET	"+-0123456789"
#define DOUBLE_SET	"+-0123456789."
#define FLOAT_SET	"+-0123456789.f"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();

		static int parseInput(std::string const &input);

		static void fromChar(int type, std::string const &input);
		static void fromInt(int type, std::string const &input);
		static void fromFloat(int type, std::string const &input);
		static void fromDouble(int type, std::string const &input);

		static void print(int type, std::string const &input, char c, int i, float f, double d);

	public:
		static void convert(std::string const &input);
};
