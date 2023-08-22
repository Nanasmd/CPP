/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:57:41 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:57:49 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class Brain{
private:
	std::string ideas[100];

public:
	Brain();
	virtual ~Brain();
	Brain(Brain const &src);
	Brain &operator=(Brain const &src);
	void setIdeas(int i, std::string idea);
	void printIdeas() const;
};

#endif