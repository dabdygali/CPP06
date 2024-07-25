/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:16:21 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/25 16:47:11 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>
#include "utils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int		i;
	
	srand(time(NULL));
	i = rand();
	switch(i % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "Object is of A class" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "Object is of B class" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "Object is of C class" << std::endl;
		return;
	}
	std::cout << "Object is nether A, B or C" << std::endl;
	return;
}

void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "(Reference)Object is of A class" << std::endl;
		return;
	}
	catch(std::exception &e)
	{
	}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "(Reference)Object is of B class" << std::endl;
		return;
	}
	catch(std::exception &e)
	{
	}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "(Reference)Object is of C class" << std::endl;
		return;
	}
	catch(std::exception &e)
	{
	}
}
