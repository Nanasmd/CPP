/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:37:49 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/08 14:14:00 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructeur par défaut
ScalarConverter::ScalarConverter(){}

// Constructeur de copie
ScalarConverter::ScalarConverter(ScalarConverter const &other){*this = other;}

// Destructeur
ScalarConverter::~ScalarConverter(){}

// Surcharge de l'opérateur d'assignation
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	if (this == &other)
		return (*this);
	return (*this);
}

// Vérifie si la chaîne représente un NaN ou l'infini
static bool isNanInf(std::string const &in) {
	return (in == "nan" || in == "nanf" || in == "+inf" || in == "-inf" || in == "+inff" || in == "-inff" || in == "inf" || in == "inff");
}

// Vérifie si la chaîne est un caractère spécial
static bool isSpecialChar(std::string const &in) {
	return (in.length() == 1 &&	(in[0] == '+' || in[0] == '-' || in[0] == '.' || in[0] == 'f'));
}

// Vérifie la présence de signaux invalides
static bool hasInvalidSignal(std::string const &in) {
	return (in.find_first_of(SIGNAL) != in.find_last_of(SIGNAL));
}

// Vérifie si la chaîne est un entier
static bool isInt(std::string const &in) {
	return (in.find_first_not_of(DIGIT_SET) == std::string::npos);
}

// Vérifie si la chaîne est un double
static bool isDouble(std::string const &in) {
	return (in.find_first_not_of(DOUBLE_SET) == std::string::npos);
}

// Vérifie la validité d'un double
static bool isInvalidDouble(std::string const &in) {
	return (in.find_first_of(".") != in.find_last_of(".")
		|| isdigit(in[in.find_first_of(".") + 1]) == false
		|| in.find_first_of(".") == 0);
}

// Vérifie si la chaîne est un float
static bool isFloat(std::string const &in) {
	return (in.find_first_not_of(FLOAT_SET) == std::string::npos);
}

// Vérifie la validité d'un float
static bool isInvalidFloat(std::string const &in) {
	return (in.find_first_of("f") != in.find_last_of("f")
		|| in.find_first_of(".") != in.find_last_of(".")
		|| in.find_first_of("f") - in.find_first_of(".") == 1
		|| isdigit(in[in.find_first_of(".") + 1]) == false
		|| in.find_first_of(".") == 0);
}

// Vérifie si la chaîne est un caractère
static bool isChar(std::string const &in) {
	return (in.length() == 1 && isprint(in[0]));
}

// Analyse l'entrée et détermine son type
int ScalarConverter::parseInput(std::string const &input) {
    try {
        if (isNanInf(input)) {
            return NAN_INF;
        } else if (isSpecialChar(input)) {
            throw std::invalid_argument("Invalid character");
        } else if (hasInvalidSignal(input)) {
            throw std::invalid_argument("Invalid signal");
        } else if (isInt(input)) {
            return INT;
        } else if (isDouble(input)) {
            if (isInvalidDouble(input)) {
                throw std::invalid_argument("Invalid double");
            }
            return DOUBLE;
        } else if (isFloat(input)) {
            if (isInvalidFloat(input)) {
                throw std::invalid_argument("Invalid float");
            }
            return FLOAT;
        } else if (isChar(input)) {
            return CHAR;
        } else {
            throw std::invalid_argument("Invalid input");
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        return ERROR;
    }
}

// Convertit depuis un caractère
void ScalarConverter::fromChar(int type, std::string const &input) {
	char	c = static_cast<unsigned char>(input[0]);
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);
	ScalarConverter::print(type, input, c, i, f, d);
}

// Convertit depuis un entier
void ScalarConverter::fromInt(int type, std::string const &input) {
	int		i = std::atoi(input.c_str());
	char	c = static_cast<unsigned char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);
	ScalarConverter::print(type, input, c, i, f, d);
}

// Convertit depuis un float
void ScalarConverter::fromFloat(int type, std::string const &input) {
	float	f = std::atof(input.c_str());
	char	c = static_cast<unsigned char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<float>(f);
	ScalarConverter::print(type, input, c, i, f, d);
}

