/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:43:50 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/25 16:48:30 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "utils.hpp"

int	main()
{
	Base	*ptr;

	ptr = generate();
	if(!ptr)
	{
		std::cerr << "Error" << std::endl;
		return EXIT_FAILURE;
	}
	identify(ptr);
	identify(*ptr);
	delete	ptr;
	return EXIT_SUCCESS;
}
