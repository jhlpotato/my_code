#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main(void) {
	string str1 = "jinghoang";
	string str2 = "liuman";
	str1 = str2;
	cout << str1 << str2 << endl;
	return 0;
}