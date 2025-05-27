/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:14:57 by paulmart          #+#    #+#             */
/*   Updated: 2025/05/27 16:08:47 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int		argType(std::string const &arg);
void	charConversion(std::string const &arg);
void	intConversion(std::string const &arg);
void	floatConversion(std::string const &arg);
void	doubleConversion(std::string const &arg);


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

void	ScalarConverter::convert(const std::string &arg)
{
	if (arg.compare("-inf") == 0 || arg.compare("+inf") == 0 || arg.compare("inf") == 0 ||
		arg.compare("nan") == 0 || arg.compare("nanf") == 0 ||
		arg.compare("inff") == 0 || arg.compare("-inff") == 0 || arg.compare("+inff") == 0)
	{
		std::cerr << "Char : impossible" << std::endl << "Int : impossible" << std::endl;
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
	switch (argType(arg))
	{
		case TYPE_CHAR:
			charConversion(arg);
		break;
		case TYPE_INT:
			intConversion(arg);
			break;
		case TYPE_FLOAT:
			floatConversion(arg);
			break;
		case TYPE_DOUBLE:
			doubleConversion(arg);
			break;
		case TYPE_INVALID:
			std::cerr << "Invalid type, try only with a char, a int, a float or a double." << std::endl;
			break;
	}
	return ;
}

bool	isInt(std::string const &arg)
{
	long long i;
	std::istringstream iss(arg);
	iss >> std::noskipws >> i;
	return (iss.eof() && !iss.fail());
}

bool	isFloat(std::string const &arg)
{
	if (arg.empty() || arg[arg.size() - 1] != 'f')
		return (false);
	std::istringstream iss(arg.substr(0, arg.size() - 1));
	float f;
	iss >> std::noskipws >> f;
	return (iss.eof() && !iss.fail());
}

bool	isDouble(std::string const &arg)
{
	if (arg.empty() || arg[arg.length()] == 'f' || arg.find('.') == arg.npos)
		return (false);
	std::istringstream iss(arg);
	double d;
	iss >> std::noskipws >> d;
	return (iss.eof() && !iss.fail());
}

int	argType(std::string const &arg)
{
	if (arg.length() == 1 && !std::isdigit(arg[0]) && std::isprint(arg[0]))
		return (TYPE_CHAR);
	else if (isInt(arg) == true)
		return (TYPE_INT);
	else if (isFloat(arg) == true)
		return (TYPE_FLOAT);
	else if (isDouble(arg) == true)
		return (TYPE_DOUBLE);
	else 
		return (TYPE_INVALID);
}

void	charConversion(std::string const &arg)
{
	std::cout << "Char : '" << arg[0] << "'" << std::endl;
	std::cout << "Int : " << static_cast<int>(arg[0]) << std::endl;
	std::cout << "Float : " << std::fixed << std::setprecision(1) << static_cast<float>(arg[0]) << "f" << std::endl;
	std::cout << "Double : " << std::fixed << std::setprecision(1) << static_cast<double>(arg[0]) << std::endl;
}

void	intConversion(std::string const &arg)
{
	long long i = 0;
	std::istringstream iss(arg);
	iss >> std::noskipws >> i;
	if (i >= INT_MIN && i <= INT_MAX)
	{
		if (i >= 0 && i <= 255)
		{
			if(std::isprint(static_cast<unsigned char>(i)))
				std::cout << "Char : '" << static_cast<char>(i) << "'" << std::endl;
			else
				std::cerr << "Char : Non displayable" << std::endl;
		}
		else
			std::cerr << "Char : impossible" << std::endl;
		std::cout << "Int : " << i << std::endl;
		std::cout << "Float : " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
		std::cout << "Double :" << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
	}
	else
		std::cerr << "Overflow, please try again" << std::endl;
}

bool floatFractionalPart(float value)
{
	float intpart;
	return (std::modf(value, &intpart) != 0.0f);
}

void	floatConversion(std::string const &arg)
{
	float f = 0.f;
	std::istringstream iss(arg.substr(0, arg.size() - 1));
	iss >> std::noskipws >> f;
	if(f <= __FLT_MAX__ && f >= __FLT_MIN__)
	{
		if (f >= 0 && f <= 255 && floatFractionalPart(f) == false)
		{
			if(std::isprint(static_cast<unsigned char>(f)))
				std::cout << "Char : '" << static_cast<char>(f) << "'" << std::endl;
			else
				std::cerr << "Char : Non displayable" << std::endl;
		}
		else
			std::cerr << "Char : impossible" << std::endl;
		if (f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min())
			std::cout << "Int : " << static_cast<int>(f) << std::endl;
		else
			std::cerr << "Int : out of range" << std::endl;
		if (floatFractionalPart(f))
		{
			std::cout << "Float : " << f << "f" << std::endl;
			std::cout << "Double : " << static_cast<double>(f) << std::endl;
		}
		else
		{
			std::cout << "Float : " << std::fixed << std::setprecision(5) << f << "f" << std::endl;
			std::cout << "Double : " << std::fixed << std::setprecision(5) << static_cast<double>(f) << std::endl;
		}
	}
	else
		std::cerr << "Overflow, please try again" << std::endl;
}

bool doubleFractionalPart(double value)
{
	double intpart;
	return (std::modf(value, &intpart) != 0.0);
}

void	doubleConversion(std::string const &arg)
{
	double d = 0.;
	std::istringstream iss(arg);
	iss >> std::noskipws >> d;
	char* endptr = NULL;
	std::strtod(arg.c_str(), &endptr);
	if (endptr != arg.c_str() && *endptr == '\0')
	{
		if (d >= 0 && d <= 255 && doubleFractionalPart(d) == false)
		{
			if(std::isprint(static_cast<unsigned char>(d)))
				std::cout << "Char : '" << static_cast<char>(d) << "'" << std::endl;
			else
				std::cerr << "Char : Non displayable" << std::endl;
		}
		else
			std::cerr << "Char : impossible" << std::endl;
		if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min())
			std::cout << "Int : " << static_cast<int>(d) << std::endl;
		else
			std::cerr << "Int : out of range" << std::endl;
		if (doubleFractionalPart(d))
		{
			std::cout << "Float : "  << static_cast<float>(d) << "f" << std::endl;
			std::cout << "Double : " << d << std::endl;
		}
		else
		{
			std::cout << "Float : " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
			std::cout << "Double : " << std::fixed << std::setprecision(1) << d << std::endl;
		}
	}
	else
		std::cerr << "Overflow, please try again" << std::endl;
}
