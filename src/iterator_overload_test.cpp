/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_overload_test.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:51:05 by raweber           #+#    #+#             */
/*   Updated: 2022/11/15 10:52:38 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <unistd.h>
#include <cstdio>
#include <stdlib.h>
#include "../inc/colors.hpp"
#include "../inc/vector.hpp"
#include "../inc/map.hpp"
#include "../inc/stack.hpp"
	
int main(void) {

	ft::vector<int> v2(size_t(5), int(5)); // WITHOUT TYPECASTING (enable_if!)
	// temp
	// for (ft::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	// 	std::cout << "value is: " << *it << std::endl;
	ft::vector<int>::iterator it = v2.begin();
	ft::vector<int>::iterator it2 = it;
	ft::vector<int>::iterator it3(it2);
	it++;
	it2++;
	it3++;
	++it;
	++it2;
	++it3;
	it--;
	it2--;
	it3--;
	--it;
	--it2;
	--it3;
	std::cout << "All still the same '==': " << ((it == it2) ? "True" : "false") << ((it == it3) ? "True" : "false") << ((it3 == it2) ? "True" : "false") << std::endl;
	std::cout << "All still the same '==': " << ((it != it2) ? "false" : "True") << ((it != it3) ? "false" : "True") << ((it3 != it2) ? "false" : "True") << std::endl;
	std::cout << "value at *it: " << *it << std::endl;
	std::cout << "value at *it++: " << *it++ << std::endl;
	std::cout << "value at *it2: " << *it2 << std::endl;
	std::cout << "value at *it2++: " << *it2++ << std::endl;
	ft::vector<int>::iterator empty_it;
	std::cout << "value at *(it + 4): " << *(it + 4) << std::endl;
	std::cout << "value at *(it + 4): " << *(it - 4) << std::endl;
	std::cout << "it < it3 ? " << ((it < it3) ? "True" : "false") << std::endl;
	std::cout << "it <= it3 ? " << ((it <= it3) ? "True" : "false") << std::endl;
	std::cout << "it > it3 ? " << ((it > it3) ? "True" : "false") << std::endl;
	std::cout << "it >= it3 ? " << ((it >= it3) ? "True" : "false") << std::endl;
	std::cout << "value at *(it += 1): " << *(it += 1) << std::endl;
	std::cout << "value at *(it += 1): " << *(it -= 1) << std::endl;
	std::cout << "value at it[1]: " << it[1] << std::endl;
	//temp
}