#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	if(n <= 0)
            return 0;
        
        char strN[50];
        sprintf(strN, "%d", n);
        
        return NumberOf1(strN);
    }
    
    int NumberOf1(const char* strN) {
        if(!strN || *strN < '0' || *strN > '9' || *strN == '\0') 
            return 0;
        
        int first = *strN - '0';
        unsigned int length = static_cast<unsigned int>(strlen(strN));
        
        if(length == 1 && first == 0)
            return 0;
        if(length == 1 && first > 0)
            return 1;
        
        int firstnum = 0;
        if(firstnum > 1)
            firstnum = powerBase10(length-1);
        else if(firstnum == 1)
            firstnum = atoi(strN+1) + 1;
            
        int othernum = first * (length-1) * powerBase10(length-2);
        int recursivenum = NumberOf1(strN+1);
        
        return firstnum + othernum + recursivenum;
    }
    
    int powerBase10(int n) {
        int sum = 1;
        for(int i = 0; i < n; ++i)
            sum *= 10;
        return sum;
    }
};

int main(void) {
    Solution* s = new Solution();
    int temp = s->NumberOf1Between1AndN_Solution(10);
    cout << temp << endl;
    return 0;
}