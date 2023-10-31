/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:12:39 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/25 18:08:58 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Fixed.hpp"
#include "Point.hpp"

#define GREY		"\033[90m"
#define PINK		"\e[0;38;5;199m"
#define LILAC		"\e[0;38;5;13m"
#define PURPLE		"\e[0;38;5;93m"
#define YELLOW		"\033[93m"
#define GREEN		"\033[92m"
#define RED			"\033[91m"
#define RESET		"\033[0m"
#define BOLD 		"\033[1m"
#define BOLD_RED	"\e[1;31m"

char	**createGrid(int height, int width)
{
	char** grid = new char*[height];
	
    for (int i = 0; i < height; i++)
	{
        grid[i] = new char[width];
	}
	return (grid);
}

void	deleteGrid(char** grid, int height)
{
	for (int i = 0; i < height; i++)
		delete[] grid[i];
	delete[] grid;
}

void drawTriangle(Point a, Point b, Point c, Point p, int mode)
{
	char	fill = 'X';
	char	empty = '.';
    Fixed	minX = Fixed::min(Fixed::min(a.getX(), b.getX()), c.getX());
    Fixed	maxX = Fixed::max(Fixed::max(a.getX(), b.getX()), c.getX());
    Fixed	minY = Fixed::min(Fixed::min(a.getY(), b.getY()), c.getY());
    Fixed	maxY = Fixed::max(Fixed::max(a.getY(), b.getY()), c.getY());
    int		width = maxX.toInt() - minX.toInt() + 3;
    int		height = maxY.toInt() - minY.toInt() + 3;

	char	**grid = createGrid(height, width);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
		{
            if (bsp(a, b, c, Point(x, y)))
                grid[y][x] = fill;
			else
           		grid[y][x] = empty;
		}
			
    }
    std::cout << "  ";
    for (int x = 0; x < width - 2; x++)
        std::cout << GREY << std::setfill('0') << std::setw(2) << x << " " << RESET;
    std::cout << std::endl;
    for (int y = 0; y < height - 2; y++)
    {
        std::cout << GREY << std::setfill('0') << std::setw(2) << y << " " << RESET;
        for (int x = 0; x < width - 2; x++)
        {
            if ((Fixed)x == p.getX() && (Fixed)y == p.getY() && grid[y][x] == fill && mode == 1)
                std::cout << BOLD << GREEN << "Y  " << RESET;
            else if ((Fixed)x == p.getX() && (Fixed)y == p.getY() && grid[y][x] != fill && mode == 1)
                std::cout << BOLD << RED << "N  " << RESET;
            else if (grid[y][x] == fill)
                std::cout << YELLOW << grid[y][x] << "  " << RESET;
			else
				std::cout << GREY << grid[y][x] << "  " << RESET;
        }
        std::cout << std::endl;
    }
	deleteGrid(grid, height);
}

void	mainHeader(void)
{
	std::cout << BOLD << "\033c";
	std::cout << BOLD << PINK << "****************************************************************" << RESET << std::endl;
	std::cout << BOLD << PINK << "*                              BSP                             *" << RESET << std::endl;
	std::cout << BOLD << PINK << "****************************************************************" << RESET << std::endl;
}

int main(void)
{
	Point a(10, 0);
	Point b(0, 30);
	Point c(20, 30);
	float x;
	float y;

	mainHeader();
	drawTriangle(a, b, c, Point(0, 0), 0);
	std::cout << "Enter an x and y value (x y): ";
	std::cin >> x >> y;
	if (std::cin.fail())
	{
		std::cout << BOLD << RED << "\n\tWrong input\n" << std::endl;
		return (EXIT_FAILURE);
	}
	mainHeader();
	drawTriangle(a, b, c, Point(x, y), 1);
	if (bsp(a, b, c, Point(x, y)))
		std::cout << GREEN << "\n\tThe position (" << x << "," << y << ") is inside the triangle" << RESET << std::endl << std::endl;
	else
		std::cout << RED << "\n\tThe position (" << x << "," << y << ") is outside the triangle" << RESET << std::endl << std::endl;
	return 0;
}
