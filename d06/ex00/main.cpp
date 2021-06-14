/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <hrhirha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:47:18 by hrhirha           #+#    #+#             */
/*   Updated: 2021/06/14 17:09:37 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

void	convert(std::string s, dt &dt)
{
	if (isChar(s)) convertChar(s, dt);
	else if (isInt(s)) convertInt(s, dt);
	else if (isFloat(s)) convertFloat(s, dt);
	else if (isDouble(s)) convertDouble(s, dt);
	else
	{
		std::cout << "Unknown type\n";
		exit(1);
	}
}

void	display(std::string s, dt &dt)
{
	if (s == "+inff" || s == "-inff" || s == "nanf")
	{
		std::cout << "char: Impossible\n";
		std::cout << "int: Impossible\n";
		std::cout << "float: " << s << '\n';
		std::cout << "duoble: " << s.substr(0, s.size()-1) << '\n';
		return ;
	}
	else if (s == "+inf" || s == "-inf" || s == "nan")
	{
		std::cout << "char: Impossible\n";
		std::cout << "int: Impossible\n";
		std::cout << "float: " << s+"f" << '\n';
		std::cout << "duoble: " << s << '\n';
		return ;
	}
	std::cout << "char: ";
	if (dt.c == -1) std::cout << "Impossible\n";
	else if (dt.c == 0) std::cout << "Non displayable\n";
	else std::cout << '\'' << (char)dt.c << "'\n";
	std::cout << "int: ";
	if (dt.i == std::numeric_limits<int>::max() + 1) std::cout << "Impossible\n";
	else std::cout << dt.i << '\n';
	std::cout << "float: ";
	if (dt.f == std::numeric_limits<float>::max() + 1) std::cout << "Impossible\n";
	else std::cout << dt.f << ((dt.f - (int)dt.f == 0) ? ".0f" : "f") << '\n';
	std::cout << "double: ";
	std::cout << dt.d << ((dt.d - (int)dt.d == 0) ? ".0" : "") << '\n';
}

int	main(int ac, char **av)
{
	dt dt;

	if (ac !=2)
	{
		std::cout << "Usage: ./convert [char, int, float, double]\n";
		return (1);
	}
	convert(static_cast<std::string>(av[1]), dt);
	display(static_cast<std::string>(av[1]), dt);
}
