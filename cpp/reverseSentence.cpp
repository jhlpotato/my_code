#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	void reverse(string& str, int start, int end) {
		while(start < end) {
			char temp = str[start];
			str[start] = str[end];
			str[end] = temp;
			start ++;
			end --;
		}
	}

    string ReverseSentence(string str) {
		if(str.length() == 0)
			return str;

		int start = 0;
		int end = str.length()-1;
		reverse(str, start, end);

		start = end = 0;
		while(str[start] != '\0') {
			if(str[start] == ' ') {
				start ++;
				end ++;
			} else if (str[end] == ' ' || str[end] == '\0') {
				reverse(str, start, --end);
				start = ++end;
			} else {
				++ end;
			}
		}
		return str;        
    }
};

int main(void) {
	Solution s;
	string str = "jin hong liang";
	cout << s.ReverseSentence(str) << endl;
	return 0;
}