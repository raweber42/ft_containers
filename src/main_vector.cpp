/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:08 by raweber           #+#    #+#             */
/*   Updated: 2022/12/16 17:04:21 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <unistd.h>
#include <cstdio>
#include <stdlib.h>
#include "../inc/colors.hpp"

#if STD //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "../inc/vector.hpp"
	#include "../inc/map.hpp"
	#include "../inc/stack.hpp"
#endif

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

void print_values(ft::vector<int> &v1) {
	
	std::cout << "The values held by the vector are (accessed via iterator): [ ";
	for (ft::vector<int>::const_iterator it = v1.begin(); it != v1.end(); it++)
	{
		std::cout << *it << " ";
		fflush(stdout);
		usleep(80000);
	}
	std::cout << "]" << std::endl << std::endl;
}

void print_values_reversed(ft::vector<int> v1) {
	
	std::cout << "The values held by the vector are (accessed via REVERSE iterator): [ ";
	for (ft::vector<int>::const_reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
	{
		std::cout << *it << " ";
		fflush(stdout);
		usleep(80000);
	}
	std::cout << "]" << std::endl << std::endl;
}

int main(void) {

	std::cout << std::endl << COLOR_YELLOW << "######################## INTEGER VECTOR ###############################" << COLOR_DEFAULT << std::endl;
	usleep(500000);
	std::cout << COLOR_RED <<  "CONSTRUCTOR TESTS" << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_BLUE << "Initializing empty vector v1" << COLOR_DEFAULT << std::endl;
	ft::vector<int> v1;
	print_values(v1);
	
	std::cout << COLOR_BLUE << "Initializing vector v2 with 5 values of '2' via 'v2(5, 2)'" << COLOR_DEFAULT  << std::endl;
	ft::vector<int> v2(5, 2); // WITHOUT TYPECASTING (enable_if!)	
	print_values(v2);

	std::cout << COLOR_BLUE << "Initializing vector v3 with iterator range via 'v3(v2.begin() + 1, v2.end() - 1)'" << COLOR_DEFAULT  << std::endl;
	ft::vector<int> v3(v2.begin() + 1, v2.end() - 1);
	print_values(v3);

	// std::cout << COLOR_BLUE << "Initializing vector v4 via copy constructor via 'v4(v3)'" << COLOR_DEFAULT  << std::endl;
	// ft::vector<int> v4(v3);
	// print_values(v4);

	std::cout << COLOR_BLUE << "Initializing vector v5 via assignment 'v5 = v2'" << COLOR_DEFAULT  << std::endl;
	ft::vector<int> v5 = v2;
	print_values(v5);
	usleep(500000);
	
	usleep(500000);
	int test_size = 20;
	std::cout << COLOR_RED <<  "PUSH TO AND POP FROM V1" << COLOR_DEFAULT << std::endl;
	std::cout << "Current capacity is: " << v1.capacity() << " | current size is: " << v1.size() << std::endl;
	std::cout << COLOR_BLUE << "Pushing integers 0 - " << (test_size - 1) << " to v1" << COLOR_DEFAULT;
	for (int i = 0; i < 5; i++)
	{
		std::cout << " .";
		fflush(stdout);
		usleep(200000);
	}
	std::cout << std::endl;
	for (int i = 0; i < test_size; i++)
	{
		v1.push_back(i);
	}
	std::cout << "Current capacity is: " << v1.capacity() << " | current size is: " << v1.size() << std::endl;
	print_values(v1);
	print_values_reversed(v1);

	std::cout << COLOR_BLUE <<  "Popping half of the values from v1" << COLOR_DEFAULT;
	for (int i = 0; i < (test_size/2); i++)
	{
		std::cout << " .";
		fflush(stdout);
		v1.pop_back();
		usleep(200000);
	}
	std::cout << std::endl;
	std::cout << "Current capacity is: " << v1.capacity() << " | current size is: " << v1.size() << std::endl;
	print_values(v1);
	usleep(500000);


	usleep(500000);
	std::cout << COLOR_RED <<  "TESTS FOR ELEMENT ACCESS" << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_BLUE << "Get first value via ' v1.front()'" << COLOR_DEFAULT << std::endl;
	std::cout << "First value is: " << v1.front() << std::endl;
	std::cout << COLOR_BLUE << "Get last value via 'v1.back()'" << COLOR_DEFAULT << std::endl;
	std::cout << "Last value is: " << v1.back() << std::endl;
	std::cout <<  COLOR_BLUE << "Get first value via 'v1.at(0)'" << COLOR_DEFAULT << std::endl;
	std::cout << "Value is: " << v1.at(0) << std::endl;
	std::cout <<  COLOR_BLUE << "Get first value via 'v1[0]'" << COLOR_DEFAULT << std::endl;
	std::cout << "Value is: " << v1[0] << std::endl;
	std::cout <<  COLOR_BLUE << "Get pointer to first container element via 'v1.data()'" << COLOR_DEFAULT << std::endl;
	std::cout << "Address is: " << v1.data() << " which holds the value of " << *v1.data() << std::endl << std::endl;
	usleep(500000);


	usleep(500000);
	std::cout << COLOR_RED <<  "TESTS FOR CAPACITY FUNCTIONS" << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_BLUE << "Check if container is empty via 'v1.empty()'" << COLOR_DEFAULT << std::endl;
	std::cout << "Function returns: " << ((v1.empty()) ? "TRUE" : "FALSE") << std::endl;
	std::cout << COLOR_BLUE << "Get size of vector via 'v1.size()'" << COLOR_DEFAULT << std::endl;
	std::cout << "Current size is is: " << v1.size() << std::endl;
	std::cout <<  COLOR_BLUE << "Get max size of vector via 'max_size()'" << COLOR_DEFAULT << std::endl;
	std::cout << "Max size is: " << v1.max_size() << std::endl;
	std::cout <<  COLOR_BLUE << "Get capacity of vector via 'v1.capacity()'" << COLOR_DEFAULT << std::endl;
	std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	std::cout <<  COLOR_BLUE << "Try calling 'v1.reserve(5)' (should NOT increase capacity)" << COLOR_DEFAULT << std::endl;
	try {
		v1.reserve(5);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	std::cout <<  COLOR_BLUE << "Try calling 'v1.reserve(50)' (SHOULD increase capacity)" << COLOR_DEFAULT << std::endl;
	try {
		v1.reserve(50);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Current capacity is: " << v1.capacity() << std::endl << std::endl;
	usleep(500000);


	usleep(500000);
	std::cout << COLOR_RED <<  "TESTS FOR MODIFIER FUNCTIONS" << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_BLUE << "Resize the vector via v1.resize(5)" << COLOR_DEFAULT << std::endl;
	v1.resize(5);
	std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	print_values(v1);
	std::cout << COLOR_BLUE << "Resize the vector via v1.resize(10, 5)" << COLOR_DEFAULT << std::endl;
	v1.resize(10, 5);
	std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	print_values(v1);
	
	std::cout << COLOR_BLUE << "Insert one elements of value '77' at the beginning of the vector via 'v1.insert(v1.begin(), 77)'" << COLOR_DEFAULT << std::endl;
	std::cout << "Current capacity is: " << v1.capacity() << " | current size is: " << v1.size() << std::endl;
	v1.insert(v1.begin(), 77);
	print_values(v1);
	std::cout << COLOR_BLUE << "Insert 5 elements of value '66' at the beginning of the vector via 'v1.insert(v1.begin(), 5, 66)'" << COLOR_DEFAULT << std::endl;
	v1.insert(v1.begin(), 5, 66); // ENABLE_IF!
	print_values(v1);
	std::cout << COLOR_BLUE << "Insert the first three elements of value v2 at the beginning of the vector via 'v1.insert(v1.begin(), v2.begin(), v2.begin() + 3)'" << COLOR_DEFAULT << std::endl;
	v1.insert(v1.begin(), v2.begin(), v2.begin() + 3);
	print_values(v1);
	
	std::cout << COLOR_BLUE << "Erase the first element at the beginning of the vector via calling 'v1.erase(v1.begin())'" << COLOR_DEFAULT << std::endl;
	for (int i = 0; i < 5; i++)
		v1.erase(v1.begin());
	print_values(v1);
	std::cout << COLOR_BLUE << "Erase the first four element at the beginning of the vector via calling 'v1.erase(v1.begin(), v1.begin() + 4)'" << COLOR_DEFAULT << std::endl;
	v1.erase(v1.begin(), v1.begin() + 4);
	print_values(v1);
	std::cout << COLOR_BLUE << "Swap v1 and v2 via v1.swap(v2)" << COLOR_DEFAULT << std::endl;
	v1.swap(v2);
	std::cout << "Print values of v1:" << std::endl;
	print_values(v1);
	std::cout << "Print values of v2:" << std::endl;
	print_values(v2);
	std::cout << COLOR_BLUE << "Swap them back via v2.swap(v1)" << COLOR_DEFAULT << std::endl;
	v2.swap(v1);
	std::cout << "Print values of v1:" << std::endl;
	print_values(v1);
	std::cout << "Print values of v2:" << std::endl;
	print_values(v2);
	std::cout << COLOR_BLUE << "Clear the vector via v1.clear()" << COLOR_DEFAULT << std::endl;
	v1.clear();
	std::cout << "Current size is is: " << v1.size() << std::endl;
	std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	print_values(v1);
	std::cout << COLOR_BLUE << "Assign v2 to v1 via v1.assign(v2.begin(), v2.end())" << COLOR_DEFAULT << std::endl;
	v1.assign(v2.begin(), v2.end());
	std::cout << "Current size is is: " << v1.size() << std::endl;
	std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	print_values(v1);
	std::cout << COLOR_BLUE << "Assign nine values of '99' to v1 via v1.assign(9, 99)" << COLOR_DEFAULT << std::endl;
	v1.assign(9, 99);
	std::cout << "Current size is is: " << v1.size() << std::endl;
	std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	print_values(v1);
	usleep(500000);


	usleep(500000);
	std::cout << COLOR_RED <<  "TESTS FOR RELATIONAL OPERATORS" << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_BLUE << "Compare v1 and v2" << COLOR_DEFAULT << std::endl;
	std::cout << "Printing v1: ";
	print_values(v1);
	std::cout << "Printing v2: ";
	print_values(v2);
	std::cout << "Printing v5: ";
	print_values(v5);
	std::cout << COLOR_BLUE << "Compare v1 and v2" << COLOR_DEFAULT << std::endl;
	std::cout << "Is 'v1 == v2' (should return false)? " << COLOR_BLUE << ((v1 == v2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 'v1 != v2' (should return true)? " << COLOR_BLUE << ((v1 != v2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 'v1 < v2' (should return false)? " << COLOR_BLUE << ((v1 < v2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 'v1 <= v2' (should return false)? " << COLOR_BLUE << ((v1 <= v2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 'v1 > v2' (should return true)? " << COLOR_BLUE << ((v1 > v2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 'v1 >= v2' (should return true)? " << COLOR_BLUE << ((v1 >= v2) ? "true" : "false") << COLOR_DEFAULT << std::endl;

	std::cout << COLOR_BLUE << "Compare v2 and v5" << COLOR_DEFAULT << std::endl;
	std::cout << "Is 'v2 == v5' (should return true)? " << COLOR_BLUE << ((v2 == v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 'v2 != v5' (should return false)? " << COLOR_BLUE << ((v2 != v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 'v2 < v5' (should return false)? " << COLOR_BLUE << ((v2 < v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 'v2 <= v5' (should return true)? " << COLOR_BLUE << ((v2 <= v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 'v2 > v5' (should return false)? " << COLOR_BLUE << ((v2 > v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 'v2 >= v5' (should return true)? " << COLOR_BLUE << ((v2 >= v5) ? "true" : "false") << COLOR_DEFAULT << std::endl  << std::endl;
	usleep(500000);




	// std::cout << COLOR_YELLOW << "//######################## STRING VECTOR ######################################" << COLOR_DEFAULT << std::endl;
	// std::cout << std::endl << "Checking string vector" << std::endl;
	// ft::vector<std::string> vector_str;

	// std::cout << COLOR_YELLOW << "//######################## CUSTOM STRUCT VECTOR ###############################" << COLOR_DEFAULT << std::endl;

	// std::cout << std::endl << "Checking custom struct vector" << std::endl;
	// ft::vector<Buffer> vector_buffer;
	

	return (0);
}



// add constructor tests and non-member-functions!
// test change of dereferenced pointer (is overload dauerhaft modifying ?)
// ----> { b=a; *a++; *b; } also stuff like this. See test cases: https://cplusplus.com/reference/iterator/
// check all iterator operator overloads!!! (need vector with incrementing numbers inside -> wait until push_back works)

// use std::find for testing (and container::find)

// ------ ITERATOR OVERLOAD