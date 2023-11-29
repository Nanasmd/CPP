/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:41:17 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/30 00:55:07 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Vérifie si la chaîne représente un nombre valide.
// bool isValidNumber(std::string const &in)
// {
// 	if (in.empty() || (in.find_first_not_of(VALID_SET) != std::string::npos))
// 		return (false);
// 	return (true);	
// }

// // Vérifie si la chaîne est un opérateur valide.
// bool isOperator(std::string const &in)
// {
// 	return (in == "+" || in == "-" || in == "*" || in == "/");
// }

// // Effectue l'opération indiquée sur les deux nombres en haut de la pile.
// void doOperation(std::string const &in, std::stack<int> &stack)
// {
// 	if (stack.size() < 2)
// 		throw std::runtime_error(INVALID);
// 	int a = stack.top();
// 	stack.pop();
// 	int b = stack.top();
// 	stack.pop();

// 	if (in == "+")
// 		stack.push(b + a);
// 	else if (in == "-")
// 		stack.push(b - a);
// 	else if (in == "*")
// 		stack.push(b * a);
// 	else if (in == "/") {
//         // Check for division by zero
//         if (a == 0)
//             throw std::runtime_error("Division by zero error");
//         stack.push(b / a);
//     }
// }

// // Ajoute un nombre à la pile.
// void addNumber(std::string const &in, std::stack<int> &stack)
// {
// 	int nb = std::atoi(in.c_str());

// 	if (nb > 9)
// 		throw std::runtime_error(ERROR);
// 	stack.push(nb);
// }

// // Traite l'expression RPN et imprime le résultat.
// void rpn(std::string const &in)
// {
// 	std::stack<int> stack;
// 	std::stringstream ss(in);
// 	std::string token;

// 	while (!ss.eof())
// 	{
// 		std::getline(ss, token, ' ');
// 		if (token.empty())
// 			continue;
// 		if (isOperator(token))
// 			doOperation(token, stack);
// 		else if (isValidNumber(token))
// 			addNumber(token, stack);
// 		else
// 			throw std::runtime_error(ERROR);
// 	}
// 	if (stack.size() == 1)
// 		std::cout << stack.top() << std::endl;
// 	else
// 		throw std::runtime_error(ERROR);
// }

bool isValidNumber(std::string const &in)
{
    if (in.empty())
        throw std::runtime_error("Error: Empty input");
    if (in.find_first_not_of(VALID_SET) != std::string::npos)
        throw std::runtime_error(NON_NUMERIC);
    return true;    
}

bool isOperator(std::string const &in)
{
    return in == "+" || in == "-" || in == "*" || in == "/";
}

void doOperation(std::string const &in, std::stack<int> &stack)
{
    if (stack.size() < 2)
        throw std::runtime_error(INVALID);
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();

    if (in == "+")
        stack.push(b + a);
    else if (in == "-")
        stack.push(b - a);
    else if (in == "*")
        stack.push(b * a);
    else if (in == "/") {
        if (a == 0)
            throw std::runtime_error(DIV_ZERO);
        stack.push(b / a);
    }
}

void addNumber(std::string const &in, std::stack<int> &stack)
{
    int nb = std::atoi(in.c_str());
    if (nb > MAX_NUMBER)
        throw std::runtime_error(TOO_LARGE);
    stack.push(nb);
}

void rpn(std::string const &in)
{
    if (in.empty())
        throw std::runtime_error("Error: Empty input");

    std::stack<int> stack;
    std::stringstream ss(in);
    std::string token;

    while (std::getline(ss, token, ' ')) {
        if (token.empty())
            continue;
        if (isOperator(token))
            doOperation(token, stack);
        else if (isValidNumber(token))
            addNumber(token, stack);
        else
            throw std::runtime_error(ERROR);
    }

    if (stack.size() != 1)
        throw std::runtime_error(INCOMPLETE_EXPR);

    std::cout << stack.top() << std::endl;
}

