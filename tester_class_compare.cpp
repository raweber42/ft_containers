#include "inc/utils.hpp"
#include "inc/map.hpp"
#include <map>
#include <vector>
#include <functional>

int _ratio = 10000;

void printElement(std::string t) {
	std::cout << t << std::endl;
}

template <class T, class V, class C>
void fillMap(std::map<T, V, C> &mp) {
	mp.insert(std::make_pair(16, 3));
	mp.insert(std::make_pair(8, 3));
	mp.insert(std::make_pair(23, 3));
	mp.insert(std::make_pair(7, 3));
	mp.insert(std::make_pair(19, 3));
	mp.insert(std::make_pair(29, 3));
	mp.insert(std::make_pair(41, 3));
	mp.insert(std::make_pair(4, 3));
	mp.insert(std::make_pair(11, 3));
}

template <class T, class V, class C>
void fillMap(ft::map<T, V, C> &mp) {
	mp.insert(ft::make_pair(16, 3));
	mp.insert(ft::make_pair(8, 3));
	mp.insert(ft::make_pair(23, 3));
	mp.insert(ft::make_pair(7, 3));
	mp.insert(ft::make_pair(19, 3));
	mp.insert(ft::make_pair(29, 3));
	mp.insert(ft::make_pair(41, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(11, 3));
}

template <class T, class V>
std::vector<int> comparator_test(std::map<T, V> mp) {

    std::vector<int> v;
    fillMap(mp);
    for (typename std::map<T, V>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
    for (typename std::map<T, V>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::greater<int> > mp1;
    fillMap(mp1);
    v.push_back(mp1.begin()->first);
    mp1.erase(41);
    v.push_back(mp1.begin()->first);
    mp1.erase(29);
    v.push_back(mp1.begin()->first);
    std::map<int, int, std::greater<int> > mp2;
    mp2.insert(std::make_pair(3, 3));
    v.push_back(mp2.begin()->first);
    mp2.erase(3);
    if (mp2.begin() == mp2.end())
        v.push_back(1);
    std::map<int, int, std::plus<int> > mp3;
    fillMap(mp3);
    for (typename std::map<T, V>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
    for (typename std::map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::minus<int> > mp4;
    fillMap(mp4);
    for (typename std::map<T, V>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
    for (typename std::map<T, V>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::greater_equal<int> > mp5;
    fillMap(mp5);
    for (typename std::map<T, V>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
    for (typename std::map<T, V>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::multiplies<int> > mp6;
    fillMap(mp6);
    for (typename std::map<T, V>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
    for (typename std::map<T, V>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::bit_xor<int> > mp7;
    fillMap(mp7);
    for (typename std::map<T, V>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
    for (typename std::map<T, V>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::logical_and<int> > mp8;
    fillMap(mp8);
    for (typename std::map<T, V>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
    for (typename std::map<T, V>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
    // g_start1 = timer();
    // g_end1 = timer();
    v.push_back(mp1.size());
    return v;
}

template <class T, class V>
std::vector<int> comparator_test(ft::map<T, V> mp) {
    std::vector<int> v;
    fillMap(mp);
    for (typename ft::map<T, V>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
    for (typename ft::map<T, V>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::greater<int> > mp1;
    fillMap(mp1);
    v.push_back(mp1.begin()->first);
    mp1.erase(41);
    v.push_back(mp1.begin()->first);
    mp1.erase(29);
    v.push_back(mp1.begin()->first);
    ft::map<int, int, std::greater<int> > mp2;
    mp2.insert(ft::make_pair(3, 3));
    v.push_back(mp2.begin()->first);
    mp2.erase(3);
    if (mp2.begin() == mp2.end())
        v.push_back(1);
    ft::map<int, int, std::plus<int> > mp3;
    fillMap(mp3);
    for (typename ft::map<T, V>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
    for (typename ft::map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::minus<int> > mp4;
    fillMap(mp4);
    for (typename ft::map<T, V>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
    for (typename ft::map<T, V>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::greater_equal<int> > mp5;
    fillMap(mp5);
    for (typename ft::map<T, V>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
    for (typename ft::map<T, V>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::multiplies<int> > mp6;
    fillMap(mp6);
    for (typename ft::map<T, V>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
    for (typename ft::map<T, V>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::bit_xor<int> > mp7;
    fillMap(mp7);
    for (typename ft::map<T, V>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
    for (typename ft::map<T, V>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::logical_and<int> > mp8;
    fillMap(mp8);
    for (typename std::map<T, V>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
    for (typename std::map<T, V>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
    // g_start1 = timer();
    // g_end1 = timer();
    v.push_back(mp1.size());

    return v;
}



template <class T, class V>
int run_map_unit_test(std::string test_name, std::vector<int> (func1)(std::map<T, V>), std::vector<int> (func2)(ft::map<T, V>)) {
    int    result;
    int    leaks;
	time_t t1;
	time_t t2;
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

	return !(!result && !leaks);
}

int main() {

    exit(run_map_unit_test<int, int>("compare class", comparator_test, comparator_test));
}
