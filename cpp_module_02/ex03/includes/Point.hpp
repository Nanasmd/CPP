/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:12:23 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/31 14:07:55 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		// Constructors
		Point();
		Point(float const x, float const y);
		Point(Point const &copy);
		~Point();

		// Overload operators
		Point 	&operator=(Point const &copy);
		bool	operator==(Point const &copy) const;
		
		// Get / Set
		Fixed	getX() const;
		Fixed	getY() const;
		
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
