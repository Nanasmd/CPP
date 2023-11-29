/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:40:40 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/14 14:46:35 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

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
	std::cout << PINK << "*              nasamadi's C++ 08           *" << RESET << std::endl;
	std::cout << PINK << "********************************************" << RESET << std::endl << std::endl;
}

void	pressEnter(void)
{
	std::cout << std::endl << GREEN << "press ENTER to continue" << RESET<< std::endl;
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

void titleHeader(const std::string& message)
{
    std::cout << "\033c";
	mainHeader();
    int standardSize = 34;
    int messageSize = message.length();
    int spaces = (standardSize - messageSize) / 2;

    std::cout << YELLOW << "************************************" << std::endl << "*" << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << YELLOW << message << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << YELLOW << "*" << std::endl << "************************************" << RESET << std::endl << std::endl;
}

int main(int, char**)
{
	{
		titleHeader("MUTANT STACK TEST");
		
		debugMessageConstructors(WITHOUT_NEWLINE);
		MutantStack<int> mstack;
		
		debugMessageAction("insert 5, 17, 589 on stack");
		mstack.push(5);
		mstack.push(17);
		mstack.push(589);
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "Top value: " << mstack.top() << std::endl;
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "Stack size: " << mstack.size() << std::endl;
		
		debugMessageAction("remove top value");
		mstack.pop();

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "Top value: " << mstack.top() << std::endl;
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "Stack size: " << mstack.size() << std::endl;
		
		debugMessageAction("insert value 3, 5, 737 and 0 on stack");
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		debugMessageAction("print all values on stack using iterator");
		std::cout << "\t";
		while (it != ite)
		{
			std::cout << "[" << *it << "] ";
			++it;
		}
		std::cout << std::endl;

		debugMessageAction("copy the Mutant Stack to another common stack");
		std::stack<int> s(mstack);

		debugMessageAction("delete all values on stack");
		MutantStack<int>::iterator itEnd;
		while (!mstack.empty())
		{
			itEnd = mstack.end();
			--itEnd;
			std::cout << "\t" << "... deleting " << *itEnd << " from stack" << std::endl;
			mstack.pop();			
		}
		
		debugMessageDestructors(WITHOUT_NEWLINE);
	}
	pressEnter();
	{
		titleHeader("SAME TEST BUT WITH LIST");

		// std::list<int> list;
		std::list<int> myList;  // Renamed variable
		
		debugMessageAction("insert 5, 17, 589 on list");
		myList.push_back(5);
		myList.push_back(17);
		myList.push_back(589);
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "List top value: " << myList.back() << std::endl;

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "List size: " << myList.size() << std::endl;

		debugMessageAction("remove top value");
		myList.pop_back();

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "List top value: " << myList.back() << std::endl;
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "List size: " << myList.size() << std::endl;

		debugMessageAction("insert value 3, 5, 737 and 0 on list");
		myList.push_back(3);
		myList.push_back(5);
		myList.push_back(737);
		myList.push_back(0);

		std::list<int>::iterator it = myList.begin();
		std::list<int>::iterator ite = myList.end();
		
		++it;
		--it;
		debugMessageAction("print all values on list using iterator");
		std::cout << "\t";
		while (it != ite)
		{
			std::cout << "[" << *it << "] ";
			++it;
		}
		std::cout << std::endl;

		debugMessageAction("copy the list to another list");
		std::list<int> s(myList);

		debugMessageAction("delete all values on list");
		std::list<int>::iterator itEnd;
		while (!myList.empty())
		{
			itEnd = myList.end();
			--itEnd;
			std::cout << "\t" << "... deleting " << *itEnd << " from list" << std::endl;
			myList.pop_back();			
		}
	}
	pressEnter();
	return 0;
}
