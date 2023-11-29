/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:40:48 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/23 18:15:15 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    MutantStack() {
        std::cout << "create MutantStack" << std::endl;
    }
    
    MutantStack(MutantStack const &other) {
        std::cout << "create copy MutantStack from other" << std::endl;
        *this = other;
    }
    
    ~MutantStack() {
        std::cout << "destroy MutantStack" << std::endl;
    }

    MutantStack &operator=(MutantStack const &other) {
        std::cout << "assign MutantStack to other" << std::endl;
        std::stack<T, Container>::operator=(other);
        return *this;
    }

    typedef typename Container::iterator iterator;
    
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

// #pragma once

// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <stack>
// #include <vector>
// #include <list>
// #include <deque>
// #include <algorithm>

// template <typename T, typename Container = std::deque<T> >
// class MutantStack : public std::stack<T, Container> {
// 	public:
// 		MutantStack() {
// 			std::cout << "create MutantStack" << std::endl;
// 		}
		
// 		MutantStack(MutantStack const &other) {
// 			std::cout << "create copy MutantStack from other" << std::endl;
// 			*this = other;
// 		}
		
// 		~MutantStack() {
// 			std::cout << "destroy MutantStack" << std::endl;
// 		}

// 		MutantStack &operator=(MutantStack const &other) {
// 			std::cout << "assign MutantStack to other" << std::endl;
// 			std::stack<T, Container>::operator=(this, other);
// 			return (*this);
// 		}

// 		typedef typename Container::iterator iterator;
		
// 		iterator begin(void){return (this->c.begin());}
// 		iterator end(void){return (this->c.end());}
// };
