/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 07:27:49 by tmerrien          #+#    #+#             */
/*   Updated: 2022/03/13 15:32:26 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstdio>
#include <climits>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <errno.h>

int print_all(long long ll, double d, int i, char c, float f)
{
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d))
		std::cout << "impossible" <<std::endl;
	else if (c < 33 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << c << std::endl;
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) || \
		ll > INT_MAX || ll < INT_MIN)
		std::cout << "impossible" <<std::endl;
	else
		std::cout << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: ";
	if (ll > __FLT_MAX__ || ll < -__FLT_MAX__)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << "f" << std::endl;
	std::cout << "double: ";
	if (ll > __DBL_MAX__ || ll < -__DBL_MAX__)
		std::cout << "impossible" << std::endl;
	else
		std::cout << d << std::endl;
	return (0);
}

int convert_to_float(std::string str, long long ll)
{

	float f = std::strtof(str.c_str(), NULL);
	int i = static_cast<int>(f);
	char c = static_cast<char>(f);
	double d = static_cast<double>(f);
	return (print_all(ll, d, i, c, f));
}

int convert_to_double(std::string str, long long ll)
{
	double d = std::atof(str.c_str());
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	char c = static_cast<char>(d);
	return (print_all(ll, d, i, c, f));
}

int convert_to_int(std::string str, long long ll)
{
	int i = std::atoi(str.c_str());
	double d = static_cast<double>(i);
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	return (print_all(ll, d, i, c, f));
}

int convert_to_char(std::string str, long long ll)
{
	char c = str[0];
	double d = static_cast<double>(c);
	float f = static_cast<float>(c);
	int i = static_cast<int>(c);
	return (print_all(ll, d, i, c, f));
}

// void impossible(bool mode)
// {
// 	std::cout << "char: "
// }

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Not enough or too much arguments" << std::endl;
		return (1);
	}

	std::string str(av[1]);
	long long ll = std::atoll(str.c_str());
	if (str.length() == 1 && ((str[0] >= ' ' && str[0] <= '/') || (str[0] >= ':' && str[0] <= '~')))
		return (convert_to_char(str, ll));
	if (str.find("f", 1) != std::string::npos)
		return (convert_to_float(str, ll));
	if (str.find(".", 0) != std::string::npos || ll > INT_MAX || ll < INT_MIN || \
		str.find("nan") != std::string::npos || str.find("inf") != std::string::npos)
		return (convert_to_double(str, ll));
	return (convert_to_int(str, ll));
}