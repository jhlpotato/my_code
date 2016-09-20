#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <utility>

using namespace std;

struct map_func_t {
	bool operator() (const int& x, const int& y) {
		return x > y;
	}
};

typedef std::map<int, string, map_func_t> my_map;

void showmap(my_map m) {
	my_map::iterator it = m.begin();
	for(; it != m.end(); ++it) {
		std::cout << it->second << std::endl;
	}
}

struct test_func {
	unsigned long operator()(const std::pair<int, int>& p) const {
		return p.first * 1 + p.second * 10;
	}
};

typedef std::map<std::pair<int, int>, string, test_func> my_test;

int main(void) {
	my_map m;
	m[1] = "jinhongliang";
	m[2] = "fuchao";
	m[3] = "liuweikai";
	showmap(m);

	my_test mt;
	std::pair<int, int> p1;
	std::pair<int, int> p2;
	std::pair<int, int> p3;
	mt[p1] = "jinhongliang";
	mt[p2] = "fuchao";
	mt[p3] = "liuweikai";
	showmap(mt);
	return 0;
}