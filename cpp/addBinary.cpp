#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        string result;
        
        if(alen == 0 && blen == 0)
            return "0";
        if(alen != 0 && blen == 0)
            return a;
        if(alen == 0 && blen != 0)
            return b;
        
        //int i = alen > blen ? blen-1 : alen-1;
        int flag = 0;
        int temp = 0;
        int ia = 0, ib = 0;
        alen --;
        blen --;
        while(alen >= 0 && blen >= 0) {
            ia = (int)(a[alen] - '0');
            ib = (int)(b[blen] - '0');
            flag = (ia + ib + flag) / 2;
            temp = (ia + ib + flag) % 2;
            result.push_back((char)(temp) + '0');
            alen --;
            blen --;
        }
        
        while(alen >= 0) {
            ia = (int)(a[alen] - '0');
            flag = (ia + flag) / 2;
            temp = (ia + flag) % 2;
            result.push_back((char)(temp) + '0');
            alen --;
        }
        
        while(blen >= 0) {
            ib = (int)(b[blen] - '0');
            flag = (ib + flag) / 2;
            temp = (ib + flag) % 2;
            result.push_back((char)(temp) + '0');
            blen --;
        }
        
        if(flag == 1) {
            result.push_back('1');
        }
        
        return result;
    }
};

int main(void) {
	Solution s;
	cout << s.addBinary("11", "11") << endl;
	return 0;
}