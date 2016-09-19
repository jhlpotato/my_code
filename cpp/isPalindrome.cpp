#include <iostream>
#include <vector>
#include <string>

using namespace std;

string preHandleString(string s) {
        string result;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                char ctemp = s[i] + ('a' - 'A');
                result.push_back(ctemp);
            } else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                result.push_back(s[i]);
            } 
        }
        return result;
    }
int main(void) {

	cout << preHandleString("0P") << endl;
	return 0;
}