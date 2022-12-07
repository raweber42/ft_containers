/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:08 by raweber           #+#    #+#             */
/*   Updated: 2022/12/07 10:15:19 by raweber          ###   ########.fr       */
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
// 	#include <map>
// 	#include <stack>
// 	#include <stack>
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

// void print_values_underlying(ft::stack<int, ft::vector<int> > &s1) {
	
// 	std::cout << "The values held by the stacks underlying container are (accessed via iterator): [ ";
// 	for (ft::vector<int>::iterator it = s1.c.begin(); it != s1.c.end(); it++)
// 	{
// 		std::cout << *it << " ";
// 		fflush(stdout);
// 		usleep(80000);
// 	}
// 	std::cout << "]" << std::endl << std::endl;
// }

int main(void) {

	std::cout << std::endl << COLOR_YELLOW << "######################## INTEGER STACK ###############################" << COLOR_DEFAULT << std::endl;
	usleep(500000);
	std::cout << COLOR_RED <<  "CONSTRUCTOR TESTS" << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_BLUE << "Initializing vector s1 for underlying container" << COLOR_DEFAULT << std::endl;
	ft::vector<int> v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	print_values(v1);
	
	std::cout << COLOR_BLUE << "Initializing stack s1 with vector via 'ft::stack<int, ft::vector<int>> s1'" << COLOR_DEFAULT << std::endl;
	ft::stack<int, ft::vector<int> > s1(v1);

	std::cout << COLOR_BLUE << "Initializing stack s2 via copy constructor via 's2(s1)'" << COLOR_DEFAULT  << std::endl;
	ft::stack<int, ft::vector<int> > s2(s1);

	std::cout << COLOR_BLUE << "Initializing stack s3 via assignment 's3 = s2'" << COLOR_DEFAULT  << std::endl;
	ft::stack<int, ft::vector<int> > s3 = s2;
	// print_values_underlying(s3);
	usleep(500000);
	
	usleep(500000);
	std::cout << COLOR_RED <<  "TESTS FOR MODIFIER FUNCTIONS" << COLOR_DEFAULT << std::endl;
	std::cout << "Current size is: " << s1.size() << std::endl;
	std::cout << COLOR_BLUE << "Pushing integers 10 - 20 to s1" << COLOR_DEFAULT;
	for (int i = 0; i < 5; i++)
	{
		std::cout << " .";
		fflush(stdout);
		usleep(200000);
	}
	std::cout << std::endl;
	for (int i = 10; i < 21; i++)
	{
		s1.push(i);
	}
	std::cout << "Current size is: " << s1.size() << std::endl;
	// print_values_underlying(s1);

	std::cout << COLOR_BLUE <<  "Popping 5 values from s1" << COLOR_DEFAULT;
	for (int i = 0; i < 5; i++)
	{
		std::cout << " .";
		fflush(stdout);
		s1.pop();
		usleep(200000);
	}
	std::cout << std::endl;
	std::cout << "Current size is: " << s1.size() << std::endl;
	// print_values_underlying(s1);
	usleep(500000);


	usleep(500000);
	std::cout << COLOR_RED <<  "TESTS FOR ELEMENT ACCESS" << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_BLUE << "Get top value via ' s1.top()'" << COLOR_DEFAULT << std::endl;
	std::cout << "First value is: " << s1.top() << std::endl;
	usleep(500000);


	usleep(500000);
	std::cout << COLOR_RED <<  "TESTS FOR CAPACITY FUNCTIONS" << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_BLUE << "Check if container is empty via 's1.empty()'" << COLOR_DEFAULT << std::endl;
	std::cout << "Function returns: " << ((s1.empty()) ? "TRUE" : "FALSE") << std::endl;
	std::cout << COLOR_BLUE << "Get size of stack via 's1.size()'" << COLOR_DEFAULT << std::endl;
	std::cout << "Current size is is: " << s1.size() << std::endl;
	usleep(500000);

	usleep(500000);
	std::cout << COLOR_RED <<  "TESTS FOR RELATIONAL OPERATORS" << COLOR_DEFAULT << std::endl;
	// std::cout << "Printing s1: ";
	// print_values(s1);
	// std::cout << "Printing s2: ";
	// print_values(s2);
	// std::cout << "Printing v5: ";
	// print_values(s3);
	std::cout << COLOR_BLUE << "Compare s1 and s2" << COLOR_DEFAULT << std::endl;
	std::cout << "Is 's1 == s2' (should return false)? " << COLOR_BLUE << ((s1 == s2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 's1 != s2' (should return true)? " << COLOR_BLUE << ((s1 != s2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 's1 < s2' (should return false)? " << COLOR_BLUE << ((s1 < s2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 's1 <= s2' (should return false)? " << COLOR_BLUE << ((s1 <= s2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 's1 > s2' (should return true)? " << COLOR_BLUE << ((s1 > s2) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 's1 >= s2' (should return true)? " << COLOR_BLUE << ((s1 >= s2) ? "true" : "false") << COLOR_DEFAULT << std::endl;

	std::cout << COLOR_BLUE << "Compare s2 and s3" << COLOR_DEFAULT << std::endl;
	std::cout << "Is 's2 == s3' (should return true)? " << COLOR_BLUE << ((s2 == s3) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 's2 != s3' (should return false)? " << COLOR_BLUE << ((s2 != s3) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 's2 < s3' (should return false)? " << COLOR_BLUE << ((s2 < s3) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 's2 <= s3' (should return true)? " << COLOR_BLUE << ((s2 <= s3) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 's2 > s3' (should return false)? " << COLOR_BLUE << ((s2 > s3) ? "true" : "false") << COLOR_DEFAULT << std::endl;
	std::cout << "Is 's2 >= s3' (should return true)? " << COLOR_BLUE << ((s2 >= s3) ? "true" : "false") << COLOR_DEFAULT << std::endl  << std::endl;
	usleep(500000);




	// std::cout << COLOR_YELLOW << "//######################## STRING stack ######################################" << COLOR_DEFAULT << std::endl;
	// std::cout << std::endl << "Checking string stack" << std::endl;
	// ft::stack<std::string> stack_str;

	// std::cout << COLOR_YELLOW << "//######################## CUSTOM STRUCT stack ###############################" << COLOR_DEFAULT << std::endl;

	// std::cout << std::endl << "Checking custom struct stack" << std::endl;
	// ft::stack<Buffer> stack_buffer;
	

	return (0);
}



// add constructor tests and non-member-functions!
// test change of dereferenced pointer (is overload dauerhaft modifying ?)
// ----> { b=a; *a++; *b; } also stuff like this. See test cases: https://cplusplus.com/reference/iterator/
// check all iterator operator overloads!!! (need stack with incrementing numbers inside -> wait until push_back works)

// use std::find for testing (and container::find)

// ------ ITERATOR OVERLOAD