/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:06:38 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/17 21:25:23 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

bool			isFloat(std::string s)
{
	int		i = 0;

	while (std::isdigit(s[i]))
		i++;
	return (s[i] == '.');
}

bool			checkFrontOperator(std::string &expr, int &index)
{
	if (!index)
		return (false);

	int		i = index - 1;

	while (i && std::isspace(expr[i]))
		i--;
	if (std::isdigit(expr[i]))
		while (((i - 1) >= 0) && (std::isdigit(expr[i - 1]) || (expr[i - 1] == '.')))
			i--;
	else if (expr[i] == ')')
	{
		for (int parenthesisCount = 1; parenthesisCount;)
		{
			if (--i < 0)
				return (false);
			else if (expr[i] == ')')
				parenthesisCount++;
			else if (expr[i] == '(')
				parenthesisCount--;
		}
	}
	else
		return (false);
	if (expr[index] == '*' || expr[index] == '/')
	{
		expr.insert(expr.begin() + i, '(');
		index++;
	}
	return (true);
}

bool			checkBackOperator(std::string &expr, int &index)
{
	int		i = index + 1;

	while (std::isspace(expr[i]))
		i++;
	if (std::isdigit(expr[i]))
		while (expr[i] && (std::isdigit(expr[i]) || expr[i] == '.'))
			i++;
	else if (expr[i] == '(')
	{
		for (int parenthesisCount = 1; parenthesisCount;)
		{
			if (!expr[++i])
				return (false);
			if (expr[i] == '(')
				parenthesisCount++;
			else if (expr[i] == ')')
				parenthesisCount--;
		}
	}
	else
		return (false);
	if (expr[index] == '*' || expr[index] == '/')
		expr.insert(expr.begin() + i, ')');
	return (true);
}

inline bool		checkOperator(std::string &expr, int &i)
{
	return (checkFrontOperator(expr, i) && checkBackOperator(expr, i));
}

bool			checkExpr(std::string &expr, int i = 0, bool checkParenthesis = false)
{
	int		parenthesisCount = 1;
	int		createdParenthesis = 0;

	if (expr.find_first_not_of(" \t\n\v\f\r()+-*/.0123456789") != std::string::npos)
		return (false);
	while (expr[i])
	{
		while (std::isspace(expr[i]))
			i++;
		if (std::isdigit(expr[i]))
		{
			while (std::isdigit(expr[i]))
				i++;
			if (expr[i] == '.')
			{
				do
					i++;
				while (std::isdigit(expr[i]));
				if (expr[i] == '.')
					return (false);
			}
			while (expr[i] && (std::string("+-*/").find_first_of(expr[i]) == std::string::npos))
			{
				if (std::isdigit(expr[i]) || (expr[i] == '('))
					return (false);
				i++;
			}
			continue ;
		}
		else if (expr[i] == '(')
		{
			if (!checkExpr(expr, i + 1, true))
				return (false);
			while (parenthesisCount)
			{
				if (!expr[++i])
					return (false);
				else if (expr[i] == '(')
					parenthesisCount++;
				else if (expr[i] == ')')
					parenthesisCount--;
			}
		}
		else if (std::string("+-*/").find_first_of(expr[i]) != std::string::npos)
		{
			if ((expr[i] == '*') || (expr[i] == '/'))
				createdParenthesis++;
			if (!checkOperator(expr, i))
				return (false);
		}
		else if (expr[i] == '.')
			return (false);
		else if (expr[i] == ')')
		{
			if (createdParenthesis)
			{
				createdParenthesis--;
				i++;
				continue ;
			}
			if (checkParenthesis)
				return (true);
			return (false);
		}
		i++;
	}
	return (true);
}

Fixed			atofixed(std::string s)
{
	Fixed	nb;

	if (isFloat(s))
		nb = Fixed((float)std::atof(s.c_str()));
	else
		nb = Fixed(std::atoi(s.c_str()));
	return (nb);
}

Fixed			getResult(std::string expr, int i = 0)
{
	Fixed	result;
	char	flag = 0;

	while (expr[i])
	{
		while (std::isspace(expr[i]))
			i++;
		if (std::isdigit(expr[i]))
		{
			if (!flag)
				result = atofixed(&expr[i]);
			else if (flag == '+')
				result += atofixed(&expr[i]);
			else if (flag == '-')
				result -= atofixed(&expr[i]);
			else if (flag == '*')
				result *= atofixed(&expr[i]);
			else if (flag == '/')
				result /= atofixed(&expr[i]);
		}
		while (std::isdigit(expr[i]) || expr[i] == '.')
			i++;
		if (expr[i] == '(')
		{
			if (!flag)
				result = getResult(expr, i + 1);
			else if (flag == '+')
				result += getResult(expr, i + 1);
			else if (flag == '-')
				result -= getResult(expr, i + 1);
			else if (flag == '*')
				result *= getResult(expr, i + 1);
			else if (flag == '/')
				result /= getResult(expr, i + 1);
			for (int parenthesisCount = 1; parenthesisCount;)
			{
				if (!expr[++i])
					return (false);
				else if (expr[i] == '(')
					parenthesisCount++;
				else if (expr[i] == ')')
					parenthesisCount--;
			}
		}
		else if (expr[i] == ')')
			return (result);
		if (std::string("+-*/").find_first_of(expr[i]) != std::string::npos)
			flag = expr[i];
		i++;
	}
	return (result);
}

int				main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "Error: enter an expression" << std::endl;
	for (int i = 1; i < argc; i++)
	{
		std::string		expr(argv[i]);

		if (!checkExpr(expr))
			std::cout << "Error: wrong expression" << std::endl;
		else
			std::cout << expr << std::endl << getResult(expr) << std::endl;
	}
	return (0);
}
