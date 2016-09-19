#include <iostream>

using namespace std;

// x 和 y 的二进制的对应的位数0和1正好相反
int main(void) {
	unsigned int x, k;
	unsigned int flag = 0;
	cin >> x >> k;
	if(x < 0 || k < 0 || x > 2000000000 || k > 2000000000)
		cout << 0 << endl;

	unsigned int count = 0;
	unsigned int temp = 0;
	int val = 2;
	unsigned int number = 0;
	while(temp <= 2000000000 && count < k) {
		number = val - 1;
		val *= 2;
		temp = ~x & number;
		//flag = temp;
		if(temp != 0 && flag != temp)
			count ++;
		flag = temp;
	}
	cout << temp << endl;
	return 0;
}