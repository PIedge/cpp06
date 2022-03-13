/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:32:12 by tmerrien          #+#    #+#             */
/*   Updated: 2022/03/08 17:06:11 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <errno.h>

bool print_error(std::string msg)
{
	std::cout << msg << std::endl;
	return (true);
}

bool convert_to_char(double rep, std::string str)
{
	char c = static_cast<char>(std::atoi(str.c_str()));

	if (!str[1])
		c = static_cast<char>((char)str[0]);
	std::cout << "char: ";
	if (__isnan(rep) || __isinf(rep))
		return (print_error("impossible"));
	if (c < 33 || c > 126)
		return(print_error("Non displayable"));
	std::cout << c << std::endl;
	return (true);
}

bool convert_to_int(double rep, std::string str)
{
	int i = static_cast<int>(std::atoi(str.c_str()));

	// if (!str[1])
		// i = static_cast<int>((char)str[0]);
	std::cout << "int: ";
	if (__isnan(rep) || __isinf(rep))
		return (print_error("impossible"));
	std::cout << i << std::endl;
	return (true);
}

void convert_to_double(double rep, std::string str)
{
	str.~basic_string();
	// if (!str[1])
		// rep = static_cast<double>((char)str[0]);
	std::cout << "double: ";
	std::cout << rep << std::endl;
}

void convert_to_float(std::string str)
{
	float f = static_cast<float>(std::strtof(str.c_str(), NULL));

	// if (!str[1])
		// f = static_cast<float>((char)str[0]);
	std::cout << "float: ";
	std::cout << f << "f" << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Not enough or too much arguments" << std::endl;
		return (1);
	}

	double rep;
	std::string str;

	str = std::string(av[1]);
	rep = static_cast<double>(std::atof(str.c_str()));

	convert_to_char(rep, str);
	convert_to_int(rep, str);
	std::cout << std::fixed << std::setprecision(1);
	convert_to_float(str);
	convert_to_double(rep, str);
	return (1);
}