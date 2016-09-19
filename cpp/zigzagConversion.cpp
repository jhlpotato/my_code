#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)
        	return s;

        string *arrs = new string[numRows];
        int step = 1;
        int row = 0;

        for(int i = 0; i < s.length(); ++i) {
        	arrs[row].push_back(s[i]);

        	if(row == 0)
        		step = 1;
        	else if(row == numRows-1)
        		step = -1;

        	row += step;
        }

        s.clear();

        for(int j = 0; j < numRows; ++j) {
        	s.append(arrs[j]);
        }

        delete[] arrs;
        return s;

    }
};

int main(void) {
	Solution s;
	cout << s.convert("PAYPALISHIRING", 3) << endl;
	return 0;
}