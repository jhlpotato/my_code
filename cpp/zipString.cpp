#include <iostream>

using namespace std;

class Zipper {
public:
    string zipString(string iniString) {
        // write code here
        string result;
        int len = iniString.length();
        if(len == 1)
            return iniString;
        
        char temp = iniString[0];
        int start = 0;
        for(int i = 0; i < len; ++i) {
            if(iniString[i] != temp) {
                result.push_back(temp);
                result.push_back(i-start+48);
                temp = iniString[i];
                start = i;
            }
            if(i == len-1) {
                result.push_back(temp);
                result.push_back(i-start+1+48);
            }
            
        }
        
        int relen = result.length();
        if(relen < len)
            return result;
        else
            return iniString;
    }
};

int main(void) {
	Zipper z;
	cout << z.zipString("") << endl;

	int a = 123123;
	cout << "jinhongl" + a << endl;
	return 0;
}