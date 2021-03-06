/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:17:16 by tmerrien          #+#    #+#             */
/*   Updated: 2022/03/13 15:38:42 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.h"
#include <string>
#include <iostream>
#include <stdint.h>

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	Data d = Data(10);

	int i = 4;
	uintptr_t b = reinterpret_cast<uintptr_t>(&i);
	int *a = reinterpret_cast<int*>(b);
	std::cout << sizeof(i) << std::endl;
	std::cout << sizeof(*a) << std::endl;


	std::cout << "Data adress : " << &d << std::endl;
	std::cout << "before serialize : " << d.data << std::endl;

	uintptr_t ptr = serialize(&d);
	Data *result = deserialize(ptr);

	std::cout << "after deserialize : " << result << std::endl;
	std::cout << "Data adress : " << result->data << std::endl;

	std::cout << d.data << std::endl;
	std::cout << deserialize(serialize(&d))->data << std::endl;
	std::cout << sizeof(d) << std::endl;
	std::cout << sizeof(*deserialize(serialize(&d))) << std::endl;
	std::cout << &d << std::endl;
	std::cout << deserialize(serialize(&d)) << std::endl;
}