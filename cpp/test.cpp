#include <iostream>using namespace std;float waitingTimeSJF(int *, int *, int);int main(void) {	float result;	int a[] = {0, 2, 4, 5};	int b[] = {7, 4, 1, 4};	result = waitingTimeSJF(a, b, 4);	std::cout << result << endl;	return 0; }float waitingTimeSJF(int *requestTimes, int *durations, int n) {	/*	bool flag[] = new bool[4];	for(int i = 0; i < 4; ++i)		flag[i] = false;	*/	bool flag[] = {false, false, false, false};	int sum = 0;	int wait = 0;	int times = 0;	//int min = durations[0];	//int remin = requestTimes[0];	int index = 0;	for(int i = 1; i < n; ++i) {		flag[0] = true;		times = durations[0];		int min = 1000000;		int remin = 1000000;		if(durations[i] < min && flag[i] == false) {			flag[index] = false;			min = durations[i];			remin = requestTimes[i];			flag[i] = true;			index = i;		} else if(durations[i] == min && flag[i] == false) {			if(requestTimes[i] < remin) {				flag[index] = false;				min = durations[i];				remin = requestTimes[i];				flag[i] = true;				index = i;				}			wait = times - remin;			sum += wait;		}		}	return ((float)sum)/n;}