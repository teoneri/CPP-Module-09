/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:02:30 by mneri             #+#    #+#             */
/*   Updated: 2024/02/21 16:18:07 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector<unsigned int> vec;
	std::list<unsigned int> list;

	if(argc <= 1)
		return 0;
	if(!initialize_container(argv, argc, &list, &vec))
	{
		std::cout << "\033[1;31mError" << std::endl;
		return 0;
	}
	std::vector<unsigned int> sortedVec = sortVec(vec);
	std::list<unsigned int> sortedList = sortList(list);

}