// Convertit depuis un double
void ScalarConverter::fromDouble(int type, std::string const &input) {
	double	d = std::atof(input.c_str());
	char	c = static_cast<unsigned char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);
	ScalarConverter::print(type, input, c, i, f, d);
}

// Méthode principale pour la conversion
void ScalarConverter::convert(const std::string &input) {
    int type = ScalarConverter::parseInput(input);
    
    try {
        switch (type) {
            case NAN_INF:
                ScalarConverter::fromDouble(type, input);
                break;
            case ERROR:
                throw std::runtime_error("Error: Input not convertible");
            case CHAR:
                ScalarConverter::fromChar(type, input);
                break;
            case INT:
                ScalarConverter::fromInt(type, input);
                break;
            case FLOAT:
                ScalarConverter::fromFloat(type, input);
                break;
            case DOUBLE:
                ScalarConverter::fromDouble(type, input);
                break;
            default:
                throw std::runtime_error("Error: Unhandled conversion type");
        }
    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}

// Imprime le caractère, avec gestion des caractères non affichables
static void printChar(int type, int i, char c) {
	if (type != NAN_INF && (i >= 0 && i <= UCHAR_MAX))
	{
		if (std::isprint(i))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << RED << "char: Non displayable" << RESET << std::endl;
	}
	else
		std::cout << RED << "char: impossible" << RESET << std::endl;
}

// Imprime l'entier, avec gestion des cas impossibles
static void printInt(int type, std::string const &in, int i) {
	double check = std::atof(in.c_str());
	
	if (type != NAN_INF && (check >= INT_MIN && check <= INT_MAX))
		std::cout << "int: " << i << std::endl;
	else
		std::cout << RED << "int: impossible" << RESET << std::endl;
}

// Imprime les valeurs spéciales NaN et infinis pour les floats et doubles
static void printNanInf(const std::string &in, const std::string &type) {
    if (strcmp(in.c_str(), "nan") == 0 || strcmp(in.c_str(), "nanf") == 0) {
        std::cout << type << ": nan";
    } else if (strcmp(in.c_str(), "+inf") == 0 || strcmp(in.c_str(), "+inff") == 0) {
        std::cout << type << ": +inf";
    } else if (strcmp(in.c_str(), "-inf") == 0 || strcmp(in.c_str(), "-inff") == 0) {
        std::cout << type << ": -inf";
    } else if (strcmp(in.c_str(), "inf") == 0 || strcmp(in.c_str(), "inff") == 0) {
        std::cout << type << ": inf";
    }
    if (type == "float") {
        std::cout << "f";
    }
    std::cout << std::endl;
}


// Imprime le float avec une précision fixe
static void printFloat(int type, std::string const &input, float f) {
	if (type != NAN_INF)
	{
		double check = std::atof(input.c_str());

		if (type == INT && (check < INT_MIN || check > INT_MAX))
			std::cout << RED << "float: impossible" << RESET << std::endl;
		else
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	else
		printNanInf(input, "float");
}

// Imprime le double avec une précision fixe
static void printDouble(int type, std::string const &input, double d) {
	if (type != NAN_INF)
	{
		double check = std::atof(input.c_str());

		if (type == INT && (check < INT_MIN || check > INT_MAX))
			std::cout << RED << "double: impossible" << RESET << std::endl;
		else
			std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else
		printNanInf(input, "double");
}

// Méthode pour imprimer les valeurs converties
void ScalarConverter::print(int type, std::string const &input, char c, int i, float f, double d) {
    try {
        if (type == ERROR) {
            throw std::invalid_argument("Invalid type for printing");
        }
        printChar(type, i, c);
        printInt(type, input, i);
        printFloat(type, input, f);
        printDouble(type, input, d);
    } catch (const std::invalid_argument& e) {
        std::cerr << RED << "Print Error: " << e.what() << RESET << std::endl;
    }
}
