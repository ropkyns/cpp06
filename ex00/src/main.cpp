/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:15:03 by paulmart          #+#    #+#             */
/*   Updated: 2025/05/23 15:48:03 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cout << "Error : you need one argument, a char, a int, a float or a double" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
