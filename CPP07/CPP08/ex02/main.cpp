/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:30:45 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:32:27 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

void    mutantStackExample(void)
{
    MutantStack<int>    mstack;

    mstack.push(5);
    mstack.push(17);
    
    std::cout << "before pop, top: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "after pop, top: " << mstack.top() << std::endl;
    std::cout << "size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(42);
    mstack.push(34);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while(it != ite)
    {
        std::cout << "element: " << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
 
}

void    mutantListExample(void)
{
    std::list<int>    mlist;

    mlist.push_back(5);
    mlist.push_back(17);
    
    std::cout << "before pop, top: " << mlist.back() << std::endl;

    mlist.pop_back();
    std::cout << "after pop, top: " << mlist.back() << std::endl;
    std::cout << "size: " << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(42);
    mlist.push_back(34);
    mlist.push_back(0);

    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();

    ++it;
    --it;
    while(it != ite)
    {
        std::cout << "element: " << *it << std::endl;
        ++it;
    }
    std::list<int> s(mlist);
}

int main(void)
{   
    mutantStackExample();
    std::cout << std::endl;
    mutantListExample();
    return 0;
}