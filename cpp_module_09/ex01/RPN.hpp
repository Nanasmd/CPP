/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:41:21 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/24 16:44:47 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

// Définition des ensembles de caractères valides pour les nombres.
#define VALID_SET	"0123456789"

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

// Messages d'erreur standards.
#define ERROR	"Error"
#define INVALID	"Invalid operations"
#define USAGE	"Usage: ./rpn \"[expression]\""

bool isValidNumber(std::string const &in);
bool isOperator(std::string const &in);

void doOperation(std::string const &in, std::stack<int> &stack);
void addNumber(std::string const &in, std::stack<int> &stack);

void rpn(std::string const &in);
