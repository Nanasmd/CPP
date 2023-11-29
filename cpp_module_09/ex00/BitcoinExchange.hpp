/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:40:57 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/30 00:08:17 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <climits>
#include <stdexcept>

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

// Définitions des ensembles de caractères pour la validation des entrées
#define SIGNAL		"+-"
#define VALID_SET	"+-0123456789."
#define DATE_SET	"-0123456789"
#define SPACES_SET	" \t\n\r\f\v"

#define DB_IS_LARGER	1
#define IN_IS_LARGER	-1
#define EQUAL			0

struct btcPrice
{
	std::tm		date;
	float		price;
	float		amount;
};

// Déclaration du type pour stocker les prix Bitcoin.
typedef std::map<std::string, float> BitcoinDatabase;

// Déclarations des fonctions.
std::string trim(const std::string &str);
BitcoinDatabase getDatabase();

bool 	isValidNumber(const std::string &in);
bool 	isLeapYear(int year);
bool 	isValidDate(const std::string &date, std::string &errorMessage);
bool 	isValidValue(const std::string &in, std::string &errorMessage);
bool 	isValidAmount(const std::string &in, std::string &errorMessage);
float 	exchangeValue(const BitcoinDatabase &database, const std::string &date, float amount);
void 	readInput(const BitcoinDatabase &database, const std::string &filename);
