#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    	vector<int> result;

		if(array.size() < 2)
			return result;

		int ahead = 0;
		int behind = array.size() - 1;

		while(ahead < behind) {
			if(array[ahead] + array[behind] == sum) {
				result.push_back(array[ahead]);
				result.push_back(array[behind]);
				break;
			} else if(array[ahead] + array[behind] > sum) {
				behind --;
			} else if(array[ahead] + array[behind] < sum) {
				ahead ++;
			}
		}

		return result;
    }
};

int main(void) {
	vector<int> vec;
	/*
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(11);
	vec.push_back(15);
	*/
	vector<int> result;
	Solution s;
	result = s.FindNumbersWithSum(vec, 100);
	for(unsigned int i = 0; i < result.size(); ++i) {
		cout << result[i] << " " << endl;
	}
	return 0;
}
