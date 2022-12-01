/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:08 by raweber           #+#    #+#             */
/*   Updated: 2022/12/01 17:47:14 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <unistd.h>
#include <cstdio>
#include <stdlib.h>
#include "../inc/colors.hpp"

//temporary
#include "../inc/BST.hpp"
//temporary end

// #if STD //CREATE A REAL STL EXAMPLE
	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;

// #else
	#include "../inc/vector.hpp"
	#include "../inc/map.hpp"
	#include "../inc/stack.hpp"
// #endif

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

void print_values(ft::map<std::string, std::string> &m1) {
	
	std::cout << "The values held by the map are (accessed via iterator): [ ";
	
	for (ft::map<std::string, std::string>::const_iterator it = m1.begin(); it != m1.end(); it++)
	{
		std::cout << " (" << (*it).first << ")->[" << (*it).second << "] ";
		fflush(stdout);
		usleep(80000);
	}
	std::cout << "]" << std::endl << std::endl;
}

void print_values_reversed(ft::map<std::string, std::string> m1) {
	
	std::cout << "The values held by the map are (accessed via REVERSE iterator): [ ";
	for (ft::map<std::string, std::string>::const_reverse_iterator it = m1.rbegin(); it != m1.rend(); it++)
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
	std::cout << COLOR_BLUE << "Initializing empty map m1" << COLOR_DEFAULT << std::endl;
	ft::map<std::string, std::string> m1;
	for (int i = 0; i < 4; i++)
	{
		std::cout << ". ";
		fflush(stdout);
		usleep(200000);
	}
	std::cout << std::endl << COLOR_BLUE << "Inserting three key->value pairs into m1 via 'm1.insert(ft::pair<key_type, value_type>(key, value))'" << COLOR_DEFAULT  << std::endl;
	m1.insert(ft::pair<std::string, std::string>("1", "ABC"));
	m1.insert(ft::pair<std::string, std::string>("2", "DEF"));
	m1.insert(ft::pair<std::string, std::string>("3", "GHI"));
	print_values(m1);
	print_values_reversed(m1);

	// std::cout << COLOR_BLUE << "Initializing map m2 with iterator range via 'm2(m1.begin(), --m1.end())'" << COLOR_DEFAULT  << std::endl;
	// ft::map<std::string, std::string> m2(m1.begin(), --m1.end());
	// print_values(m2);

	// std::cout << COLOR_BLUE << "Initializing map m3 via copy constructor via 'm3(m1)' //CHANGE TO V2!!" << COLOR_DEFAULT  << std::endl;
	// ft::map<std::string, std::string> m3(m1);
	// print_values(m3);
	
	// std::cout << COLOR_BLUE << "Initializing map m4 via assignment 'm4 = m3'" << COLOR_DEFAULT  << std::endl;
	// ft::map<std::string, std::string> m4 = m3;
	// print_values(m4);
	// usleep(500000);
	
	// usleep(500000); // HOW TO TEST THIS????
	// std::cout << COLOR_RED <<  "GET ALLOCATOR TYPE" << COLOR_DEFAULT << std::endl;
	// std::cout << "m1.get_allocator() returns: " << m1.get_allocator() << std::endl;
	// usleep(500000);
	
	usleep(500000);
	std::cout << COLOR_RED <<  "INSERTING TEST ELEMENTS INTO/FROM M1" << COLOR_DEFAULT << std::endl;
	std::cout << "Size before is: " << COLOR_GREEN << m1.size() << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_BLUE << "Pushing alphabetic key->value pairs to m1" << COLOR_DEFAULT;
	m1.insert(ft::pair<std::string, std::string>("4", "JKL"));
	std::cout << " .";
	fflush(stdout);
	usleep(200000);
	m1.insert(ft::pair<std::string, std::string>("5", "MNO"));
	std::cout << " .";
	fflush(stdout);
	usleep(200000);
	m1.insert(ft::pair<std::string, std::string>("6", "PQR"));
	std::cout << " .";
	fflush(stdout);
	usleep(200000);
	m1.insert(ft::pair<std::string, std::string>("7", "STU"));
	std::cout << " .";
	fflush(stdout);
	usleep(200000);
	m1.insert(ft::pair<std::string, std::string>("8", "VWX"));
	std::cout << " .";
	fflush(stdout);
	usleep(200000);
	m1.insert(ft::pair<std::string, std::string>("9", "YZ"));
	std::cout << " .";
	fflush(stdout);
	usleep(200000);
	std::cout << std::endl << "Size after is: " << COLOR_GREEN << m1.size() << COLOR_DEFAULT << std::endl << std::endl;
	print_values(m1);
	usleep(500000);


	// usleep(500000);
	// std::cout << COLOR_RED <<  "TESTS FOR ELEMENT ACCESS" << COLOR_DEFAULT << std::endl;
	// std::cout <<  COLOR_BLUE << "Get first value via 'm1.at(\"1\")'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Value is: " << m1.at("1") << std::endl;
	// std::cout <<  COLOR_BLUE << "Get first value via 'm1[\"1\"]'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Value is: " << m1["1"] << std::endl;
	// std::cout << "Size before is: " << COLOR_GREEN << m1.size() << COLOR_DEFAULT << std::endl;
	// std::cout <<  COLOR_BLUE << "Get first value via 'm1[\"INSERTED\"]' ( WILL INSERT NEW ELEMENT WITHOUT VALUE (ONLY KEY) )" << COLOR_DEFAULT << std::endl;
	// std::cout << "Value is: " << m1["INSERTED"] << std::endl;
	// std::cout << "Size after is: " << COLOR_GREEN << m1.size() << COLOR_DEFAULT << std::endl << std::endl;
	// usleep(500000);


	// usleep(500000);
	// std::cout << COLOR_RED <<  "TESTS FOR CAPACITY FUNCTIONS" << COLOR_DEFAULT << std::endl;
	// std::cout << COLOR_BLUE << "Check if container is empty via 'm1.empty()'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Function returns: " << ((m1.empty()) ? "TRUE" : "FALSE") << std::endl;
	// std::cout << COLOR_BLUE << "Get size of map via 'm1.size()'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Current size is is: " << m1.size() << std::endl;
	// std::cout <<  COLOR_BLUE << "Get max size of map via 'm1.max_size()'" << COLOR_DEFAULT << std::endl;
	// std::cout << "Max size is: " << m1.max_size() << std::endl;
	// usleep(500000);

	
	usleep(500000);
	std::cout << COLOR_RED <<  "TESTS FOR MODIFIER FUNCTIONS" << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_BLUE << "Clear the map via m1.clear()" << COLOR_DEFAULT << std::endl;
	m1.clear();
	std::cout << "Current size is is: " << m1.size() << std::endl;
	print_values(m1);
	std::cout << COLOR_BLUE << "Insert one elements of value 'XXX' into the map via 'm1.insert(ft::pair<std::string, std::string>(\"X\", \"XXX\"))'" << COLOR_DEFAULT << std::endl;
	m1.insert(ft::pair<std::string, std::string>("X", "XXX"));
	print_values(m1);
	std::cout << COLOR_BLUE << "Insert value of '\?\?\?' as close as possible to the position just prior to m1.begin() via 'm1.insert(ft::pair<std::string, std::string>(\"?\", \"???\"))'" << COLOR_DEFAULT << std::endl;
	m1.insert(ft::pair<std::string, std::string>("?", "???"));
	print_values(m1);
	// // std::cout << COLOR_BLUE << "Insert the first three elements of value m2 at the beginning of the map via 'm1.insert(m2.begin(), m2.begin() + 3)'" << COLOR_DEFAULT << std::endl;
	// // m1.insert(m2.begin(), m2.begin() + 3);
	// // print_values(m1);
	// std::cout << COLOR_BLUE << "Erase the first element at the beginning of the map via calling 'm1.erase(m1.begin())'" << COLOR_DEFAULT << std::endl;
	// m1.erase(m1.begin());
	// print_values(m1);
	// // std::cout << COLOR_BLUE << "Erase the last two elements of the map via calling 'm1.erase(m1.end() - 3, m1.end() - 1)'" << COLOR_DEFAULT << std::endl;
	// // m1.erase(m1.end() - 3, m1.end() - 1);
	// // print_values(m1);
	// std::cout << COLOR_BLUE << "Erase the element with the key *1* via calling 'm1.erase(\"1\")' //---> CHECK THIS AGAIN!//" << COLOR_DEFAULT << std::endl;
	// m1.erase("1");
	// print_values(m1);
	// std::cout << COLOR_BLUE << "Swap m1 and m2 via m1.swap(m2)" << COLOR_DEFAULT << std::endl;
	// m1.swap(m2);
	// std::cout << "Print values of m1:" << std::endl;
	// print_values(m1);
	// std::cout << "Print values of m2:" << std::endl;
	// print_values(m2);
	// std::cout << COLOR_BLUE << "Swap them back via m2.swap(m1)" << COLOR_DEFAULT << std::endl;
	// m2.swap(m1);
	// std::cout << "Print values of m1:" << std::endl;
	// print_values(m1);
	// std::cout << "Print values of m2:" << std::endl;
	// print_values(m2);
	// usleep(500000);
	

	// usleep(500000);
	// std::cout << std::endl << COLOR_RED <<  "TESTS FOR LOOKUP FUNCTIONS" << COLOR_DEFAULT << std::endl;
	// std::cout << COLOR_BLUE << "Check the number of elements with the key *4* via 'm1.count(\"4\")' (returns 0 or 1)" << COLOR_DEFAULT << std::endl;
	// std::cout << "Function returns: " << COLOR_GREEN << m1.count("4") << COLOR_DEFAULT << std::endl;
	// std::cout << COLOR_BLUE << "Finds an element with key equivalent to *4* via 'm1.find(\"4\")' (returns iterator) //---> CHECK THIS AGAIN!//" << COLOR_DEFAULT << std::endl;
	// std::cout << "Function returns iterator with value: " << COLOR_GREEN << ((*(m1.find("4"))).second) << COLOR_DEFAULT << std::endl;
	// std::cout <<  COLOR_BLUE << "Find the range containing all elements with key *4* (-> only one element, because unique) via 'm1.equal_range(\"4\")'" << COLOR_DEFAULT << std::endl;
	// ft::pair<ft::map<std::string, std::string>::iterator, ft::map<std::string, std::string>::iterator> ret = m1.equal_range("4");
	// std::cout << "Function returns pair of iterators pointing to: " << ret.first->second << " and " << ret.second->second << std::endl;
	// std::cout << COLOR_BLUE << "Find lower_bound with the key *4* via 'm1.lower_bound(\"4\")' //---> CHECK THIS AGAIN!//" << COLOR_DEFAULT << std::endl;
	// std::cout << "Function returns iterator pointing to: " << (m1.lower_bound("4"))->second << std::endl;
	// std::cout << COLOR_BLUE << "Find upper_bound with the key *4* via 'm1.upper_bound(\"4\")'  //---> CHECK THIS AGAIN!//" << COLOR_DEFAULT << std::endl;
	// std::cout << "Function returns iterator pointing to: " << (m1.upper_bound("4"))->second << std::endl;
	// std::cout << COLOR_GREEN << "HOW TO TEST KEY_COMP??: https://en.cppreference.com/w/cpp/container/map/key_comp" << COLOR_DEFAULT << std::endl;
	// std::cout << COLOR_GREEN << "HOW TO TEST VALUE_COMP??: https://en.cppreference.com/w/cpp/container/map/value_comp" << COLOR_DEFAULT << std::endl << std::endl;
	// usleep(500000);


	// usleep(500000);
	// std::cout << COLOR_RED <<  "TESTS FOR RELATIONAL OPERATORS" << COLOR_DEFAULT << std::endl;
	// std::cout << COLOR_BLUE << "Compare m1 and m2" << COLOR_DEFAULT << std::endl;
	// std::cout << "Printing m1: ";
	// print_values(m1);
	// std::cout << "Printing m2: ";
	// print_values(m2);
	// std::cout << "Printing v5: ";
	// print_values(v5);
	// std::cout << COLOR_BLUE << "Compare m1 and m2" << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'm1 == m2' (should return true)? " << COLOR_BLUE << ((m1 == m2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'm1 != m2' (should return true)? " << COLOR_BLUE << ((m1 != m2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'm1 < m2' (should return false)? " << COLOR_BLUE << ((m1 < m2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'm1 <= m2' (should return false)? " << COLOR_BLUE << ((m1 <= m2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'm1 > m2' (should return false)? " << COLOR_BLUE << ((m1 > m2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'm1 >= m2' (should return false)? " << COLOR_BLUE << ((m1 >= m2) ? "true" : "false") << COLOR_DEFAULT << std::endl;

	// std::cout << COLOR_BLUE << "Compare m2 and v5" << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'm2 == v5' (should return false)? " << COLOR_BLUE << ((m2 == v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'm2 != v5' (should return true)? " << COLOR_BLUE << ((m2 != v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'm2 < v5' (should return false)? " << COLOR_BLUE << ((m2 < v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'm2 <= v5' (should return false)? " << COLOR_BLUE << ((m2 <= v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'm2 > v5' (should return true)? " << COLOR_BLUE << ((m2 > v5) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	// std::cout << "Is 'm2 >= v5' (should return true)? " << COLOR_BLUE << ((m2 >= v5) ? "true" : "false") << COLOR_DEFAULT << std::endl  << std::endl;
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