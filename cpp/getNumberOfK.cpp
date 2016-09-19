#include <iostream>
#include <vector>

using namespace std;

int findK(const vector<int> data, int k, int start, int end) {
	if(start > end)
		return -1;

	int middle = (start + end) / 2;
	if(data[middle] == k && middle >= 0) 
		return middle;
	else if(data[middle] > k && middle >= 0)
		return findK(data, k, start, middle-1);
	else if(data[middle] < k && middle >= 0)
		return findK(data, k, middle+1, end);
	else
		return -1;
}

int GetNumberOfK(const vector<int> data, int k) {
	int start = 0;
	int end = data.size() - 1;
	int position = findK(data, k, start, end);
	int count = 1;

	if(position == -1)
		return -1;

	for(int i = position-1; i >= 0; i--) {
		if(data[i] == k)
			count ++;
	}

	for(int i = position+1; i <= end; ++i) {
		if(data[i] == k)
			count ++;
	}

	return count;
}

int main(void) {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	cout << GetNumberOfK(vec, 6) << endl;

	return 0;
}