#include <iostream>
#include <vector>

using namespace std;

void showVec(vector<int>&);
void heapSort(vector<int>&, int, int);

int main(void) {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(10);
	vec.push_back(5);
	vec.push_back(212);
	vec.push_back(10000);
	vec.push_back(2);
	vec.push_back(2345);
	showVec(vec);
	heapSort(vec, 0, vec.size());
	showVec(vec);
	return 0;
}

void showVec(vector<int>& v){
	//vector::iterator iter;
	/*
	for(vector::iterator *iter = v.begin(); iter != v.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	*/
	int len = v.size();
	for(int i = 0; i < len; ++i) 
		cout << v[i] << " ";
	cout << endl;
}

void heapSort(vector<int>& input, int root, int end) {
	for(int i = end-1; i >= root; --i) {
		int parent = (i+root-1)/2;
		if(input[parent] > input[i]) {
			int temp = input[parent];
			input[parent] = input[i];
			input[i] = temp;
		}
	}
}