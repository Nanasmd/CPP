/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:41:37 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/28 23:44:35 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <string>
#include <list>
#include <deque>
#include <ctime>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <iterator>

// Définition de constantes pour la validation et le formatage de l'affichage
#define VALID_SET	"0123456789"
#define LIMITER		5

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

#define ERROR	"Error"


// Déclaration des fonctions communes et spécifiques aux containers
bool isValidNumber(std::string const &in);
bool isValidInput(char **av);
void printBefore(char **av);

// Fonctions pour la gestion et le tri d'une liste
void fillList(std::list<int> &list, char **av);
void listInsert(std::list<int> &sorted, int const &nb);
void listInsertionSort(std::list<int> &list);
void listMergeInsertionSort(std::list<int> &list);
void sortList(std::list<int> &list, char **av, double &time);
void printListAfter(std::list<int> &list);

// Fonctions pour la gestion et le tri d'un deque
void fillDeque(std::deque<int> &deque, char **av);
void dequeInsert(std::deque<int> &sorted, int const &nb);
void dequeInsertionSort(std::deque<int> &deque);
void dequeMergeInsertionSort(std::deque<int> &deque);
void sortDeque(std::deque<int> &deque, char **av, double &time);
void printDequeAfter(std::deque<int> &deque);

template <typename T>
void fordJohnsonSort(T &sequence);
