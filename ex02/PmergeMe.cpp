/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:02:27 by mneri             #+#    #+#             */
/*   Updated: 2024/02/21 16:15:51 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isNumber(char* str) {
    while (*str) {
        if (!std::isdigit(*str)) {
            return false;
        }
        ++str;
    }
    return true;
}

int initialize_container(char **arg, int argc, std::list<unsigned int> *list, std::vector<unsigned int> *vec)
{
	int value;
	
    for (int i = 1; i < argc; i++)
    {
        value = std::atoi(arg[i]);
		if(value < 0 || !isNumber(arg[i]))
			return 0;
        list->push_back(value);
    }
    for (int i = 1; i < argc; i++)
    {
        value = std::atoi(arg[i]);
        vec->push_back(value);
    }
    std::cout << "\033[1;31mBefore : ";
    for (std::list<unsigned int>::iterator it = list->begin(); it != list->end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
	return 1;
}

static std::vector<unsigned int> mergeVector(std::vector<unsigned int> &left, std::vector<unsigned int> &right)
{
	std::vector<unsigned int> result;

    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    while (!left.empty())
	{
        result.push_back(left.front());
        left.erase(left.begin());
    }
    while (!right.empty())
	{
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

static std::vector<unsigned int> mergeInsertionSortVEC(std::vector<unsigned int>& vec)
{
	if (vec.size() <= 1)
		return vec;
	
	int mid = vec.size() / 2;
	std::vector<unsigned int> left(vec.begin(), vec.begin() + mid);
	std::vector<unsigned int> right(vec.begin() + mid, vec.end());

	left = mergeInsertionSortVEC(left);
	right = mergeInsertionSortVEC(right);

	return mergeVector(left, right);
}

std::vector<unsigned int> sortVec(std::vector<unsigned int>& vec)
{
	std::vector<unsigned int> result;
	std::clock_t start = std::clock();
	result = mergeInsertionSortVEC(vec);
	std::clock_t end = std::clock();
	std::cout << "\033[1;32mAfter: ";
	for(std::vector<unsigned int>::iterator it = result.begin(); it != result.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
    double duration = static_cast<double>(end - start) / static_cast<double>CLOCKS_PER_SEC * 100000;
	std::cout << "\033[0mTime to process a range of " << result.size() << " elements with std::vector : " << duration << "us" << std::endl;
	return result;
}


static std::list<unsigned int> mergeList(std::list<unsigned int> &left, std::list<unsigned int> &right)
{
	std::list<unsigned int> result;

    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    while (!left.empty())
	{
        result.push_back(left.front());
        left.erase(left.begin());
    }
    while (!right.empty())
	{
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

static std::list<unsigned int> mergeInsertionSortLIST(std::list<unsigned int>& list)
{
	if (list.size() <= 1)
		return list;
	
	int mid = list.size() / 2;
	std::list<unsigned int> left;
	std::list<unsigned int> right;

	for(int i = 0; i < mid; i++)
	{
		left.push_back(list.front());
		list.pop_front();
	}
	right = list;
	left = mergeInsertionSortLIST(left);
	right = mergeInsertionSortLIST(right);

	return mergeList(left, right);
}

std::list<unsigned int> sortList(std::list<unsigned int>& vec)
{
	std::list<unsigned int> result;
	std::clock_t start = std::clock();
	result = mergeInsertionSortLIST(vec);
	std::clock_t end = std::clock();
    double duration = static_cast<double>(end - start) / static_cast<double>CLOCKS_PER_SEC * 100000;
	std::cout << "Time to process a range of " << result.size() << " elements with std::list : " << duration << "us" << std::endl;
	return result;
}
