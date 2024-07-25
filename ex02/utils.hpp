/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:08:16 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/25 16:15:48 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _UTILS_HPP_
	#define _UTILS_HPP_

	#include "Base.hpp"

	Base	*generate(void);
	void	identify(Base* p);
	void	identify(Base& p);
#endif
