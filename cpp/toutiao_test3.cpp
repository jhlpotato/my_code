#include <iostream>
#include <vector>

using namespace std;

bool isDuobianxing(vector<int>& arr, int L) {
	if(arr.size() <= 2)
		return false;
	int min = arr[0];
	int max = arr[0];
	int sum = 0;
	for(int i = 0; i < arr.size(); ++i) {
		sum += arr[i];
		if(arr[i] < min) {
			min = arr[i];
		}
		if(arr[i] > max) {
			max = arr[i];
		}
	}

	int number = sum - arr[arr.size()-1];
	if(number > arr[arr.size()-1])
		min = number - arr[arr.size()-1];
	else
		min = arr[arr.size()-1] - number;

	if(L < min || L > sum)
		return false;
	return true;
}

int main(void) {
	int n;
	cin >> n;
	vector<int> arr;
	for(int i = 0; i < n; ++i) {
		int a, L;
		cin >> a >> L;
		if(a == 1)
			arr.push_back(L);
		if(a == 2)
			arr.pop_back();

		if(arr.size() <= 2)
			cout << "No" << endl;
		else {
			if(isDuobianxing(arr, L))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}

	}
	return 0;
}