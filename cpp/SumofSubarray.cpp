#include <iostream>
#include <vector>

using namespace std;
//int FindGreatestSumOfSubArray(vector<int> array);
int FindGreatestSumOfSubArray(vector<int> array) {
    int sum = 0;
    int len = array.size();
    int max = 0;

    if(len == 0)
        return 0;

    for(int i = 0; i < len; ++i) {
        if(array[i] < 0) {
            max = sum;
            sum += array[i];
        } else {
            sum += array[i];
            if(sum > max)
                max = sum;
        }

        if(sum < 0)
            sum = 0;
    }

    return sum;
}
int main(void) {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(-2);
    vec.push_back(3);
    vec.push_back(10);
    vec.push_back(-4);
    vec.push_back(7);
    vec.push_back(2);
    vec.push_back(-5);
    FindGreatestSumOfSubArray(vec);
    cout << FindGreatestSumOfSubArray(vec);
    return 0;
}
