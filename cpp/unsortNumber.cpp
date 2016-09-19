#include <iostream>

using namespace std;

int InversePairsCore(int *data, int *copy, int start, int end) {
	if(start == end) {
		copy[start] = data[end];
		return 0;
	}

	int length = (end-start) / 2;

	int left = InversePairsCore(data, copy, start, start+length);
	int right = InversePairsCore(data, copy, start+length+1, end);

	int i = left+length;
	int j = end;
	int indexCopy = end;
	int count = 0;

	while(i>=start && j >= start+length+1) {
		if(data[i] > data[j]) {
			copy[indexCopy--] = data[j--];
			count += j-start-length;
		} else {
			copy[indexCopy--] = data[i--];
		}
	}

	while(i >= start) {
		copy[indexCopy--] = data[i--];
	}

	while(j >= start+length+1) {
		copy[indexCopy--] = data[j--];
	}

	return left+right+count;
}
int InversePairs(int *data, int length) {
	if(data == NULL || length < 0)
		return 0;

	int *copy = new int[length];
	for(int i = 0; i < length; ++i) {
		copy[i] = data[i];
	}

	int count = InversePairsCore(data, copy, 0, length-1);
	delete[] copy;
	return count;
}

int main(void) {
	int a[] = {7, 5, 6, 4, 1};
	cout << InversePairs(a, 4) << endl;	
	return 0;
}