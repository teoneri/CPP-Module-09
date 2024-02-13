/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcointExchange.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:29 by mneri             #+#    #+#             */
/*   Updated: 2024/02/13 17:25:10 by mneri            ###   ########.fr       */
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
        else 
            std::cerr << "Error parsing line: " << line << std::endl;
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

void displayBTC(std::string line, BTC btc)
{
	std::istringstream iss(line);
	std::string date_str;
	std::string value_str;
	double value;

	if(std::getline(iss, date_str, '|') && std::getline(iss, value_str))
	{
		if(btc.db.find(date_str) != btc.db.end())
		{
			value = std::strtod(value_str.c_str(), NULL);
			std::cout << date_str << " => " << value_str << " = " << std::setprecision(2) <<  value * btc.db[date_str] << std::endl;
		}
		else
		{
			std::map<std::string, double>::iterator it = btc.db.lower_bound(date_str);
			if(it == btc.db.begin())
			{
				std::cerr << "Can't find date in DB" << std::endl;
			}
			else
			{
				--it;
				value = std::strtod(value_str.c_str(), NULL);
								std::cout << date_str << " => " << value_str << " = " << value * btc.db[date_str] << std::endl;
			}
		}
	}
	else
	{
		std::cerr << "Error: not a valid line format => " << line << std::endl;
	}
}