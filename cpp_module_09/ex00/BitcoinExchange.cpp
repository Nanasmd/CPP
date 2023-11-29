/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:40:53 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/30 00:04:47 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Vérifie si une chaîne de caractères représente un nombre valide.
bool isValidNumber(std::string const &in) {
    // Vérifie l'absence de caractères invalides, la présence d'un seul point, et la position correcte du signe.
    if ((in.find_first_not_of(VALID_SET) != std::string::npos)
        || (in.find_first_of(".") != in.find_last_of("."))
        || (in.find_first_of(".") == in.length() - 1)
        || (in.find_first_of(".") == 0)
        || (in.find_first_of(SIGNAL) != in.find_last_of(SIGNAL))) {
        return false;
    }
    return true;	
}

// Détermine si une année est bissextile.
bool isLeapYear(int year) {
    // Une année bissextile est divisible par 4, mais pas par 100 sauf si elle est également divisible par 400.
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

// Vérifie si une chaîne de caractères représente une date valide.
bool isValidDate(const std::string &date, std::string &errorMessage) {
	// Vérifie la longueur et le format de la date.
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        errorMessage = "Error: Invalid date format => " + date;
        return false;
    }

	// Extrait l'année, le mois et le jour en tant qu'entiers.
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

	// Initialise les noms des mois.
    std::stringstream ss;
    std::vector<std::string> monthNames;
    monthNames.push_back("January");
    monthNames.push_back("February");
    monthNames.push_back("March");
	monthNames.push_back("April");
	monthNames.push_back("May");
	monthNames.push_back("June");
	monthNames.push_back("July");
	monthNames.push_back("August");
	monthNames.push_back("September");
	monthNames.push_back("October");
	monthNames.push_back("November");
	monthNames.push_back("December");

    if (month < 1 || month > 12) {
        ss << "Error: Invalid month format (no " << month << "th month)";
        errorMessage = ss.str();
        return false;
    }

	if (month == 2 && day == 29 && !isLeapYear(year)) {
        ss << "Error: Invalid date (" << year << " is not a leap year)";
        errorMessage = ss.str();
        return false;
    }

    const int daysInMonth[] = { 31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day < 1 || day > daysInMonth[month - 1]) {
        if (month == 2 && day == 30) {
            ss << "Error: Invalid date (February never has 30 days)";
        } else if (day > 31) {
            ss << "Error: Invalid date (" << monthNames[month - 1] << " has only 31 days)";
        } else if (day > 30) {
            ss << "Error: Invalid date (" << monthNames[month - 1] << " has only 30 days)";
        } else {
            ss << "Error: Invalid date format => " << date;
        }
        errorMessage = ss.str();
        return false;
    }

    return true;
}

// Fonction pour vérifier si une chaîne est une valeur valide
bool isValidValue(const std::string &in, std::string &errorMessage) {
    // Vérifie si la chaîne représente un nombre valide.
	if (!isValidNumber(in)) {
        errorMessage = "Error: amount is not a valid number";
        return false;
    }
    // Vérifie si le nombre est négatif ou dépasse la valeur maximale autorisée.
    float nb = std::atof(in.c_str());
    if (nb < 0) {
        errorMessage = "Error: amount cannot be negative";
        return false;
    }
    
    if (nb >= (float)INT_MAX) {
        errorMessage = "Error: amount exceeds MAX";
        return false;
    }

    return true;
}

// Vérifie si le montant est valide
bool isValidAmount(const std::string &in, std::string &errorMessage) {
    if (!isValidNumber(in)) {
        errorMessage = "Error: amount is not a valid number";
        return false;
    }
    // Vérifie si le nombre est négatif ou dépasse 1000.
    float nb = std::atof(in.c_str());
    if (nb < 0) {
        errorMessage = "Error: amount cannot be negative";
        return false;
    }
    
    if (nb > 1000) {
        errorMessage = "Error: amount is larger than 1000";
        return false;
    }

    return true;
}

// Élimine les espaces superflus.
std::string trim(std::string const &str)
{
    size_t start = str.find_first_not_of(SPACES_SET);
    size_t end = str.find_last_not_of(SPACES_SET);

    if (start == std::string::npos)
        return "";

    return (str.substr(start, end - start + 1));
}

// Obtienir la base de données à partir d'un fichier CSV.
BitcoinDatabase getDatabase() {
    std::ifstream file("data.csv");
    BitcoinDatabase database;
    std::string line, date, value, errorMessage;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open data.csv file" << std::endl;
        return database; // Return empty database
    }

    std::getline(file, line);
    if (line != "date,exchange_rate") {
        std::cerr << "Error: Invalid header in data.csv file" << std::endl;
        return database; // Return empty database
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        ss >> value;

        if (!isValidValue(value, errorMessage)) {
            std::cerr << "Error in data.csv: " << errorMessage << " (Line: " << line << ")" << std::endl;
            continue; // Skip this line and continue with the next
        }

        float price = std::atof(value.c_str());
        database[date] = price;
    }

    file.close();
    return database;
}


// Logique de comparaison.
int compareDates(std::tm const &a, std::tm const &b)
{
	if (a.tm_year > b.tm_year)
		return (DB_IS_LARGER);
	else if (a.tm_year < b.tm_year)
		return (IN_IS_LARGER);
	else if (a.tm_mon > b.tm_mon)
		return (DB_IS_LARGER);
	else if (a.tm_mon < b.tm_mon)
		return (IN_IS_LARGER);
	else if (a.tm_mday > b.tm_mday)
		return (DB_IS_LARGER);
	else if (a.tm_mday < b.tm_mday)
		return (IN_IS_LARGER);
	return (EQUAL);
}

// Calcule la valeur d'échange.
float exchangeValue(const BitcoinDatabase &database, const std::string &date, float amount)
{
    std::map<std::string, float>::const_iterator it = database.lower_bound(date);
	// Trouve la valeur la plus proche inférieure ou égale à la date donnée.
    // If the iterator points to the end or the date is greater than the key, move to the previous element
    if (it == database.end() || it->first > date) {
        // Check to avoid moving before the beginning of the map
        if (it != database.begin()) {
            --it;
        } else {
            // If we are at the beginning, and it's still not a match, there's no valid rate available
            return 0;
        }
    }

    // If the date exactly matches, or it's the closest lower date
    return it->second * amount;
}

// Lecture des inputs à partir d'un fichier.
void readInput(const BitcoinDatabase &database, const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << BOLD_RED << "Error: could not open file '" << filename << "'." << RESET << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);  // Ignore la première ligne (en-tête)

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, amountStr, errorMessage;
        std::getline(ss, date, '|');
        date = trim(date);
        ss >> amountStr;

        if (!isValidDate(date, errorMessage)) {
            std::cerr << BOLD_RED << errorMessage << RESET << std::endl;
            continue;
        }

		if (!isValidAmount(amountStr, errorMessage)) {
   			std::cerr << BOLD_RED << errorMessage << RESET << std::endl;
            continue;
        }

        float value = std::atof(amountStr.c_str());
        if (value < 0) {
            std::cerr << BOLD_RED << "Error: negative number not allowed => " << amountStr << RESET << std::endl;
            continue;
        }

        if (value > 1000) {
            std::cerr << BOLD_RED << "Error: value exceeds maximum limit (1000) => " << amountStr << RESET << std::endl;
            continue;
        }

        float exchange = exchangeValue(database, date, value);
        std::cout << date << " => " << value << " = " << GREEN << std::fixed << std::setprecision(1) << exchange << RESET << std::endl;
    }

    file.close();
}

