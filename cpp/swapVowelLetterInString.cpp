#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // upper and lower
    bool isVowels(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }
    
    string reverseVowels(string s) {
        if(s.length() == 0 || s.length() == 1)
            return s;
        int start = 0;
        int end = s.length()-1;
        while(start < end) {
            while(!isVowels(s[start]) && start < end) {
                start ++;
            }
            
            while(!isVowels(s[end]) && start < end) {
                end --;
            }
            
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start ++;
            end --;
        }
        
        return s;
    }
};

int main(void) {
    Solution s;
    cout << s.reverseVowels("leetcode") << endl;
    return 0;
}