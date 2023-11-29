/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:39:34 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 15:39:35 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	
	public:
		Array(): _size(0)
		{
			std::cout << "create an empty default Array" << std::endl; 
			this->_array = new T[this->_size];
		}
		
		Array(unsigned int n) : _size(n)
		{
			std::cout << "create Array with " << this->_size << " slots" << std::endl; 
			this->_array = new T[this->_size];
		}
		
		Array(Array const &other) : _size(other._size)
		{
			std::cout << "create copy Array from other" << std::endl; 
			this->_array = NULL;
			*this = other;
		}
		
		~Array()
		{
			std::cout << "destroy Array of size " << this->_size << std::endl;
			if (this->_array)
				delete [] this->_array;
		}

		Array &operator=(Array const &other)
		{
			std::cout << "assign Array to other" << std::endl;
			if (this->_array)
				delete [] this->_array;
			if (other.size() > 0)
			{
				this->_size = other.size();
				this->_array = new T[other.size()];
				for (unsigned int i = 0; i < other.size(); i++)
					this->_array[i] = other._array[i];
			}
			return (*this);
		}
		
		T &operator[](unsigned int index)
		{
			if (index >= this->_size || this->_array == NULL)
			{
				std::cout << "Invalid access to index " << index << ": ";
				throw Array<T>::OutOfLimitsException();
			}
			return (this->_array[index]);
		}

		unsigned int size() const{return (this->_size);}

		class OutOfLimitsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};	
};

template <typename T>
char const *Array<T>::OutOfLimitsException::what() const throw()
{
	return ("Out of limits");
}
