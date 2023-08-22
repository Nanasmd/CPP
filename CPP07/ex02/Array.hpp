/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:26:41 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:26:44 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array {
private:
	T *arr;
	unsigned int n;
public:
	Array(): arr(new T[0]), n(0){}
	~Array() {
		delete[] arr;
	}
	Array(unsigned int _n): arr(new T[_n]), n(_n){}
	Array(Array const &copy): arr(new T[copy.size()]), n(copy.size())
	{
		for (unsigned int i = 0;i < this->n ; i++)
			arr[i] = copy.arr[i];
	}
	Array	&operator=(Array const &src)
	{
		delete[] arr;
		arr = new T[src.size()];
		n = src.size();
		for (unsigned int i = 0; i < n; i++)
			arr[i] = src.arr[i];
	}

	unsigned int size() const {return n;}
	T &operator[](unsigned int const _n){
		if (_n < 0 || _n >= this->n)
			throw OutOfRange();
		return this->arr[_n];
	}

	class OutOfRange: public std::exception
	{
		public:
			virtual const char *what() const throw(){
				return "Error: Out of range.";
			}
	};
};

#endif