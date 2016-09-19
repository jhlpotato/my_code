#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int Min(int x, int y, int z) {
        int min = x < y ? x : y;
        min = min < z ? min : z;
        return min;
    }

    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;

        vector<int>uglynumber;
        uglynumber.push_back(1);
        int uglynext = 1;

        int multi2 = 0;
        int multi3 = 0;
        int multi5 = 0;

        while(uglynext < index) {
            int min = Min(uglynumber[multi2] * 2, uglynumber[multi3] * 3, uglynumber[multi5] * 5);
            uglynumber.push_back(min);

            while(uglynumber[multi2] * 2 <= uglynumber[uglynext])
                multi2 ++;
            while(uglynumber[multi3] * 3 <= uglynumber[uglynext])
                multi3 ++;
            while(uglynumber[multi5] * 5 <= uglynumber[uglynext])
                multi5 ++;

            uglynext ++;
        }

        return uglynumber[uglynext-1];
    }
};

int main(void) {
    Solution s;
    cout << s.GetUglyNumber_Solution(11) << endl;
    return 0;
}