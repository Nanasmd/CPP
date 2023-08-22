/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:32:56 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:33:29 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <iterator>
# include <algorithm>
# include <stack>
# include <vector>
# include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	~MutantStack() {}
	MutantStack(MutantStack const &src)
	{
		*this = src;
	}
	MutantStack &operator=(MutantStack const &src)
	{
		this->c =src->c;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() {
		return this->c.begin();
	}

	iterator end(){
		return this->c.end();
	}
};
#endif