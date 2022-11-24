/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:08 by raweber           #+#    #+#             */
/*   Updated: 2022/11/24 17:47:12 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <unistd.h>
#include <cstdio>
#include <stdlib.h>
#include "../inc/colors.hpp"

// #if STD //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
// #else
// 	#include "../inc/vector.hpp"
// 	#include "../inc/map.hpp"
// 	#include "../inc/stack.hpp"
// #endif

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

void print_values(ft::map<std::string, std::string> &v1) {
	
	std::cout << "The values held by the map are (accessed via iterator): [ ";
	for (ft::map<std::string, std::string>::const_iterator it = v1.begin(); it != v1.end(); it++)
	{
		std::cout << " (" << it->first << ")->[" << it->second << "] ";
		fflush(stdout);
		usleep(80000);
	}
	std::cout << "]" << std::endl << std::endl;
}

void print_values_reversed(ft::map<std::string, std::string> v1) {
	
	std::cout << "The values held by the map are (accessed via REVERSE iterator): [ ";
	for (ft::map<std::string, std::string>::const_reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
	{
		std::cout << " (" << it->first << ")->[" << it->second << "] ";
		fflush(stdout);
		usleep(80000);
	}
	std::cout << "]" << std::endl << std::endl;
}

int main(void) {

	std::cout << std::endl << COLOR_YELLOW << "######################## MAP<STD::STRING, STD::STRING> ###############################" << COLOR_DEFAULT << std::endl;
	usleep(500000);
	std::cout << COLOR_RED <<  "CONSTRUCTOR TESTS" << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_BLUE << "Initializing empty map v1" << COLOR_DEFAULT << std::endl;
	ft::map<std::string, std::string> v1;
	print_values(v1);
	
	std::cout << COLOR_BLUE << "Inserting three key->value pairs into v1 via 'v2.insert(std::pair<key_type, value_type>(key, value))'" << COLOR_DEFAULT  << std::endl;
	v1.insert(std::pair<std::string, std::string>("1", "ABC"));
	v1.insert(std::pair<std::string, std::string>("2", "DEF"));
	v1.insert(std::pair<std::string, std::string>("3", "GHI"));
	print_values(v1);

	// std::cout << COLOR_BLUE << "Initializing map v2 with iterator range via 'v2(v1.begin(), v1.end() - 1)'" << COLOR_DEFAULT  << std::endl;
	// ft::map<std::string, std::string> v2(v1.begin(), v1.end() - 1);
	// print_values(v2);

	std::cout << COLOR_BLUE << "Initializing map v3 via copy constructor via 'v3(v1)' //CHANGE TO V2!!" << COLOR_DEFAULT  << std::endl;
	ft::map<std::string, std::string> v3(v1);
	print_values(v3);

	std::cout << COLOR_BLUE << "Initializing map v4 via assignment 'v4 = v3'" << COLOR_DEFAULT  << std::endl;
	ft::map<std::string, std::string> v4 = v3;
	print_values(v4);
	usleep(500000);
	
	// usleep(500000);
	// std::cout << COLOR_RED <<  "GET ALLOCATOR TYPE" << COLOR_DEFAULT << std::endl;
	// std::cout << "v1.get_allocator() returns: " << v1.get_allocator() << std::endl;
	// usleep(500000);
	
	usleep(500000);
	std::cout << COLOR_RED <<  "INSERTING AND ERASING INTO/FROM V1" << COLOR_DEFAULT << std::endl;
	std::cout << "Current size is: " << v1.size() << std::endl;
	std::cout << COLOR_BLUE << "Pushing alphabetic key->value pairs to v1" << COLOR_DEFAULT;
	v1.insert(std::pair<std::string, std::string>("4", "JKL"));
	std::cout << " .";
	fflush(stdout);
	usleep(200000);
	v1.insert(std::pair<std::string, std::string>("5", "MNO"));
	std::cout << " .";
	fflush(stdout);
	usleep(200000);
	v1.insert(std::pair<std::string, std::string>("6", "PQR"));
	std::cout << " .";
	fflush(stdout);
	usleep(200000);
	v1.insert(std::pair<std::string, std::string>("7", "STU"));
	std::cout << " .";
	fflush(stdout);
	usleep(200000);
	v1.insert(std::pair<std::string, std::string>("8", "VWX"));
	std::cout << " .";
	fflush(stdout);
	usleep(200000);
	v1.insert(std::pair<std::string, std::string>("9", "YZ"));
	std::cout << "Current size is: " << v1.size() << std::endl;
	std::cout << " .";
	fflush(stdout);
	usleep(200000);
	print_values(v1);
	print_values_reversed(v1);

	std::cout << COLOR_BLUE <<  "Erase first three pairs from v1" << COLOR_DEFAULT;
	ft::map<std::string, std::string>::iterator it = v1.begin();
	for (int i = 0; i < 4; i++)
	{
		std::cout << " .";
		fflush(stdout);
		v1.erase(it++);
		usleep(200000);
	}
	std::cout << std::endl;
	std::cout << "Current size is: " << v1.size() << std::endl;
	print_values(v1);
	usleep(500000);


	// usleep(500000);
	// std::cout << COLOR_RED <<  "TESTS FOR ELEMENT ACCESS" << COLOR_DEFAULT << std::endl;
	// std::cout << COLOR_BLUE << "Get first value via ' v1.front()'" << COLOR_DEFAULT << std::endl;
	// std::cout << "First value is: " << v1.front() << std::endl;
	// std::cout << COLOR_BLUE << "Get last value via 'v1.back()'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Last value is: " << v1.back() << std::endl;
	// std::cout <<  COLOR_BLUE << "Get first value via 'v1.at(0)'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Value is: " << v1.at(0) << std::endl;
	// std::cout <<  COLOR_BLUE << "Get first value via 'v1[0]'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Value is: " << v1[0] << std::endl;
	// std::cout <<  COLOR_BLUE << "Get pointer to first container element via 'v1.data()'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Address is: " << v1.data() << " which holds the value of " << *v1.data() << std::endl << std::endl;
	// usleep(500000);


	// usleep(500000);
	// std::cout << COLOR_RED <<  "TESTS FOR CAPACITY FUNCTIONS" << COLOR_DEFAULT << std::endl;
	// std::cout << COLOR_BLUE << "Check if container is empty via 'v1.empty()'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Function returns: " << ((v1.empty()) ? "TRUE" : "FALSE") << std::endl;
	// std::cout << COLOR_BLUE << "Get size of map via 'v1.size()'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Current size is is: " << v1.size() << std::endl;
	// std::cout <<  COLOR_BLUE << "Get max size of map via 'max_size()'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Max size is: " << v1.max_size() << std::endl;
	// std::cout <<  COLOR_BLUE << "Get capacity of map via 'v1.capacity()'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	// std::cout <<  COLOR_BLUE << "Try calling 'v1.reserve(5)' (should NOT increase capacity)" << COLOR_DEFAULT << std::endl;
	// try {
	// 	v1.reserve(5);
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	// std::cout <<  COLOR_BLUE << "Try calling 'v1.reserve(50)' (SHOULD increase capacity)" << COLOR_DEFAULT << std::endl;
	// try {
	// 	v1.reserve(50);
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// // std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	// // std::cout <<  COLOR_BLUE << "Try calling 'v1.reserve(999999999999999)' (should THROW EXCEPTION)" << COLOR_DEFAULT << std::endl;
	// // try {
	// // 	v1.reserve(99999999999999);
	// // }
	// // catch (std::exception &e) {
	// // 	std::cerr << e.what() << std::endl;
	// // }
	// // catch (std::bad_alloc &e) {
	// // 	std::cerr << e.what() << std::endl;
	// // }
	// std::cout << "Current capacity is: " << v1.capacity() << std::endl << std::endl;
	// usleep(500000);


	// usleep(500000);
	// std::cout << COLOR_RED <<  "TESTS FOR MODIFIER FUNCTIONS" << COLOR_DEFAULT << std::endl;
	// std::cout << COLOR_BLUE << "Resize the map via v1.resize(5)" << COLOR_DEFAULT << std::endl;
	// v1.resize(5);
	// std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	// print_values(v1);
	// std::cout << COLOR_BLUE << "Resize the map via v1.resize(10, 5)" << COLOR_DEFAULT << std::endl;
	// v1.resize(10, 5);
	// std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	// print_values(v1);
	
	// std::cout << COLOR_BLUE << "Insert one elements of value '77' at the beginning of the map via 'v1.insert(v1.begin(), 77)'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Current size is: " << v1.size() << std::endl;
	// v1.insert(v1.begin(), 77);
	// print_values(v1);
	// std::cout << COLOR_BLUE << "Insert 5 elements of value '66' at the beginning of the map via 'v1.insert(v1.begin(), 5, 66)'" << COLOR_DEFAULT << std::endl;
	// v1.insert(v1.begin(), 5, 66); // ENABLE_IF!
	// print_values(v1);
	// std::cout << COLOR_BLUE << "Insert the first three elements of value v2 at the beginning of the map via 'v1.insert(v1.begin(), v2.begin(), v2.begin() + 3)'" << COLOR_DEFAULT << std::endl;
	// v1.insert(v1.begin(), v2.begin(), v2.begin() + 3);
	// print_values(v1);
	
	// std::cout << COLOR_BLUE << "Erase the first element at the beginning of the map via calling 'v1.erase(v1.begin())'" << COLOR_DEFAULT << std::endl;
	// for (int i = 0; i < 5; i++)
	// 	v1.erase(v1.begin());
	// print_values(v1);
	// std::cout << COLOR_BLUE << "Erase the first four element at the beginning of the map via calling 'v1.erase(v1.begin(), v1.begin() + 4)'" << COLOR_DEFAULT << std::endl;
	// v1.erase(v1.begin(), v1.begin() + 4);
	// print_values(v1);
	// std::cout << COLOR_BLUE << "Swap v1 and v2 via v1.swap(v2)" << COLOR_DEFAULT << std::endl;
	// v1.swap(v2);
	// std::cout << "Print values of v1:" << std::endl;
	// print_values(v1);
	// std::cout << "Print values of v2:" << std::endl;
	// print_values(v2);
	// std::cout << COLOR_BLUE << "Swap them back via v2.swap(v1)" << COLOR_DEFAULT << std::endl;
	// v2.swap(v1);
	// std::cout << "Print values of v1:" << std::endl;
	// print_values(v1);
	// std::cout << "Print values of v2:" << std::endl;
	// print_values(v2);
	// std::cout << COLOR_BLUE << "Clear the map via v1.clear()" << COLOR_DEFAULT << std::endl;
	// v1.clear();
	// std::cout << "Current size is is: " << v1.size() << std::endl;
	// std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	// print_values(v1);
	// std::cout << COLOR_BLUE << "Assign v2 to v1 via v1.assign(v2.begin(), v2.end())" << COLOR_DEFAULT << std::endl;
	// v1.assign(v2.begin(), v2.end());
	// std::cout << "Current size is is: " << v1.size() << std::endl;
	// std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	// print_values(v1);
	// std::cout << COLOR_BLUE << "Assign nine values of '99' to v1 via v1.assign(9, 99)" << COLOR_DEFAULT << std::endl;
	// v1.assign(9, 99);
	// std::cout << "Current size is is: " << v1.size() << std::endl;
	// std::cout << "Current capacity is: " << v1.capacity() << std::endl;
	// print_values(v1);
	// usleep(500000);

	

	// usleep(500000);
	// std::cout << COLOR_RED <<  "TESTS FOR RELATIONAL OPERATORS" << COLOR_DEFAULT << std::endl;
	// std::cout << COLOR_BLUE << "Compare v1 and v2" << COLOR_DEFAULT << std::endl;
	// std::cout << "Printing v1: ";
	// print_values(v1);
	// std::cout << "Printing v2: ";
	// print_values(v2);
	// std::cout << "Printing v5: ";
	// print_values(v5);
	// std::cout << COLOR_BLUE << "Compare v1 and v2" << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'v1 == v2' (should return true)? " << COLOR_BLUE << ((v1 == v2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'v1 != v2' (should return true)? " << COLOR_BLUE << ((v1 != v2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'v1 < v2' (should return false)? " << COLOR_BLUE << ((v1 < v2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'v1 <= v2' (should return false)? " << COLOR_BLUE << ((v1 <= v2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'v1 > v2' (should return false)? " << COLOR_BLUE << ((v1 > v2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'v1 >= v2' (should return false)? " << COLOR_BLUE << ((v1 >= v2) ? "true" : "false") << COLOR_DEFAULT << std::endl;

	// std::cout << COLOR_BLUE << "Compare v2 and v5" << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'v2 == v5' (should return false)? " << COLOR_BLUE << ((v2 == v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'v2 != v5' (should return true)? " << COLOR_BLUE << ((v2 != v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'v2 < v5' (should return false)? " << COLOR_BLUE << ((v2 < v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'v2 <= v5' (should return false)? " << COLOR_BLUE << ((v2 <= v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'v2 > v5' (should return true)? " << COLOR_BLUE << ((v2 > v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'v2 >= v5' (should return true)? " << COLOR_BLUE << ((v2 >= v5) ? "true" : "false") << COLOR_DEFAULT << std::endl  << std::endl;
	// usleep(500000);




	// std::cout << COLOR_YELLOW << "//######################## STRING VECTOR ######################################" << COLOR_DEFAULT << std::endl;
	// std::cout << std::endl << "Checking string map" << std::endl;
	// ft::map<std::string> map_str;

	// std::cout << COLOR_YELLOW << "//######################## CUSTOM STRUCT VECTOR ###############################" << COLOR_DEFAULT << std::endl;

	// std::cout << std::endl << "Checking custom struct map" << std::endl;
	// ft::map<Buffer> map_buffer;
	

	return (0);
}

// add constructor tests and non-member-functions!
// test change of dereferenced pointer (is overload dauerhaft modifying ?)
// ----> { b=a; *a++; *b; } also stuff like this. See test cases: https://cplusplus.com/reference/iterator/
// check all iterator operator overloads!!! (need map with incrementing numbers inside -> wait until push_back works)

// use std::find for testing (and container::find)

// ------ ITERATOR OVERLOAD