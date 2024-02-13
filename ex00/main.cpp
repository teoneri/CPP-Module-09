/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:16:45 by mneri             #+#    #+#             */
/*   Updated: 2024/02/12 17:36:00 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "invalid number of args" << std::endl;
	}
	const std::string file = "data.csv";
	BTC btc = BTC(file);
	std::map<std::string, double> file;
	txtDB(argv[1], file);
	
}