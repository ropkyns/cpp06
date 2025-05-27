/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:07:57 by paulmart          #+#    #+#             */
/*   Updated: 2025/05/27 16:09:07 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer : Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &S)
{
	*this = S;
	std::cout << "Serializer : Copy constructor called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer : Destructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &S)
{
	if (this == &S)
		return (*this);
	return(*this);
}

uintptr_t	Serializer::serialized(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}