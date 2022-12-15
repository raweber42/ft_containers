#include "inc/utils.hpp"
#include "inc/vector.hpp"
#include <vector>

int _ratio = 10000;

void printElement(std::string t) {
	std::cout << t << std::endl;
}
bool iterator_traits_test() {
	std::vector<std::string> res;
	std::vector<std::string> res2;
	// g_start1 = g_end1 = timer();

	res.push_back(typeid(std::vector<int>::iterator::iterator_category).name());
	res.push_back(typeid(std::vector<int>::iterator::value_type).name());
	res.push_back(typeid(std::vector<int>::iterator::difference_type).name());
	res.push_back(typeid(std::vector<int>::iterator::iterator_type).name());
	res.push_back(typeid(std::vector<int>::iterator::pointer).name());
	res.push_back(typeid(std::vector<int>::iterator::reference).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::iterator_category).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::value_type).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::difference_type).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::pointer).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::reference).name());

	res2.push_back(typeid(ft::vector<int>::iterator::iterator_category).name());
	res2.push_back(typeid(ft::vector<int>::iterator::value_type).name());
	res2.push_back(typeid(ft::vector<int>::iterator::difference_type).name());
	res2.push_back(typeid(ft::vector<int>::iterator::iterator_type).name());
	res2.push_back(typeid(ft::vector<int>::iterator::pointer).name());
	res2.push_back(typeid(ft::vector<int>::iterator::reference).name());
	res2.push_back(typeid(ft::vector<int>::reverse_iterator::iterator_category).name());
	res2.push_back(typeid(ft::vector<int>::reverse_iterator::value_type).name());
	res2.push_back(typeid(ft::vector<int>::reverse_iterator::difference_type).name());
	res2.push_back(typeid(ft::vector<int>::reverse_iterator::pointer).name());
	res2.push_back(typeid(ft::vector<int>::reverse_iterator::reference).name());

	return res == res2;
}

int run_bool_unit_test(std::string test_name, bool (func1)()) {
    int ret = 0;
    time_t t1;
    time_t t2;
    bool res;

	printElement(test_name);
	res = func1();
	if (res) {
	    printElement("OK");
	    ret = 0;
	}
	else {
	    printElement("FAILED");
	    ret = 1;
	}
	// t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;
	// (t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);
	// (t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);
	// cout << endl;

    return ret;
}

int main() {

	exit(run_bool_unit_test("iterators_traits", iterator_traits_test));
}