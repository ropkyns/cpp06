/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:07:47 by paulmart          #+#    #+#             */
/*   Updated: 2025/05/28 17:23:53 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct Data
{
	std::string	_name;
	int			_age;
	size_t		_favNumber;
	Data		*next;
}				t_data;


class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &S);
		~Serializer();
		Serializer &operator= (const Serializer &S);
	public:
		static uintptr_t	serialized(Data *ptr);
		static t_data			*deserialize(uintptr_t raw);
};

#endif