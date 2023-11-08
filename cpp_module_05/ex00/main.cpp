/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:07:19 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/03 20:02:44 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
#define WITHOUT_NEWLINE	0
#define WITH_NEWLINE	1

void	mainHeader() 
{
	std::cout << "\033c";
	std::cout << PINK << "********************************************" << RESET << std::endl;
	std::cout << PINK << "*         nasamadi's C++ BUREAUCRAT        *" << RESET << std::endl;
	std::cout << PINK << "********************************************" << RESET << std::endl << std::endl;
}

void	pressEnter(void)
{
	std::cout << std::endl << GREEN << "press ENTER to continue" << RESET << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void debugMessageConstructors(int newline)
{
	std::cout << std::endl;
	std::cout << BLUE << "constructors> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageStatus(int newline)
{
	std::cout << std::endl;
	std::cout << PURPLE << "status> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageDestructors(int newline)
{
	std::cout << std::endl;
	std::cout << YELLOW << "destructors> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageAction(std::string action)
{
	std::cout << std::endl;
	std::cout << GREEN << "action> " << RESET;
	if (action.length())
		std::cout << action << std::endl;
}

void exceptionError(std::string message, std::string exception)
{
	std::cerr << BOLD_RED << "\t" << message << exception << RESET << std::endl;
}

void titleHeader(const std::string& message)
{
    std::cout << "\033c";
	mainHeader();
    int standartSize = 34;
    int messageSize = message.length();
    int spaces = (standartSize - messageSize) / 2;

    std::cout << LILAC << "************************************" << std::endl << "*" << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << LILAC << message << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << LILAC << "*" << std::endl << "************************************" << RESET << std::endl;
}

int	main(void)
{
	{
		titleHeader("BASIC TEST");

		debugMessageConstructors(WITHOUT_NEWLINE);
		Bureaucrat *theDefault = new Bureaucrat();

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theDefault;
		try
		{
			debugMessageAction("try to increment grade");
			theDefault->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			exceptionError("Error: ", e.what());
		}
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theDefault;
		try
		{
			debugMessageAction("try to decrement grade");
			theDefault->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("Error: ", e.what());
		}
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theDefault;
		try
		{
			debugMessageAction("try to decrement grade");
			theDefault->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("Error: ", e.what());
		}
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theDefault;

		debugMessageDestructors(WITHOUT_NEWLINE);
		delete theDefault;
	}
	pressEnter();
	{
		titleHeader("CALL WITH VALID NUMBER");

		debugMessageConstructors(WITHOUT_NEWLINE);
		Bureaucrat *validNumber = new Bureaucrat(1);

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << validNumber;
		try
		{
			debugMessageAction("try to decrement grade");
			validNumber->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("Error: ", e.what());
		}
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << validNumber;
		try
		{
			debugMessageAction("try to increment grade");
			validNumber->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			exceptionError("Error: ", e.what());
		}
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << validNumber;
		try
		{
			debugMessageAction("try to increment grade");
			validNumber->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			exceptionError("Error: ", e.what());
		}
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << validNumber;

		debugMessageDestructors(WITHOUT_NEWLINE);
		delete validNumber;
	}
	pressEnter();
	{
		titleHeader("CALL WITH HIGH INVALID NUMBERS");

		Bureaucrat *theHighest = NULL;
		try
		{
			debugMessageConstructors(WITHOUT_NEWLINE);
			theHighest = new Bureaucrat(0);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			exceptionError("Error: ", e.what());
		}
		if (theHighest)
		{
			debugMessageStatus(WITHOUT_NEWLINE);
			std::cout << theHighest;
			debugMessageDestructors(WITHOUT_NEWLINE);
			delete theHighest;
		}
	}
	pressEnter();
	{
		titleHeader("CALL WITH LOW INVALID NUMBERS");
		Bureaucrat *theLowest = NULL;
		try
		{
			debugMessageConstructors(WITHOUT_NEWLINE);
			theLowest = new Bureaucrat(151);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("Error: ", e.what());
		}
		if (theLowest)
		{
			debugMessageStatus(WITHOUT_NEWLINE);
			std::cout << theLowest;
			debugMessageDestructors(WITHOUT_NEWLINE);
			delete theLowest;
		}
	}
	pressEnter();
	{
		titleHeader("DEEP COPY TESTS");

		debugMessageConstructors(WITHOUT_NEWLINE);
		Bureaucrat *theOriginal = new Bureaucrat("First Class", 111);

		debugMessageAction("try to increment grade");
		theOriginal->incrementGrade();

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theOriginal;

		debugMessageConstructors(WITH_NEWLINE);
		Bureaucrat *theCopy = new Bureaucrat(*theOriginal);

		debugMessageDestructors(WITHOUT_NEWLINE);
		delete theOriginal;

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theCopy;

		debugMessageAction("try to decrement grade");
		theCopy->decrementGrade();

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theCopy;

		debugMessageDestructors(WITHOUT_NEWLINE);
		delete theCopy;
	}
	pressEnter();
}