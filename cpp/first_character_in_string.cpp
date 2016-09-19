#include <iostream>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty())
            return -1;
        
        int len = str.length();
        int array[257];
        for(int i = 0; i < 257; ++i)
            array[i] = 0;
        
        for(int i = 0; i < len ; ++i) {
            int temp = static_cast<int>(str[i]);
            array[temp] ++;
        }
        
        for(int i = 0; i < len; ++i) {
            if(array[static_cast<int>(str[i])] == 1)
                return i;
        }
        return -1;
    }
};

int main(void) {
	Solution s;
	cout << s.FirstNotRepeatingChar("google") << endl;
	return 0;
}