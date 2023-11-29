/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:41:32 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/28 23:43:59 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// --------------------------------------- fonctions communes ---------------------------------------

// Vérifie si une chaîne représente un nombre valide
bool isValidNumber(std::string const &in)
{
	double nb = std::atof(in.c_str());

	// Vérifie si la chaîne est vide, contient des caractères non valides, ou représente un nombre hors limites
	if (in.empty() || (in.find_first_not_of(VALID_SET) != std::string::npos)
		|| nb < 0 || nb > (double)INT_MAX)
		return (false);
	return (true);	
}

// Vérifie si l'entrée du programme est valide
bool isValidInput(char **av)
{
	for (int i = 1; av[i]; i++)
		if (!isValidNumber(av[i]))
			return (false);
	return (true);
}

// Affiche la séquence d'entiers avant le tri
void printBefore(char **av)
{
	std::cout << V_CYAN << "Before:\t" << RESET;
	for (int i = 0; av[i]; i++)
		std::cout << av[i] << " ";
	std::cout << std::endl;
}

// Fonction pour imprimer le contenu d'une liste après le tri
void printListAfter(std::list<int> &list) {
    std::cout << V_CYAN << "After:\t" << RESET;
    for (std::list<int>::const_iterator it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printDequeAfter(std::deque<int> &deque)
{
	std::deque<int>::const_iterator it;

	std::cout << PINK << "After:\t" << RESET;;
	for (it = deque.begin(); it != deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void fillList(std::list<int> &list, char **av) {
    for (int i = 0; av[i]; i++) {
        list.push_back(std::atoi(av[i]));
    }
}

void fillDeque(std::deque<int> &deque, char **av) {
    for (int i = 0; av[i]; i++) {
        deque.push_back(std::atoi(av[i]));
    }
}

// Implémentation de sortList en utilisant l'algorithme de Ford-Johnson pour std::list
void sortList(std::list<int> &list, char **av, double &time) {
    clock_t start = clock();

    fillList(list, av);
    fordJohnsonSort(list); // Utilisation de l'algorithme de Ford-Johnson

    clock_t end = clock();
    time = (double)(end - start) / ((double)CLOCKS_PER_SEC / 1000);
}

// Implémentation de sortDeque en utilisant l'algorithme de Ford-Johnson pour std::deque
void sortDeque(std::deque<int> &deque, char **av, double &time) {
    clock_t start = clock();

    fillDeque(deque, av);
    fordJohnsonSort(deque); // Utilisation de l'algorithme de Ford-Johnson

    clock_t end = clock();
    time = (double)(end - start) / ((double)CLOCKS_PER_SEC / 1000);
}

// Fonction auxiliaire pour calculer les tailles de groupe pour l'étape 4
std::vector<int> calculateGroupSizes(int n) {
    std::vector<int> groupSizes;
    int total = 0;
    while (total < n) {
        int nextSize = static_cast<int>(std::pow(2, std::ceil(std::log(static_cast<double>(total + 1)) / std::log(2.0))) - total);
        groupSizes.push_back(std::min(nextSize, n - total));
        total += nextSize;
    }
    return groupSizes;
}

// Fonction auxiliaire pour l'insertion par recherche binaire à l'étape 5
template <typename T>
typename T::iterator binarySearchInsert(T &sequence, typename T::iterator end, const typename T::value_type &value) {
    typename T::iterator insertPos = std::lower_bound(sequence.begin(), end, value);
    return sequence.insert(insertPos, value);
}

// VERSION 4 : FORD-JOHNSON + C++98
template <typename T>
void fordJohnsonSort(T& sequence) {
    if (sequence.size() <= 1) {
        return; // Cas de base pour la récursion
    }

    // Étape 1 : Appariement et comparaison initiale
    std::vector<typename T::value_type> largerElements, smallerElements;

    typename T::iterator it = sequence.begin();
    while (it != sequence.end()) {
        typename T::iterator next = it; 
        ++next;
        if (next != sequence.end()) {
            if (*it > *next) {
                largerElements.push_back(*it);
                smallerElements.push_back(*next);
            } else {
                largerElements.push_back(*next);
                smallerElements.push_back(*it);
            }
            // Passer à la paire suivante
            ++next;
            it = next;
        } else {
            // Gérer le cas d'un nombre impair d'éléments
            smallerElements.push_back(*it);
            ++it;
        }
    }

    // Étape 2 : Tri récursif des éléments plus grands
    T sortedLargerElements(largerElements.begin(), largerElements.end());
    fordJohnsonSort(sortedLargerElements);

    // Étape 3 : Fusion des éléments plus grands
    sequence.clear();
    for (typename T::iterator it = sortedLargerElements.begin(); it != sortedLargerElements.end(); ++it) {
        sequence.push_back(*it);
    }

    // Étape 4 et 5 : Insertion des éléments plus petits
    for (typename std::vector<typename T::value_type>::iterator k = smallerElements.begin(); k != smallerElements.end(); ++k) {
        // Insérer chaque élément plus petit à sa position correcte
        typename T::iterator insertPos = sequence.begin();
        while (insertPos != sequence.end() && *insertPos < *k) {
            ++insertPos;
        }
        sequence.insert(insertPos, *k);
    }
}


// Initial Sequence: 3  1  2  5

					

// Pairing:
// Step 1:  3-1  =>  Larger: 3, Smaller: 1
// Step 2:  2-5  =>  Larger: 5, Smaller: 2

// After Pairing:
// Larger Elements:  3  5
// Smaller Elements: 1  2

// Recursive Sort (Larger Elements):
// 3  5  (already sorted)

// Merge Back:
// 3  5

// Inserting Smaller Elements:
// Insert 1: 1  3  5
// Insert 2: 1  2  3  5

// Final Sorted Sequence: 1  2  3  5












































// VERSION 3 WORKING USING STD::MERGE
// template <typename T>
// void mergeBack(T& sequence, const std::vector<typename T::value_type>& sortedElements) {
//     sequence.clear();
//     for (typename std::vector<typename T::value_type>::const_iterator it = sortedElements.begin(); it != sortedElements.end(); ++it) {
//         sequence.push_back(*it);
//     }
// }

// template <typename T>
// void fordJohnsonSort(T& sequence) {
//     if (sequence.size() <= 1) {
//         return; // Base case for recursion
//     }

//     std::vector<typename T::value_type> elements(sequence.begin(), sequence.end());
//     std::vector<typename T::value_type> largerElements, smallerElements;

//     for (size_t i = 0; i < elements.size(); i += 2) {
//         if (i + 1 < elements.size()) {
//             if (elements[i] > elements[i + 1]) {
//                 largerElements.push_back(elements[i]);
//                 smallerElements.push_back(elements[i + 1]);
//             } else {
//                 largerElements.push_back(elements[i + 1]);
//                 smallerElements.push_back(elements[i]);
//             }
//         } else {
//             // Handle the odd element case
//             smallerElements.push_back(elements[i]);
//         }
//     }

//     // Recursive sorting of larger elements
//     T sortedLargerElements(largerElements.begin(), largerElements.end());
//     fordJohnsonSort(sortedLargerElements);

//     // Merging back the larger elements
//     std::vector<typename T::value_type> mergedElements;
//     std::merge(sortedLargerElements.begin(), sortedLargerElements.end(), smallerElements.begin(), smallerElements.end(), std::back_inserter(mergedElements));

//     // Merge back into original sequence
//     mergeBack(sequence, mergedElements);
// }

// Helper function for binary search insertion in Step 5
// template <typename T>
// typename T::iterator binarySearchInsert(T &sequence, typename T::iterator end, const typename T::value_type &value) {
//     typename T::iterator insertPos = std::lower_bound(sequence.begin(), end, value);
//     return sequence.insert(insertPos, value);
// }

// VERSION 1 NOT WORKING : ELEMENT MISSING + DUPLICATE
// template <typename T>
// void fordJohnsonSort(T &sequence) {
//     if (sequence.size() <= 1) {
//         return; // Base case for recursion
//     }

//     // Step 1: Pairing and Initial Comparison
//     std::vector<typename T::value_type> largerElements, smallerElements;

//     typename T::iterator it = sequence.begin();
// 	std::cout << "STARTING BLOCKS :" << std::endl;
// 	std::cout << "IT :" << *it << std::endl;
// 	std::cout << std::endl;
//     while (it != sequence.end())
// 	{
//         typename T::iterator next = it;
//         ++next;
// 		std::cout << "IT :" << *it << std::endl;
// 		std::cout << "NEXT :" << *next << std::endl;
// 		std::cout << std::endl;
//         if (next != sequence.end()) 
// 		{
//             if (*it > *next) 
// 			{
//                 largerElements.push_back(*it);
// 				it = sequence.erase(it); // Then erase 'it' and update it
// 				++it;
//                 // smallerElements.push_back(*next);
//             } 
// 			else 
// 			{
//                 largerElements.push_back(*next);
// 				sequence.erase(next); // First erase the next element
// 				++it;
//                 // smallerElements.push_back(*it);
//             }
//             // Erase both elements
//             // sequence.erase(next); // First erase the next element
//             // it = sequence.erase(it); // Then erase 'it' and update it
//         } 
// 		else 
// 		{
//             // Handle the case where there is an odd number of elements
//             smallerElements.push_back(*it);
//             it = sequence.erase(it);
//         }
//     }


// VERSION 0 : Implementation of Ford-Johnson algorithm (merge-insertion sort)
// template <typename T>
// void fordJohnsonSort(T &sequence) {
//     if (sequence.size() <= 1) {
//         return; // Base case for recursion
//     }

//     // Step 1: Pairing and Initial Comparison
//     std::vector<typename T::value_type> largerElements;
//     for (typename T::iterator it = sequence.begin(); it != sequence.end(); /* updated inside */) {
//         typename T::iterator next = it; ++next;
//         if (next != sequence.end()) {
//             if (*it > *next) {
//                 largerElements.push_back(*it);
//                 it = sequence.erase(it);
//             } else {
//                 largerElements.push_back(*next);
//                 sequence.erase(next++);
//             }
//             it = next;
//         } else {
//             ++it;
//         }
//     }

//     // Step 2: Recursive Sorting of Larger Elements
//     T sortedLargerElements(largerElements.begin(), largerElements.end());
//     fordJohnsonSort(sortedLargerElements);

//     // Step 3: Initial Insertion
//     if (!sortedLargerElements.empty()) {
//         sequence.push_front(sortedLargerElements.front());
//         sortedLargerElements.pop_front();
//     }

//     // Steps 4 and 5: Ordering and Binary Search Insertion
//     std::vector<typename T::value_type> smallerElements(sequence.begin(), sequence.end());
// sequence.clear();

// std::vector<int> groupSizes = calculateGroupSizes(smallerElements.size());
// std::vector<typename T::value_type> orderedElements;

// int start = 0;
// for (std::vector<int>::size_type i = 0; i < groupSizes.size(); ++i) {
//     int size = groupSizes[i];
//     for (int j = start + size - 1; j >= start; --j) {
//         orderedElements.push_back(smallerElements[j]);
//     }
//     start += size;
// }

// for (typename std::vector<typename T::value_type>::size_type k = 0; k < orderedElements.size(); ++k) {
//     binarySearchInsert(sequence, sequence.end(), orderedElements[k]);
// }

// sequence.insert(sequence.end(), sortedLargerElements.begin(), sortedLargerElements.end());
// }

// ORIGINAL // --------------------------------------- fonctions pour list ---------------------------------------

// // Remplit une liste avec les valeurs fournies
// void fillList(std::list<int> &list, char **av)
// {
// 	for (int i = 0; av[i]; i++)
// 		list.push_back(std::atoi(av[i]));
// }

// // Insère un élément dans une liste triée
// void listInsert(std::list<int> &sorted, int const &nb)
// {
// 	std::list<int>::iterator it;

// 	// Parcours la liste et insère l'élément à la bonne position
// 	for (it = sorted.begin(); it != sorted.end(); it++)
// 	{
// 		if (*it > nb)
// 		{
// 			sorted.insert(it, nb);
// 			return ;
// 		}
// 	}
// 	sorted.insert(it, nb);
// }

// // Tri par insertion pour une liste
// void listInsertionSort(std::list<int> &list)
// {
// 	std::list<int> sorted;

// 	// Trie chaque élément un par un
// 	while (!list.empty())
// 	{
// 		int nb = list.front();
// 		list.pop_front();
// 		listInsert(sorted, nb);
// 	}
// 	list.swap(sorted);
// }

// // Tri fusion-insertion pour une liste
// void listMergeInsertionSort(std::list<int> &list)
// {
// 	// Utilise le tri par insertion pour de petits ensembles
// 	if (list.size() <= LIMITER)
// 	{
// 		listInsertionSort(list);
// 		return ;
// 	}

// 	 // Divise la liste en deux, trie chaque moitié, puis fusionne
// 	std::list<int> left, right;
// 	int middle = list.size() / 2;
// 	for (int i = 0; i < middle; i++)
// 	{
// 		left.push_back(list.front());
// 		list.pop_front();
// 	}
// 	right = list;
	
// 	// recursion
// 	listMergeInsertionSort(left);
// 	listMergeInsertionSort(right);

// 	list.clear();
// 	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(list));

// }

// // Tri et mesure du temps pour une liste
// void sortList(std::list<int> &list, char **av, double &time)
// {
// 	clock_t start = clock();

// 	fillList(list, av);
// 	listMergeInsertionSort(list);

// 	clock_t end = clock();
// 	time = (double)(end - start) / ((double)CLOCKS_PER_SEC / 1000);
// }

// // Affiche la liste après le tri
// void printListAfter(std::list<int> &list)
// {
// 	std::list<int>::const_iterator it;

// 	std::cout << PINK << "After:\t" << RESET;
// 	for (it = list.begin(); it != list.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }

// // --------------------------------------- fonctions pour deque ---------------------------------------

// // Les fonctions pour 'deque' suivent une logique similaire à celles pour 'list', adaptées au container 'deque'
// void fillDeque(std::deque<int> &deque, char **av)
// {
// 	for (int i = 0; av[i]; i++)
// 		deque.push_back(std::atoi(av[i]));
// }

// void printDequeAfter(std::deque<int> &deque)
// {
// 	std::deque<int>::const_iterator it;

// 	std::cout << PINK << "After:\t" << RESET;;
// 	for (it = deque.begin(); it != deque.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }

// void dequeInsert(std::deque<int> &sorted, int const &nb)
// {
// 	std::deque<int>::iterator it;

// 	for (it = sorted.begin(); it != sorted.end(); it++)
// 	{
// 		if (*it > nb)
// 		{
// 			sorted.insert(it, nb);
// 			return ;
// 		}
// 	}
// 	sorted.insert(it, nb);
// }

// void dequeInsertionSort(std::deque<int> &deque)
// {
// 	std::deque<int> sorted;

// 	while (!deque.empty())
// 	{
// 		int nb = deque.front();
// 		deque.pop_front();
// 		dequeInsert(sorted, nb);
// 	}
// 	deque.swap(sorted);
// }

// void dequeMergeInsertionSort(std::deque<int> &deque)
// {
// 	if (deque.size() <= LIMITER)
// 	{
// 		dequeInsertionSort(deque);
// 		return ;
// 	}
// 	std::deque<int> left, right;
// 	int middle = deque.size() / 2;
// 	for (int i = 0; i < middle; i++)
// 	{
// 		left.push_back(deque.front());
// 		deque.pop_front();
// 	}
// 	right = deque;

// 	dequeMergeInsertionSort(left);
// 	dequeMergeInsertionSort(right);

// 	deque.clear();
// 	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(deque));
// }

// void sortDeque(std::deque<int> &deque, char **av, double &time)
// {
// 	clock_t start = clock();

// 	fillDeque(deque, av);
// 	dequeMergeInsertionSort(deque);

// 	clock_t end = clock();
// 	time = (double)(end - start) / ((double)CLOCKS_PER_SEC / 1000);
// }
