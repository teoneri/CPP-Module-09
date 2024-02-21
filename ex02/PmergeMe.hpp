/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:02:20 by mneri             #+#    #+#             */
/*   Updated: 2024/02/21 16:05:17 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>
bool isNumber(char* str);
int initialize_container(char **arg, int argc, std::list<unsigned int> *list, std::vector<unsigned int> *vec);
std::vector<unsigned int> sortVec(std::vector<unsigned int>& vec);
std::list<unsigned int> sortList(std::list<unsigned int>& vec);

#endif // PMERGE_ME_HPP
