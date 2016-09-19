#include <iostream>

using namespace std;

int a() {
	cout << 'a' << endl;
}

int b(int b) {
	cout << b << endl;
}

int main() {
	a();
	b(1);
	return 0;
}