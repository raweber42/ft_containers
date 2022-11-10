#include <iostream>
#include <vector>
 
int main()
{
    std::vector<std::string> alice;
	alice.push_back("ABC");
	alice.push_back("CDE");
	alice.push_back("EFG");
    std::vector<std::string> eve;
	eve.push_back("AC");
	// eve.push_back("cde");
	// eve.push_back("efg");
 
    std::cout << std::boolalpha;
  
    // Compare equal containers
    std::cout << "alice == eve returns " << (alice == eve) << '\n';
    std::cout << "alice != eve returns " << (alice != eve) << '\n';
    std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
}

/*
comparison of vectors:

CASE: '<'
v1;
v2;
for (int i = 0; i < v1.size(); i++)
{
	if (v1[i] == v2[i])
		continue;
	if (v1[i] < v2[i])
		return true;
	return false;
}
if (v1.size < v2.size)
	return true;
return false;

CASE: '=='
v1;
v2;
if (v1.size != v2.size)
	return false;
for (int i = 0; i < v1.size(); i++)
{
	if (v1[i] == v2[i])
		continue;
	if (v1[i] != v2[i])
		return false;
}
return true;


*/