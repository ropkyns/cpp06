/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:15:10 by paulmart          #+#    #+#             */
/*   Updated: 2025/05/26 15:15:02 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stdexcept>
#include <iomanip>
#include <limits>

enum Type {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &S);
		~ScalarConverter();
		ScalarConverter &operator= (const ScalarConverter &S);
	public:
		static void		convert(std::string const &arg);
};

#endif