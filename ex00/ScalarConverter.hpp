/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:53:36 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/24 09:53:50 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _SCALARCONVERTER_HPP_
	#define _SCALARCONVERTER_HPP_
	
	#include <string>

	enum	e_type
	{
		e_char,
		e_int,
		e_float,
		e_double,
		e_error
	};
	
	class	ScalarConverter
	{
		private:
			// Constructors
			ScalarConverter();
			ScalarConverter(const ScalarConverter &src);

			// Operators
			ScalarConverter	&operator=(const ScalarConverter &rhs);
			
		public:
			// Destructors
			~ScalarConverter();

			// Actions
			static void	convert(const std::string &str);
	};
	
	#endif
