/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:16:45 by mneri             #+#    #+#             */
/*   Updated: 2024/02/13 17:02:40 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "invalid number of args" << std::endl;
		return 0;
	}
	const std::string file = "data.csv";
	const std::string input_file = argv[1];
	std::string line;

	BTC btc = BTC(file);
	std::ifstream fstream(input_file.c_str());
	while(std::getline(fstream, line))
	{
		displayBTC(line, btc);
	}
}