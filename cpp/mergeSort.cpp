#include <iostream>
#include <vector>

using namespace std;

void Merge(int srcArr[], int tempArr[], int startIndex, int midIndex, int endIndex) {
	int i = startIndex;
	int j = midIndex+1;
	int k = startIndex;

	while(i != midIndex+1 && j != endIndex+1) {
		if(srcArr[i] >= srcArr[j]) {
			tempArr[k++] = srcArr[j++];
		} else {
			tempArr[k++] = srcArr[i++];
		}
	}

	while(i != midIndex+1) {
		tempArr[k++] = srcArr[i++];
	}

	while(j != endIndex+1) {
		tempArr[k++] = srcArr[j++];
	}

	for(i = startIndex; i <= endIndex; ++i) 
		srcArr[i] = tempArr[i];
}

void MergeSort(int srcArr[], int tempArr[], int startIndex, int endIndex) {
	int midIndex = (startIndex + endIndex) / 2;
	if(startIndex < endIndex) {
		MergeSort(srcArr, tempArr, startIndex, midIndex);
		MergeSort(srcArr, tempArr, midIndex+1, endIndex);
		Merge(srcArr, tempArr, startIndex, midIndex, endIndex);
	}
}

int main(void) {
	int a[] = {50, 10, 20, 30, 70, 40, 80, 60};
	int i, b[8];
	MergeSort(a, b, 0, 7);
	for(i = 0; i < 8; ++i) {
		cout << a[i] << " ";
	}	
	cout << endl;
	return 0;
}