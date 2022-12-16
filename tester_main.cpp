#include "inc/utils.hpp"
#include "inc/map.hpp"
#include <map>
#include <vector>
#include <functional>

int _ratio = 10000;

void printElement(std::string t) {
	std::cout << t << std::endl;
}
template <class T, class V>
std::vector<int> lower_bound_test(std::map<T, V> mp) {
    std::vector<int> v;
    std::map<int, int, std::greater<int> > mp2;
    mp.insert(std::make_pair(10, 10));
    mp2.insert(std::make_pair(10, 10));
    if (mp.lower_bound(11) == mp.end())
        v.push_back(1);
    if (mp2.lower_bound(1) == mp2.end())
        v.push_back(1);
    mp.insert(std::make_pair(20, 20));
    mp.insert(std::make_pair(30, 30));
    mp.insert(std::make_pair(40, 40));
    mp.insert(std::make_pair(50, 50));
    mp.insert(std::make_pair(60, 60));
    mp2.insert(std::make_pair(20, 20));
    mp2.insert(std::make_pair(30, 30));
    mp2.insert(std::make_pair(40, 40));
    mp2.insert(std::make_pair(50, 50));
    mp2.insert(std::make_pair(60, 60));
    std::map<int, int>::iterator it;
    for (int i = 1; i < 60; i += 10) {
        it = mp.lower_bound(i);
        v.push_back(it->first);
    }
    for (int i = 11; i < 70; i += 10) {
        it = mp2.lower_bound(i);
        v.push_back(it->first);
    }
    std::map<int, int> mp3;
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j) {
        mp3.insert(std::make_pair(i, j));
    }
    // g_start1 = timer();
    mp3.lower_bound(49 * _ratio);
    // g_end1 = timer();
    return v;
}

template <class T, class V>
std::vector<int> lower_bound_test(ft::map<T, V> mp) {
    std::vector<int> v;
    ft::map<int, int, std::greater<int> > mp2;
    mp.insert(ft::make_pair(10, 10));
    mp2.insert(ft::make_pair(10, 10));
    if (mp.lower_bound(11) == mp.end())
        v.push_back(1);
    if (mp2.lower_bound(1) == mp2.end())
        v.push_back(1);
    mp.insert(ft::make_pair(20, 20));
    mp.insert(ft::make_pair(30, 30));
    mp.insert(ft::make_pair(40, 40));
    mp.insert(ft::make_pair(50, 50));
    mp.insert(ft::make_pair(60, 60));
    mp2.insert(ft::make_pair(20, 20));
    mp2.insert(ft::make_pair(30, 30));
    mp2.insert(ft::make_pair(40, 40));
    mp2.insert(ft::make_pair(50, 50));
    mp2.insert(ft::make_pair(60, 60));
    ft::map<int, int>::iterator it;
    for (int i = 1; i < 60; i += 10) {
        it = mp.lower_bound(i);
        v.push_back(it->first);
    }
    for (int i = 11; i < 70; i += 10) {
        it = mp2.lower_bound(i);
        v.push_back(it->first);
    }
    ft::map<int, int> mp3;
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j) {
        mp3.insert(ft::make_pair(i, j));
    }
    // g_start2 = timer();
    mp3.lower_bound(49 *_ratio);
    // g_end2 = timer();
    return v;
}


template <class T, class V>
int run_map_unit_test(std::string test_name, std::vector<int> (func1)(std::map<T, V>), std::vector<int> (func2)(ft::map<T, V>)) {
    int    result;
    // int    leaks;
	// time_t t1;
	// time_t t2;
	std::vector<int > res1;
	std::vector<int > res2;
	std::map<int, int> map;
	ft::map<int, int> my_map;

	printElement(test_name);
	res1 = func1(map);
	res2 = func2(my_map);
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

	return !(!result);// && !leaks);
}


int main() {

    exit(run_map_unit_test<int, int>("lower_bound()", lower_bound_test, lower_bound_test));
}