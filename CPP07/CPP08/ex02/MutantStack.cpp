/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:31:01 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:31:03 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(): n(0) {}

Span::~Span(){}

Span::Span(Span const &copy){
	*this = copy;
}

Span::Span(unsigned int _n): n(_n) {}

Span	&Span::operator=(Span const  &src)
{
	if (this != &src)
		this->v = src.v;
	return *this;
}

void	Span::addNumber(int const add)
{
	if (this->v.size() >= n)
	{
		this->v.clear();
		std::vector<int>().swap(this->v);
		throw MemoryException();
	}
	v.push_back(add);
}

void	Span::addNumbers(int *num, int size)
{
	std::vector<int>::iterator it = v.begin();
	this->v.insert(it, num, num + size);
	if (this->v.size() > n)
	{
		this->v.clear();
		std::vector<int>().swap(this->v);
		throw MemoryException();
	}
}


unsigned int	Span::shortestSpan()
{
	if (!this->v.size())
		throw EmptyArrayException();
	else if (this->v.size() == 1)
		throw OneArrayException();
	std::vector<int>	tmp(this->v);
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator it;
	unsigned int ret = longestSpan();
	for (it = tmp.begin(); it < tmp.end() - 1; it++)
	{
		if (static_cast<unsigned int>(*(it + 1) - *it) < ret)
			ret = *(it + 1) - *it;
	}
	return ret;
}

unsigned int	Span::longestSpan()
{
	if (!this->v.size())
		throw EmptyArrayException();
	else if (this->v.size() == 1)
		throw OneArrayException();
	std::vector<int>	tmp(this->v);
	std::sort(tmp.begin(), tmp.end());
	return *(tmp.end() - 1) - *tmp.begin();
}

void	Span::showElement()
{
	std::vector<int>::iterator it;
	for(it = this->v.begin(); it < this->v.end(); it++)
		std::cout << "element: " << *it << std::endl;
}