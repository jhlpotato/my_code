#include <iostream>

using namespace std;

class Reverse {
public:
    string reverseString(string iniString) {
        // write code here
        int len = iniString.length();
        if(len == 0 || len == 1)
            return iniString;
        
        for(int i = 0; i < len/2; ++i) {
            char temp = iniString[i];
            iniString[i] = iniString[len-1-i];
            iniString[len-1-i] = temp;
        }
        
        return iniString;
    }
};

int main(void) {
	Reverse r;
	cout << r.reverseString("12") << endl;

	return 0;
}