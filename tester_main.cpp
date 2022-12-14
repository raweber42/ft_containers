#include "inc/vector.hpp"
#include <vector>

int _ratio = 10000;

void printElement(std::string t) {
	std::cout << t << std::endl;
}

template <typename T>
std::vector<int> resize_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    // g_start1 = timer();
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
	std::cout << "capacity std is: " << vector.capacity() << std::endl;
    vector.resize(15300 * _ratio, T());
    v.push_back(vector.size());
	std::cout << "capacity std is: " << vector.capacity() << std::endl;
    // v.push_back(vector.capacity());
    // v.push_back(vector[65]);
    // g_end1 = timer();
    return v;
}

template <typename T>
std::vector<int> resize_test(ft::vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    // g_start2 = timer();
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
	std::cout << "capacity ft is: " << vector.capacity() << std::endl;
    vector.resize(15300 * _ratio, T());
    v.push_back(vector.size());
	std::cout << "capacity ft is: " << vector.capacity() << std::endl;
    // v.push_back(vector.capacity());
    // v.push_back(vector[65]);
    // g_end2 = timer();
    return v;
}

template <class T>
int run_vector_unit_test(std::string test_name, std::vector<int> (func1)(std::vector<T>), std::vector<int> (func2)(ft::vector<T>)) {
    int    result;
    int    leaks;
    time_t t1;
    time_t t2;
    std::vector<int > res1;
    std::vector<int > res2;
    std::vector<int> vector;
    ft::vector<int> my_vector;

	printElement(test_name);
	res1 = func1(vector);
	res2 = func2(my_vector);
	if (res1 == res2) {
	    printElement("OK");
	    result = 0;
	}
	else {
	    printElement("FAILED");
	    result = 1;
	}
	// t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;
	// (t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);
	// (t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);
	// leaks = leaks_test(getpid());
	// cout << endl;

	return !(!result && !leaks);
}



int main() {

    exit(run_vector_unit_test<int>("resize()", resize_test, resize_test));
}