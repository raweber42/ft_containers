#include <iostream>
#include <string>
#include <deque>
#include <unistd.h>
#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


int main(void) {

	std::cout << "######################## INTEGER VECTOR ###############################" << std::endl;
	ft::vector<int> vector_int;
	int test_size = 20;
	
	std::cout << "Pushing integers 0 - " << (test_size - 1) << " to vector";
	for (int i = 0; i < 5; i++)
	{
		std::cout << " .";
		fflush(stdout);
		usleep(300000);
	}
	std::cout << std::endl;
	for (int i = 0; i < test_size; i++)
	{
		vector_int.push_back(i);
	}
	std::cout << "The values are (accessed via iterator): " << std::endl;
	for (ft::vector<int>::iterator it = vector_int.begin(); it != vector_int.end(); it++)
	{
		std::cout << *it << ", ";
		fflush(stdout);
		usleep(100000);
	}
	std::cout << "FINISHED" << std::endl << std::endl;

	std::cout << "Popping half of the values";
	for (int i = 0; i < (test_size/2); i++)
	{
		std::cout << " .";
		fflush(stdout);
		vector_int.pop_back();
		usleep(300000);
	}
	std::cout << std::endl;

	std::cout << "Last value now is: " << vector_int.back() << std::endl;
	std::cout << "First value now is: " << vector_int.front() << std::endl; 

	// std::cout << "//######################## STRING VECTOR ######################################" << std::endl;
	// std::cout << std::endl << "Checking string vector" << std::endl;
	// ft::vector<std::string> vector_str;

	// std::cout << "//######################## CUSTOM STRUCT VECTOR ###############################" << std::endl;

	// std::cout << std::endl << "Checking custom struct vector" << std::endl;
	// ft::vector<Buffer> vector_buffer;
	

	return (0);
}