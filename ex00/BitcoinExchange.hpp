/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:37 by mneri             #+#    #+#             */
/*   Updated: 2024/02/19 15:07:18 by mneri            ###   ########.fr       */
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
#include <limits.h>
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
void found(BTC btc, std::string value_str, std::string date_str);
void not_found(BTC btc, std::string value_str, std::string date_str);

