/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:15:47 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/25 15:34:25 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Serializer.hpp"

int	main()
{
	Data		d;
	Data		*ptr;
	uintptr_t	iptr;

	d.i_data = 42;
	iptr = Serializer::serialize(&d);
	ptr = Serializer::deserialize(iptr);

	std::cout << "Address of Data variable:	" << &d << std::endl;
	std::cout << "Pointer after serialization:	" << ptr << std::endl;
	return EXIT_SUCCESS;
}
