#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	void putValueIntoVec(vector<int>& temp, unsigned int small, unsigned int big) {
		//vector<int> temp;
		for(int i = small; i <= big; ++i)
			temp.push_back(i);
		//return temp;
	}
    vector<vector<int> > FindContinuousSequence(int sum) {
       	
       	vector<vector<int> > result; 
 		if(sum < 3)
 			return result;

 		unsigned int small = 1;
 		unsigned int big = 2;
 		unsigned int cursum = 3;
 		unsigned int mid = (sum + 1) / 2;

 		/*
 		while (small < mid) {
 			vector<int> temp;
 			if(cursum == sum) {
 				//vector<int> temp;
 				temp.clear();
 				putValueIntoVec(temp, small, big);
 				result.push_back(temp);
 			}
 			while(cursum > sum && small < mid) {
 				cursum -= small;
 				small ++;

 				if(cursum == sum) {
 					temp.clear();
 					putValueIntoVec(temp, small, big);
 					result.push_back(temp);
 				}
 			}
 			big ++;
 			cursum += big;
 		}
 		*/

 		while(small < mid) {
 			vector<int> temp;

 			if(cursum == sum) {
 				temp.clear();
 				putValueIntoVec(temp, small, big);
 				result.push_back(temp);
 				big ++;
 				cursum += big;
 			} else if (cursum > sum) {
 				cursum -= small;
 				small ++;
 			} else if (cursum < sum) {
 				big ++;
 				cursum += big;
 			}
 		}

 		

 		return result;
    }
};

int main(void) {
	Solution s;
	vector<vector<int> >result;
	result = s.FindContinuousSequence(15);
	for(int i = 0; i < result.size(); ++i) {
		for(int j = 0; j < result[i].size(); ++j)
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}