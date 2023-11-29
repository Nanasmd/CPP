/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:40:31 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/23 18:22:09 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0){}
Span::Span(Span const &other){*this = other;}
Span::Span(unsigned int N) : N(N){}
Span::~Span(){}

Span &Span::operator=(Span const &other)
{
	if (this == &other)
		return (*this);
	this->N = other.getN();
	this->storage = other.getStorage();
	return (*this);
}

unsigned int Span::getN() const{return (this->N);}
std::vector<int> Span::getStorage() const{return (this->storage);}

void Span::addNumber(int number)
{
	if (this->storage.size() >= this->N)
		throw Span::FullStorageException();
	this->storage.push_back(number);
}

void Span::addNumbers(const std::vector<int>& numbers) {
    if (this->storage.size() + numbers.size() > this->N)
        throw Span::FullStorageException();
    this->storage.insert(this->storage.end(), numbers.begin(), numbers.end());
}

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    size_t newSize = std::distance(begin, end);
    if (this->storage.size() + newSize > this->N)
        throw Span::FullStorageException();
    this->storage.insert(this->storage.end(), begin, end);
}

 // Je trie le stockage puis je trouve la plus petite différence entre les éléments adjacents, 
 // ce qui est la méthode correcte pour trouver le plus court intervalle.
 // De même, dans longestSpan, j'utilise std::min_element et std::max_element pour trouver l'intervalle.

int Span::shortestSpan()
{
	if (this->storage.size() <= 1)
	{
		throw Span::NotEnoughNumbersException();
		return (-1);
	}

	std::vector<int> tmp = this->storage;
	std::sort(tmp.begin(), tmp.end());

	int shortest = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < shortest)
			shortest = tmp[i] - tmp[i - 1];
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (this->storage.size() <= 1)
	{
		throw Span::NotEnoughNumbersException();
		return (-1);
	}
	std::vector<int>::iterator min = std::min_element(this->storage.begin(), this->storage.end());
    std::vector<int>::iterator max = std::max_element(this->storage.begin(), this->storage.end());

    return (*max - *min);
}

void Span::autoFill()
{
	this->storage.resize(this->N);
	std::generate(this->storage.begin(), this->storage.end(), &getRandomNumber);
	std::sort(this->storage.begin(), this->storage.end());
}

const char* Span::FullStorageException::what() const throw()
{
	return ("Storage is full");
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers to calculate span");
}

std::ostream &operator<<(std::ostream &out, Span const &span)
{
	out << std::endl << "<< content >> ";
	for (unsigned int i = 0; i < span.getStorage().size(); i++)
	{
		out << span.getStorage()[i];
		if (i < span.getStorage().size() - 1)
			out << " ";
	}
	out << std::endl << std::endl << "<<  size   >> " << span.getN() << std::endl;
	return (out);
}
