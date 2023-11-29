/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:40:35 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/14 14:18:21 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <iterator>

class Span {
    private:
        unsigned int N;
        std::vector<int> storage;

    public:
        Span();
        Span(Span const &other);
        Span(unsigned int N);
        ~Span();

        Span &operator=(Span const &other);

        unsigned int getN() const;
        std::vector<int> getStorage() const;

        void addNumber(int number);
        void addNumbers(const std::vector<int>& numbers);
        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end);

        int shortestSpan();
        int longestSpan();
        void autoFill();

        class FullStorageException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NotEnoughNumbersException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Span const &span);

// #pragma once

// #include <iostream>
// #include <algorithm>
// #include <iomanip>
// #include <string>
// #include <vector>
// #include <numeric>

// class Span {
// 	private:
// 		unsigned int N;
// 		std::vector<int> storage;
		
// 	public:
// 		Span();
// 		Span(Span const &other);
// 		Span(unsigned int N);
// 		~Span();
		
// 		Span &operator=(Span const &other);

// 		unsigned int getN() const;
// 		std::vector<int> getStorage() const;

// 		void addNumber(int number);
// 		int shortestSpan();
// 		int longestSpan();
// 		void autoFill();		

// 		class FullStorageException : public std::exception
// 		{
// 			public:
// 				virtual const char* what() const throw();
// 		};

// 		class NotEnoughNumbersException : public std::exception
// 		{
// 			public:
// 				virtual const char* what() const throw();
// 		};
// };

// std::ostream &operator<<(std::ostream &out, Span const &span);


