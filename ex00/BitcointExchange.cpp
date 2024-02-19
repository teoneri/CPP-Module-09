/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcointExchange.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:29 by mneri             #+#    #+#             */
/*   Updated: 2024/02/19 15:07:26 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BTC::BTC(const std::string &file_name)
{
	std::ifstream db_file;
	std::string line;

	db_file.open(file_name.c_str());
    while (std::getline(db_file, line)) 
	{
    	double value;
		std::istringstream iss(line);
   		std::string date;
        if (std::getline(iss, date, ',') && iss >> value) 
            this->db[date] = value;
    }
	db_file.close();
}

BTC::BTC(const BTC &other) : db(other.db)
{
}

BTC &BTC::operator=(const BTC &other)
{
    if (this != &other)
    {
        this->db = other.db;
    }
    return *this;
}

BTC::~BTC()
{
}

BTC::BTC()
{
}

void found(BTC btc, std::string value_str, std::string date_str)
{
		double value = std::strtod(value_str.c_str(), NULL);

		if (value >= 0 && value < 2147483648)
		{
			std::cout << date_str << " => " << value_str << " = " << std::fixed << std::setprecision(2) << value * btc.db[date_str] << std::endl;
		}
		else if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
		}
		else
		{
			std::cerr << "Error: too large a number." << std::endl;
		}
}


void not_found(BTC btc, std::string value_str, std::string date_str)
{
		std::map<std::string, double>::iterator it = btc.db.lower_bound(date_str);
		if (it == btc.db.end() || it == btc.db.begin())
			std::cerr << "Error: Can't find date in DB" << std::endl;
		else
		{
			--it;
			double value = std::strtod(value_str.c_str(), NULL);
			if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if(value >= 2147483648)
				std::cerr << "Error: too large a number." << std::endl;
			else
				std::cout << date_str << " => " << value_str << " = " << std::fixed << std::setprecision(2) << value * it->second << std::endl;
		}
}

void displayBTC(std::string line, BTC btc)
{
	std::istringstream iss(line);
	std::string date_str;
	std::string value_str;

	if (std::getline(iss, date_str, '|') && std::getline(iss, value_str))
    {
        if (btc.db.find(date_str) != btc.db.end())
           found(btc, value_str, date_str);
        else
			not_found(btc, value_str, date_str);
    }
    else
        std::cerr << "Error: not a valid line format => " << line << std::endl;
}

