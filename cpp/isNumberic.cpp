#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;
class Solution {
public:
    bool isValidChar(char c) {
        if((c >= '0' && c <= '9') || c == 'e' || c == 'E' || c == '+' || c == '-' || c == '.')
            return true;
        return false;
    }
    
    bool isNumeric(char* string)
    {
        if(strlen(string) == 0)
            return false;
        
        bool isEappear = false;
        bool isBotappear = false;
        
        for(int i = 0; i < strlen(string); ++i) {
        	if(!isValidChar(string[i])) 
                return false;
            if(string[i] == '+' || string[i] == '-') {
                if(i > 0) {
                    if(string[i-1] != 'e' && string[i-1] != 'E')
                        return false;
                }
            } else if(string[i] == 'e' || string[i] == 'E') {
                if(i == 0)
                    return false;
                else {
                    isEappear = true;
                }
            } else if (string[i] == '.') {
                if(isEappear)
                    return false;
                if(isBotappear)
                    return false;
                isBotappear = true;
            }
        }
        return true;
    }

};

int main(void) {
	Solution s;
	cout << s.isNumeric("123.45e+6") << endl;
	return 0;
}