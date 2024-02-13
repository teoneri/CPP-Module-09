/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcointExchange.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:29 by mneri             #+#    #+#             */
/*   Updated: 2024/02/12 17:37:52 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BTC::BTC(const std::string &file_name)
{
	std::ifstream db_file;
	std::string line;
	std::istringstream iss(line);
    std::string date;
    double value;
	db_file.open(file_name.c_str());
    while (std::getline(db_file, line)) 
	{
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

void txtDB(char *filename, std::map<std::string, double> *db)
{
	
	std::ifstream infile;
	std::string line;
	std::istringstream iss(line);
    std::string date;
    double value;
	infile.open(filename);
	while (std::getline(infile, line)) 
	{

        if (std::getline(iss, date, '|') && iss >> value)
            db[date] = value;
		else 
            std::cerr << "Error parsing line: " << line << std::endl;
    }
	infile.close();
}
