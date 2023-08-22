/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:36:02 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:36:09 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point	tr_sub(Point a, Point b)
{
	Point sub(a.get_x() - b.get_x(), a.get_y() - b.get_y());
	return sub;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point d1(tr_sub(b,a).get_x(), tr_sub(b,a).get_y());
	Point d2(tr_sub(c,a).get_x(), tr_sub(c,a).get_y());
	Point p(tr_sub(point,a).get_x(), tr_sub(point,a).get_y());

	Fixed t1(((p.get_x() * d2.get_y()) - (d2.get_x() * p.get_y())) / ((d1.get_x() * d2.get_x()) - (d1.get_y() * d2.get_x())));
	Fixed t2(((p.get_x() * d1.get_y()) - (d1.get_x() * p.get_y())) / ((d1.get_y() * d2.get_x()) - (d1.get_x() * d2.get_y())));	
	if ((t1 >= 0 && t1 <= 1) && (t2 >= 0 && t2 <= 1) && (t1 + t2 <= 1))
		return 1;
	return 0;
}