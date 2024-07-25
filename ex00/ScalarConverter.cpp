/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:43:16 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/25 10:30:39 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <stdexcept>
#include <sstream>
#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	static_cast<void>(src);
}

// Operators
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

// Destructors
ScalarConverter::~ScalarConverter()
{
}

// Helper functions
bool	isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	isDouble(const std::string &str)
{
	long unsigned int	i;
	
	if (str.empty() || str.length() < 3)
		return false;
	if (!str.compare("+inf") || !str.compare("-inf") || !str.compare("nan"))
		return true;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!isDigit(str[i]))
		return false;
	while (i < str.length() && isDigit(str[i]))
		i++;
	if (i < str.length() && str[i] == '.')
		i++;
	else
		return false;
	if (!isDigit(str[i]))
		return false;
	while (i < str.length() && isDigit(str[i]))
		i++;
	if (i == str.length())
		return true;
	return false;
}

bool	isFloat(const std::string &str)
{
	long unsigned int	i;
	
	if (str.empty() || str.length() < 4)
		return false;
	if (!str.compare("+inff") || !str.compare("-inff") || !str.compare("nanf"))
		return true;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!isDigit(str[i]))
		return false;
	while (i < str.length() && isDigit(str[i]))
		i++;
	if (i < str.length() && str[i] == '.')
		i++;
	else
		return false;
	if (!isDigit(str[i]))
		return false;
	while (i < str.length() && isDigit(str[i]))
		i++;
	if (i == str.length() - 1 && str[i] == 'f')
		return true;
	return false;
}

bool	isInt(const std::string &str)
{
	long unsigned int	i;

	if (str.empty())
		return false;
	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str.length() > 1)
		i++;
	while (i < str.length())
	{
		if (!isDigit(str[i]))
			return false;
		i++;
	}
	return true;
}

e_type	categorizeString(const std::string &str)
{
	if (str.length() == 1 && !isDigit(str[0]))
		return e_char;
	if (isInt(str))
		return e_int;
	if (isFloat(str))
		return e_float;
	if (isDouble(str))
		return e_double;
	return e_error;
}

// Actions
void	ScalarConverter::convert(const std::string &str)
{
	char				c;
	int					i;
	float				f;
	double				d;
	std::istringstream	sin(str);

	switch(categorizeString(str))
	{
		case e_char:
			c = str[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case e_int:
			sin >> i;
			if (sin.fail())
			{
				std::cout << "Given value cannot be represented as int" << std::endl;
				return;
			}
			if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
				c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		case e_float:
			if (!str.compare("+inff"))
				f = std::numeric_limits<float>::infinity();
			else if (!str.compare("-inff"))
				f = -std::numeric_limits<float>::infinity();
			else if (!str.compare("nanf"))
				f = std::numeric_limits<float>::quiet_NaN();
			else
			{
				sin >> f;
				if (sin.fail())
				{
					std::cout << "Given value cannot be represented as float" << std::endl;
					return;
				}
			}
			if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
				c = static_cast<char>(f);
			if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
				i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		case e_double:
			if (!str.compare("+inf"))
				d = std::numeric_limits<double>::infinity();
			else if (!str.compare("-inf"))
				d = -std::numeric_limits<double>::infinity();
			else if (!str.compare("nan"))
				d = std::numeric_limits<double>::quiet_NaN();
			else
			{
				sin >> d;
				if (sin.fail())
				{
					std::cout << "Given value cannot be represented as double" << std::endl;
					return;
				}
			}
			if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
				c = static_cast<char>(d);
			if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
				i = static_cast<int>(d);
			if ((d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max()) \
			|| d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity() || d == std::numeric_limits<double>::quiet_NaN())
				f = static_cast<float>(d);
			break;
		default:
			std::cout << "Input is not recognized as char/int/float/double" << std::endl;
			return;
	}
	
	// Printing char
	std::cout << "char: ";
	if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
	{
		if (c >= ' ' && c <= '~')
			std::cout << '\'' << c << '\'' << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	
	// Printing int
	std::cout << "int: ";
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;
	
	// Printing float
	std::cout << "float: ";
	if ((d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max()) \
	|| d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity() || d == std::numeric_limits<double>::quiet_NaN())
		std::cout << f << std::endl;
	else
		std::cout << "impossible" << std::endl;
	
	// Printing double
	std::cout << "double: " << d << std::endl;
}
