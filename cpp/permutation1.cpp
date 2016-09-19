#include <iostream>
#include <vector>
#include <string>

using namespace std;
void swap(string& str, int index, int i) {
	char temp = str[index];
	str[index] = str[i];
	str[i] = temp;
}

void Permutation1(string& str, int index) {
	if(str[index] == '\0')
		cout << str << endl;
	else {
		for(int i = index; str[i] != '\0'; ++i) {
			swap(str, index, i);
			Permutation1(str, index+1);
			swap(str, index, i);
		}
	}
}

int main(void) {
	string s = "abcdefghijklmn";
	Permutation1(s, 0);
	return 0;
}