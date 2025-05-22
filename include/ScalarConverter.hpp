/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:15:10 by paulmart          #+#    #+#             */
/*   Updated: 2025/05/22 18:10:46 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCLARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stdexcept>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &S);
		~ScalarConverter();
		ScalarConverter &operator= (const ScalarConverter &S);
	public:
		static void		convert(std::string const &arg);
		static int		argType(std::string const &arg);
		static void		charFunction(std::string const &arg);
		static void		intFunction(std::string const &arg);
		static void		floatFunction(std::string const &arg);
		static void		doubleFunction(std::string const &arg);
};


#endif