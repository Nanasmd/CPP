/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:29:34 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:29:37 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main(void)
{
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    sp.showElement();

    std::cout << std::endl;
    std::cout << "---memory error test----" << std::endl;
    try
    {
        sp.addNumber(12);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "---int min, max test----" << std::endl;
    Span sp2 = Span(2);
    sp2.addNumber(-2147483648);
    sp2.addNumber(2147483647);
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    std::cout << std::endl;
    std::cout << "---Better addNumber----" << std::endl;
    Span sp3 = Span(10);
    int arr[] = {0, 2, 4, 6, 8, 7, 12, 15, 25, 1};
    try
    {
        sp3.addNumbers(arr, 10);
        sp3.showElement();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << sp3.shortestSpan() << std::endl;
        std::cout << sp3.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "---at least 10000----" << std::endl;
    Span sp4 = Span(100000);
    int arr2[100000];
    for (int i = 0 ;i < 100000; i++)
        arr2[i] = i;
    try
    {
        sp4.addNumbers(arr2, 100000);
        //sp4.showElement();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << sp4.shortestSpan() << std::endl;
        std::cout << sp4.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}