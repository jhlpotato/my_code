#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int len = strs.size();
        if(len == 0)
            return result;
        int i = 0;
        int j = 0;
        bool flag = true;
        while(strs[0][i] != '\0') {
            for(j = 0; j < len; j++) {
                if(strs[j][i] != strs[0][i] || strs[j][i] == '\0') {
                    flag = false;
                    break;
                }
            }
            
            if(flag == true) {
                result.push_back(strs[0][i]);
                i ++;
            } else
                break;
        }
        return result;
    }
};

int main(void) {
	string str1 = "jinhongliang";
	string str2 = "jinadjfkall:a;fafal";
	vector<string> vec;
	vec.push_back(str1);
	vec.push_back(str2);
	Solution s;
	cout << s.longestCommonPrefix(vec) << endl;
	return 0;
}