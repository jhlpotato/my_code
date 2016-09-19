#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        
        int flag = nums[0];
        int count = 0;
        int maxcount = 0;
        for(int i = 0; i < size; ++i) {
            flag = nums[i];
            count = 1;
            for(int j = i; j < size; ++j) {
                if(nums[j] > flag) {
                    count ++;
                    flag = nums[j];
                }
            }
            if(count > maxcount) {
                maxcount = count;
            }
        }
        return maxcount;
    }
};

int main(void) {
	Solution s;
	vector<int> vec = {10, 9, 2, 5, 3, 4};
	cout << s.lengthOfLIS(vec) << endl;
	return 0;
}