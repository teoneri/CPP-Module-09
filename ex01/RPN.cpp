/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:22 by mneri             #+#    #+#             */
/*   Updated: 2024/02/22 15:06:19 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	calculate_stack(std::stack<int> *stack, char *arg, int i)
{
		int val = stack->top();
		stack->pop();
		int val2 = stack->top();
		stack->pop();
		int result;
		switch (arg[i])
		{
			case '-':
				result = val2 - val;
				stack->push(result);
				break;
			case '+':
				result = val2 + val;
				stack->push(result);
				break;
			case '*':
				result = val2 * val;
				stack->push(result);
				break;
			case '/':
				if(val == 0)
					throw std::exception();
				result = val2 / val;
				stack->push(result);
				break;
			default:
				break;
		}
}

void parse_stack(char *arg)
{
	std::stack<int> stack;

	for(int i = 0; arg[i]; i++)
	{
		if(arg[i] >= '0' && arg[i] <= '9')
		{
			stack.push(arg[i] - 48);
			i++;
		}
		if(arg[i] == '-' || arg[i] == '+' || arg[i] == '*' || arg[i] == '/')
		{
			if(stack.size() >= 2)
			{	
				try
				{
					calculate_stack(&stack, arg, i);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << ": N / 0\n";
					return ;
				}
				i++;
			}
			else
			{
				std::cout << "Error" << std::endl;
				return ;
			}
		}
	}
		std::cout << stack.top() << std::endl;
}