/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scan.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:30:02 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:30:03 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <algorithm>
# include <vector>

class Span {
private:
	unsigned int	n;
	std::vector<int> v;

public:
	Span();
	~Span();
	Span(Span const &copy);
	Span	&operator=(Span const  &src);
	Span(unsigned int _n);
	void addNumber(int n);
	void addNumbers(int *num, int size);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void showElement();
	class EmptyArrayException: public std::exception{
		public:
			virtual const char * what() const throw() {
				return "Empty array";
			}
	};
	class MemoryException: public std::exception{
		public:
			virtual const char * what() const throw() {
				return "out of the set range";
			}
	};
	class OneArrayException: public std::exception{
		public:
			virtual const char * what() const throw() {
				return "One number in array";
			}
	};
};

#endif