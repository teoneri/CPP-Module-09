/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:37 by mneri             #+#    #+#             */
/*   Updated: 2024/02/12 17:37:56 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class BTC
{
	private:
		BTC();
	public:
		std::map<std::string, double> db;
		std::map<std::string, double> txt;
		BTC(const std::string &filename);
		BTC(const BTC &other);  // Copy constructor
		BTC &operator=(const BTC &other);  // Copy assignment operator
		~BTC();
};
void txtDB(char *filename, std::map<std::string, double> *db);

