#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N, T, M;
	vector<int> vec;
	vector<int> contain;
	int temp;	
	int count = 0;
	cin >> N >> T >> M;
	for(int i = 0; i < N; ++i) {
		cin >> temp;
		vec.push_back(temp);
	}

	for(int i = 0; i < M; ++i) {
		contain.push_back(T);
	}

	int j = 0;	
	for(int i = 0; i < vec.size(); ++i) {
		if(vec[i] =< contain[j]) {
			contain[j] -= vec[i];
			count ++;
		} else if(vec[i] > contain[j] && contain[j] != T) {
			j++;
			i--;
		}
	}
	cout << count << endl;
	return 0;
}