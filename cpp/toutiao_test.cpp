#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n;
	//int maxnumber = 0;
	vector<vector<int>> tongji;
	vector<string> arr;
	vector<int> hashtable;
	int count = 9;
	int flag = 0;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		string temp;
		cin >> temp;		
		arr.push_back(temp);
	}

	for(int i = 0; i < 12; ++i) {
		vector<int> tempvec;
		
		for(int k = 0; k < 12; ++k)
			tempvec.push_back(0);

		for(int j = 0; j < n; ++j) {
			int len = arr[j].length();
			if(i >= len)
				continue;
			else 
				tempvec[static_cast<int>(arr[j][i]-'A')] ++;
		}
		tongji.push_back(tempvec);
	}

	int max = tongji[0][0];
	for(int i = 0; i < 12;) {
		for(int j = 0; j < 12;) {
			if(tongji[j][i] > max) {
				max = tongji[j][i];
				flag = j;
			}
			else
				j++;
		}
		hashtable[flag] = count;
		count --;
		i ++;
	}

	//int number = 1;
	vector<int> result;
	for(int i = 0; i < n; ++i) {
		int len = arr[i].length();
		int number = 1;
		int sum = 0;
		for(int j = len-1; j >= 0; j--) {
			sum += number * hashtable[static_cast<int>(arr[i][j]-'A')];
			number *= 10;
		}
		result.push_back(sum);
	}

	int total = 0;
	for(int i = 0; i < n; ++i) {
		total += result[i];	
	}

	cout << total << endl;

	return 0;
}