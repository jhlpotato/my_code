#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str;
        if(n == 0)
            return str;
            
        str += to_string(1);
        if(n == 1)
            return str;
        char flag = str[0];
        int start = 0;
        string temp;
        for(int i = 1; i < n; ++i) {
            temp.clear();
            flag = str[0];
            start = 0;
            for(int j = 0; j <= str.length(); ++j) {
                if(str[j] != flag || str[j] == '\0') {
                    temp += to_string(j-start);
                    temp.push_back(flag);


                    if(str[j] == '\0') {
                    	str = temp;
                    	break;
                    }
                    flag = str[j];
                    start = j;
                    //str = temp;
                }
            }        
        }
        return temp;
    }
};

int main(void) {
	Solution s;
	cout << s.countAndSay(7) << endl;
	return 0;
}