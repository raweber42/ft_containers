#include "inc/vector.hpp"
#include <vector>

int _ratio = 10000;

void printElement(std::string t) {
	std::cout << t << std::endl;
}

template <typename T>
std::vector<int> swap_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1100 * _ratio, 11);
    std::vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);
    // g_start1 = timer();
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    long *adr1 = reinterpret_cast<long *>(&vector);
    long *adr2 = reinterpret_cast<long *>(&tmp);
    vector.swap(tmp);
    if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
    	v.push_back(1);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.swap(tmp3);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    std::swap(vector, tmp2);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity()); // HERE ERROR
    std::swap(vector, tmp4);
    // g_end1 = timer();
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> swap_test(ft::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1100 * _ratio, 11);
	ft::vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);
    // g_start2 = timer();
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    long *adr1 = reinterpret_cast<long *>(&vector);
    long *adr2 = reinterpret_cast<long *>(&tmp);
    vector.swap(tmp);
    if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
    	v.push_back(1);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.swap(tmp3);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    std::swap(vector, tmp2);
    v.push_back(vector[2]);
    v.push_back(vector.size()); 
    v.push_back(vector.capacity()); // HERE ERROR
    std::swap(vector, tmp4);
    // g_end2 = timer();
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
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
	// std::cout << endl;

	return !(!result && !leaks);
}

int main() {

    exit(run_vector_unit_test<int>("swap()", swap_test, swap_test));
}