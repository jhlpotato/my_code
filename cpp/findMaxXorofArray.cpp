#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getPreXorValue(vector<int> vec, int index) {
	int result = 0;
	for(int i = 0; i <= index; ++i) {
		result ^= vec[i];
	} 
	return result;
}

int getSufXorValue(vector<int> vec, int index) {
	int result = 0;
	for(int i = vec.size()-1; i >= index; --i) {
		result ^= vec[i];
	}
	return result;
}

int findMaxXorofArray(vector<int> vec) {
	int len = vec.size();
	if(len == 0)
		return 0;

	int max = INT_MIN;
	vector<int> pre_xor_vec;
	vector<int> suf_xor_vec;
	pre_xor_vec.push_back(0);
	suf_xor_vec.push_back(0);

	for(int i = 0; i < len; ++i) {
		int value = getPreXorValue(vec, i);
		pre_xor_vec.push_back(value);
	}

	for(int i = len-1; i >= 0; --i) {
		int value = getSufXorValue(vec, i);
		suf_xor_vec.push_back(value);
	}

	for(int i = 0; i <= len; ++i) {
		for(int j = 0; j <= len-i; ++j) {
			int value = pre_xor_vec[i] ^ suf_xor_vec[j];
			if(value > max)
				max = value;
		}
	}

	return max;
}

int main(void) {
	vector<int> vec = {1, 2, 4, 8, 16};
	cout << findMaxXorofArray(vec) << endl;
	return 0;
}