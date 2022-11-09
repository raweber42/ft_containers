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

void print_values(ft::vector<int> vector_int) {
	
	std::cout << "The values held by the vector are  (accessed via iterator): " << std::endl;
	for (ft::vector<int>::iterator it = vector_int.begin(); it != vector_int.end(); it++)
	{
		std::cout << *it << ", ";
		fflush(stdout);
		usleep(80000);
	}
	std::cout << "FINISHED" << std::endl << std::endl;
}

void print_values_reversed(ft::vector<int> vector_int) {
	
	std::cout << "The values held by the vector are (accessed via REVERSE iterator): " << std::endl;
	for (ft::vector<int>::reverse_iterator it = vector_int.rbegin(); it != vector_int.rend(); it++)
	{
		std::cout << *it << ", ";
		fflush(stdout);
		usleep(80000);
	}
	std::cout << "FINISHED" << std::endl << std::endl;
}


int main(void) {

	std::cout << std::endl << "\033[33m" << "######################## INTEGER VECTOR ###############################" << "\033[0m" << std::endl;
	
	usleep(500000);
	std::cout << "\033[34m" <<  "!! ADD TESTS FOR CONSTRUCTORS HERE !!" << "\033[0m" << std::endl;
	ft::vector<int> zeroed_vector(10);
	usleep(500000);

	ft::vector<int> vector_int;
	int test_size = 20;
	
	std::cout << "\033[34m" << "Pushing integers 0 - " << (test_size - 1) << " to vector" << "\033[0m";
	for (int i = 0; i < 5; i++)
	{
		std::cout << " .";
		fflush(stdout);
		usleep(200000);
	}
	std::cout << std::endl;
	for (int i = 0; i < test_size; i++)
	{
		vector_int.push_back(i);
	}
	print_values(vector_int);
	print_values_reversed(vector_int);

	std::cout << "\033[34m" <<  "Popping half of the values" << "\033[0m";
	for (int i = 0; i < (test_size/2); i++)
	{
		std::cout << " .";
		fflush(stdout);
		vector_int.pop_back();
		usleep(200000);
	}
	std::cout << std::endl;
	print_values(vector_int);

	usleep(500000);
	std::cout << "\033[34m" << "Copying values to new vector via assignment and copy assignment " << "\033[0m" << std::endl;
	ft::vector<int> copy_assign_vector = vector_int;
	ft::vector<int> assign_vector;
	assign_vector = vector_int;
	std::cout << "Print copy assignment vector:" << std::endl;
	print_values(copy_assign_vector);
	std::cout << "Print assignment vector:" << std::endl;
	print_values(assign_vector);
	usleep(500000);

	std::cout << "\033[34m" << "Check '==' operator overload" << "\033[0m" << std::endl;
	std::cout << "Is vector_int == copy_assign_vector? " << ((vector_int == copy_assign_vector) ? "YES" : "NO") << std::endl;
	std::cout << "Is vector_int == assign_vector? " << ((vector_int == copy_assign_vector) ? "YES" : "NO") << std::endl;

	usleep(500000);
	std::cout << "\033[34m" <<  "TESTS FOR ELEMENT ACCESS" << "\033[0m" << std::endl;
	std::cout << "\033[34m" << "Get first value via 'front'" << "\033[0m" << std::endl;
	std::cout << "First value is: " << vector_int.front() << std::endl;
	std::cout << "\033[34m" << "Get last value via 'back'" << "\033[0m" << std::endl;
	std::cout << "Last value is: " << vector_int.back() << std::endl;
	std::cout <<  "\033[34m" << "Get first value via vector_int.at(0)" << "\033[0m" << std::endl;
	std::cout << "Value is: " << vector_int.at(0) << std::endl;
	std::cout <<  "\033[34m" << "Get first value via vector_int[0]" << "\033[0m" << std::endl;
	std::cout << "Value is: " << vector_int[0] << std::endl;
	std::cout <<  "\033[34m" << "Get all pointer to first container element via vector_int.data()" << "\033[0m" << std::endl;
	std::cout << "Address is: " << vector_int.data() << " which holds the value of " << *vector_int.data() << std::endl << std::endl;
	usleep(500000);

	usleep(500000);
	std::cout << "\033[34m" <<  "TESTS FOR CAPACITY FUNCTIONS" << "\033[0m" << std::endl;
	std::cout << "\033[34m" << "Check if container is empty via vector_int.empty()" << "\033[0m" << std::endl;
	std::cout << "Function returns: " << ((vector_int.empty()) ? "TRUE" : "FALSE") << std::endl;
	std::cout << "\033[34m" << "Get size of vector via 'size()'" << "\033[0m" << std::endl;
	std::cout << "Current size is is: " << vector_int.size() << std::endl;
	std::cout <<  "\033[34m" << "Get max size of vector via 'max_size()'" << "\033[0m" << std::endl;
	std::cout << "Max size is: " << vector_int.max_size() << std::endl;
	std::cout <<  "\033[34m" << "Get capacity of vector via capacity()" << "\033[0m" << std::endl;
	std::cout << "Current capacity is: " << vector_int.capacity() << std::endl;
	std::cout <<  "\033[34m" << "Try calling 'vector_int.reserve(5)' (should NOT increase capacity)" << "\033[0m" << std::endl;
	vector_int.reserve(5);
	std::cout << "Current capacity is: " << vector_int.capacity() << std::endl;
	std::cout <<  "\033[34m" << "Try calling 'vector_int.reserve(50)' (SHOULD increase capacity)" << "\033[0m" << std::endl;
	vector_int.reserve(50);
	std::cout << "Current capacity is: " << vector_int.capacity() << std::endl << std::endl;
	usleep(500000);

	usleep(500000);
	std::cout << "\033[34m" <<  "TESTS FOR MODIFIER FUNCTIONS" << "\033[0m" << std::endl;
	std::cout << "\033[34m" << "Resize the vector via vector_int.resize()" << "\033[0m" << std::endl;
	std::cout << "Current capacity is: " << vector_int.capacity() << std::endl;
	std::cout << "\033[34m" << "Insert 5 elements of value '66' at the beginning of the vector via 'vector_int.insert(vector_int.begin(), 5, 66)'" << "\033[0m" << std::endl;
	vector_int.insert(vector_int.begin(), 5, 66);
	print_values(vector_int);
	// maybe more insert tests here!
	std::cout << "\033[34m" << "Erase the first five elements at the beginning of the vector via calling 'vector_int.erase(vector_int.begin())' five times" << "\033[0m" << std::endl;
	for (int i = 0; i < 5; i++)
		vector_int.erase(vector_int.begin());
	print_values(vector_int);
	std::cout << "\033[34m" << "Swap zeroed vector and vector_int via vector_int.swap(zeroed_vector)" << "\033[0m" << std::endl;
	vector_int.swap(zeroed_vector);
	std::cout << "Print values of vector_int:" << std::endl;
	print_values(vector_int);
	std::cout << "Print values of zeroed_vector:" << std::endl;
	print_values(zeroed_vector);
	std::cout << "\033[34m" << "Clear the vector via vector.clear()" << "\033[0m" << std::endl;
	vector_int.clear();
	std::cout << "Current size is is: " << vector_int.size() << std::endl;
	std::cout << "Current capacity is: " << vector_int.capacity() << std::endl;
	usleep(500000);






	// std::cout << "\033[33m" << "//######################## STRING VECTOR ######################################" << "\033[0m" << std::endl;
	// std::cout << std::endl << "Checking string vector" << std::endl;
	// ft::vector<std::string> vector_str;

	// std::cout << "\033[33m" << "//######################## CUSTOM STRUCT VECTOR ###############################" << "\033[0m" << std::endl;

	// std::cout << std::endl << "Checking custom struct vector" << std::endl;
	// ft::vector<Buffer> vector_buffer;
	

	return (0);
}

// add constructor tests and non-member-functions!