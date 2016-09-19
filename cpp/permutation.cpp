#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
	void swap(string& str, int i, int n) {
		char temp = str[i];
		str[i] = str[n];
		str[n] = temp;
	}
	void MyPermutation(string& str, int n, int len) {
		if(len-1 == n) {
			cout << str <<endl;
		}

		for(int i = n; i < len; ++i) {
			swap(str, i, n);
			MyPermutation(str, n+1, len);
			swap(str, i, n);
		}
	}
    void Permutation(string str) {
    	//vector<string> result;
        int len = str.length();
        MyPermutation(str, 0, len);
        //return result;
    }
};


int main() {
	Solution s;
	//string str = "a";
	s.Permutation("abcdefghigklmn");
	//cout << "123" << endl;
	return 0;
}