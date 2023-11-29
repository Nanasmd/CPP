/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:41:24 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/28 20:04:03 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Usage example with std::list
// int main() {
//     std::list<int> numbers = {34, 7, 23, 32, 5, 62, 78, 4, 1, 9};

//     fordJohnsonSort(numbers);

//     for (int num : numbers) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }

int main(int ac, char **av)
{
	std::list<int> list;
	std::deque<int> deque;
	double listTime;
	double dequeTime;

	try
	{
		if (!isValidInput(av) || ac == 1)
			throw std::runtime_error(ERROR);
		++av;
		printBefore(av);
		sortList(list, av, listTime);
		sortDeque(deque, av, dequeTime);
		printListAfter(list);
		printDequeAfter(deque);
		std::cout << "Time to process a range of " << list.size() << " elements with std::list  : " << GREEN << listTime << " miliseconds" << RESET << std::endl;
		std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << GREEN << dequeTime << " miliseconds" << RESET << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
}
