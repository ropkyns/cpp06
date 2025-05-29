/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:08:04 by paulmart          #+#    #+#             */
/*   Updated: 2025/05/28 17:26:01 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

int main(void)
{
	t_data	goat;

	goat._name = "Romain";
	goat._age = 19;
	goat._favNumber = 28;
	goat.next = NULL;
	

	t_data	someone;

	someone._name = "Mike";
	someone._age = 35;
	someone._favNumber = 100;
	someone.next = &goat;

	std::cout << "Goat : " << std::endl << "Adresse : " << &goat << std::endl << "Name : " << goat._name << std::endl << "Age : " << goat._age << std::endl
	<< "Favorite Number : " << goat._favNumber << std::endl << "Next : " << goat.next << std::endl << std::endl;
	std::cout << "Someone : " << std::endl << "Adresse : " << &someone << std::endl << "Name : " << someone._name << std::endl << "Age : " << someone._age << std::endl
	<< "Favorite Number : " << someone._favNumber << std::endl << "Next : " << someone.next << std::endl << std::endl;

	t_data	*serGoat = Serializer::deserialize(Serializer::serialized(&goat));
	t_data	*serSomeone = Serializer::deserialize(Serializer::serialized(&someone));

	std::cout << "Goat : " << std::endl << "Adresse : " << serGoat << std::endl << "Name : " << serGoat->_name << std::endl << "Age : " << serGoat->_age << std::endl
	<< "Favorite Number : " << serGoat->_favNumber << std::endl << "Next : " << serGoat->next << std::endl << std::endl;
	std::cout << "Someone : " << std::endl << "Adresse : " << serSomeone << std::endl << "Name : " << serSomeone->_name << std::endl << "Age : " << serSomeone->_age << std::endl
	<< "Favorite Number : " << serSomeone->_favNumber << std::endl << "Next : " << serSomeone->next << std::endl << std::endl;

	uintptr_t raw = Serializer::serialized(&goat);
	std::cout << "Serialized pointer adress : " << raw << std::endl << std::endl;

	t_data *ptrRaw = Serializer::deserialize(raw);
	std::cout << "Deserialized raw ptr : " << std::endl << "Adresse : " << ptrRaw << std::endl << "Name : " << ptrRaw->_name << std::endl << "Age : " << ptrRaw->_age << std::endl
	<< "Favorite Number : " << ptrRaw->_favNumber << std::endl << "Next : " << ptrRaw->next << std::endl << std::endl;
}