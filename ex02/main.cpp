/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:02:38 by tmerrien          #+#    #+#             */
/*   Updated: 2022/03/13 15:45:08 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABC.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base *generate(void)
{
	int r = rand() % 3 + 1;
	if (r == 1)
	{
		std::cout << "A created" << std::endl;
		return (new A());
	}
	else if (r == 2)
	{
		std::cout << "B created" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "C created" << std::endl;
		return (new C());
	}
}

void identify(Base *p)
{
	std::cout << "object is of type: ";
	if(dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	std::cout << "object is of type: ";
	try
	{
		A &b = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		if (&b == &p)
			return;
		return;
	}
	catch (std::exception &e)
	{}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		if (&b == &p)
			return;
		return;
	}
	catch (std::exception &e)
	{}
	try
	{
		C &b = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		if (&b == &p)
			return;
		return;
	}
	catch (std::exception &e)
	{}
}

int main(void)
{
	srand(time(0));
	Base *p = generate();

	identify(p);
	identify(*p);
	delete p;
}