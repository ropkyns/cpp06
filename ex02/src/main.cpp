/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:53:49 by paulmart          #+#    #+#             */
/*   Updated: 2025/06/02 10:22:45 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <typeinfo>

static Base	*generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		std::cout << "Generate : generating a new A class" << std::endl;
		return (new A());
		break;
	case 1:
		std::cout << "Generate : generating a new B class" << std::endl;
		return (new B());
		break;
	case 2:
		std::cout << "Generate : generating a new C class" << std::endl;
		return (new C());
		break;
	default :
		std::cerr << "Generate : fail generating." << std::endl;
		return (NULL);
	}
}

static void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Identify : this is a A class pointer !" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Identify : this is a B class pointer !" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Identify : this is a C class pointer !" << std::endl;
	else
		std::cerr << "Identify : fail identifying class pointer." << std::endl;
}

static void identify(Base &p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "Identify : this is a A class reference !" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "Identify : this is a B class reference !" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "Identify : this is a C class reference !" << std::endl;
	else
		std::cerr << "Identify : fail identifying class reference." << std::endl;
}

int main()
{
	int n = 3;
	for (int i = 0; i < n; ++i)
	{
		std::cout << "\n\t--- Test " << i + 1 << " ---" << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	std::cout << "\n\t--- Test fail ---" << std::endl;
	Base *fail = NULL;
	identify(*fail);
	delete fail;

	return (0);
}