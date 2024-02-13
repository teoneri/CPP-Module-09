/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:37 by mneri             #+#    #+#             */
/*   Updated: 2024/02/13 16:39:59 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iomanip>

class BTC
{
	private:
		BTC();
	public:
		std::map<std::string, double> db;
		std::map<std::string, double> txt;
		BTC(const std::string &filename);
		BTC(const BTC &other); 
		BTC &operator=(const BTC &other);  
		~BTC();
};
void displayBTC(std::string line, BTC btc);

