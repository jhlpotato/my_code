#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    unsigned int findBitIndex(int num) {
        if(num == 0)
            return 0;
        
        unsigned int bitindex = 0;
        while(((num & 1) == 0) && (bitindex < 8 * sizeof(int))) {
            num = num >> 1;
            bitindex ++;
        }
        return bitindex;
    }
    
    bool isBitIndex(int num, unsigned int bitindex) {
        num = num >> bitindex;
        return (num & 1);
    }
    
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		if(data.size() < 2)
            return;
        
        int result = 0;
        for(int i = 0; i < data.size(); ++i) {
            result ^= data[i];
        }
        unsigned int bitindex = findBitIndex(result);
        
        *num1 = *num2 = 0;
        for(int i = 0; i < data.size(); ++i) {
            if(isBitIndex(data[i], bitindex)) {
            	*num1 ^= data[i];
            } else {
            	*num2 ^= data[i];
            }
        }
    }
};

int main(void) {
	int num1 = 0;
	int num2 = 0;
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(5);
	Solution s;
	s.FindNumsAppearOnce(vec, &num1, &num2);
	cout << num1 << " " << num2 << endl;
	return 0;
}