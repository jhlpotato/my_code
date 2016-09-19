#include <iostream>
#include <vector>

using namespace std;

int getFirstK(vector<int> data, int k, int start, int end) {
	if(start > end)
		return -1;

	int middle = (start + end) / 2;
	int middledata = data[middle];

	if(middledata == k) {
		if((middle > 0 && data[middle-1] != k) || middle == 0)
			return middle;
		else
			end = middle-1;
	} else if(middledata > k) {
		end = middle-1;
	} else if(middledata < k) {
		start = middle+1;
	}

	return getFirstK(data, k, start, end);
}

int getLastK(vector<int> data, int k, int start, int end) {
	if(start > end) 
		return -1;

	int middle = (start + end) / 2;
	int middledata = data[middle];

	if(middledata == k) {
		if((middle < data.size()-1 && data[middle+1] != k) || middle == data.size()-1)
			return middle;
		else
			start = middle + 1;
	} else if(middledata > k) {
		end = middle - 1;
	} else if(middledata < k) {
		start = middle+1;
	}

	return getLastK(data, k, start, end);
}

int GetNumberOfK(vector<int> data, int k) {
	int start = 0;
	int end = data.size()-1;
	int first = getFirstK(data, k, start, end);
	int last = getLastK(data, k, start, end);

	if(first == -1 || last == -1)
		return 0;
	return last-first+1;
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
	cout << GetNumberOfK(vec, 3) << endl;
	return 0;
}