/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:12:27 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/17 18:35:35 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool isOverTheEdge(const Point p1, const Point p2, const Point p)
{
	Fixed slope((p1.getY() - p2.getY()) / (p1.getX() - p2.getX()));
	Fixed intercept(p1.getY() - slope * p1.getX());

	return (p.getY() == slope * p.getX() + intercept);
}

float getTriangleArea(const Point p1, const Point p2, const Point p3)
{
	Fixed first(p1.getX() * p2.getY() - p3.getX() * p2.getY());
	Fixed second(p3.getX() * p1.getY() - p1.getX() * p3.getY());
	Fixed third(p2.getX() * p3.getY() - p2.getX() * p1.getY());
	Fixed result(first + second + third);

	return (std::abs(result.toFloat()) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{	
	if (isOverTheEdge(a, b, point) || isOverTheEdge(b, c, point) || isOverTheEdge(c, a, point))
		return (false);

	float areaABC = getTriangleArea(a, b, c);
	float subABP = getTriangleArea(a, b, point);
	float subBCP = getTriangleArea(b, c, point);
	float subCAP = getTriangleArea(c, a, point);

	return (areaABC == subABP + subBCP + subCAP);
}
