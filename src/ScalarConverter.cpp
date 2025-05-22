/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:14:57 by paulmart          #+#    #+#             */
/*   Updated: 2025/05/22 18:21:00 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter : Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &S)
{
	*this = S;
	std::cout << "ScalarConverter : Copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter : Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &S)
{
	if (this == &S)
		return (*this);
	return(*this);
}

int	ScalarConverter::argType(std::string const &arg)
{
	if (arg.length() == 1 && !isdigit(arg[0]))
		return (0);
	else if (arg.find('f') == std::string::npos && arg.find('.') == std::string::npos)
		return (1);
	else if (arg.find('f') != std::string::npos)
		return (2);
	else if (arg.find('f') == std::string::npos && arg.find('.') != std::string::npos)
		return (3);
	else return (-1);
}

void	ScalarConverter::convert(const std::string &arg)
{
	if (arg == "-inf" || arg == "+inf" || arg == "inf" ||
		arg == "nan" || arg == "nanf"||
		arg == "inff" || arg == "-inff" || "-inff")
	{
		std::cout << "Char : impossible" << std::endl << "Int : impossible" << std::endl;
		if (arg == "nan" || arg == "nanf")
			std::cout << "Float : nanf" << std::endl << "Double : nan" << std::endl;
		else if (arg == "inf" || arg == "+inf" || arg == "-inf")
			std::cout << "Float : " << arg << "f" << std::endl << "Double : " << arg << std::endl;
		else
		{
			std::cout << "Float : " << arg << std::endl;
			std::cout << "Double : " << arg.substr(0, arg.length() - 1) << std::endl;
		}
		return ;
	}
	int ret = argType(arg);
	switch (ret)
	{
	case 0:
		//charFunction
		break;
	case 1:
		//intFunction
		break;
	case 2:
		//floatFunction
		break;
	case 3:
		//doubleFunction
		break;
	default:
		std::cout << "Invalid type" << std::endl;
		break;
	}
}

void	ScalarConverter::charFunction(std::string const &arg)
{
	
}