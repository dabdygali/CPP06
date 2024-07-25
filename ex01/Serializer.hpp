/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:59:14 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/25 15:05:40 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _SERIALIZER_HPP_
	#define _SERIALIZER_HPP_

	#include <stdint.h>
	#include "DataStruct.hpp"
	
	class Serializer
	{
		private:
			Serializer();
			Serializer(const Serializer &src);
			Serializer	&operator=(const Serializer &src);
		public:
			virtual ~Serializer();
			static uintptr_t	serialize(Data* ptr);
			static Data*		deserialize(uintptr_t raw);
	};
#endif
