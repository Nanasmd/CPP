/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:21:49 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 14:21:50 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <cstdlib>

class Brain
{
	private:
		std::string ideas[100];

	public:
		// Constructors
		Brain(void);
		Brain(Brain const &src);
		virtual ~Brain(void);
		
		// Operators
		Brain &operator=(Brain const &src);
		
		// Member functions
		void	showIdeas(void) const;
};

#endif
