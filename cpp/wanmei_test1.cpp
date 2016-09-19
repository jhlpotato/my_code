#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> pro;

string fromNumberToString(int n) {
	string result;
	bool geflag = false, shiflag = false;
	vector<string> strvec;
	int temp;
	int count = 0;
	if(n >= 1000 || n <= 0)
		return result;

	while(n) {
		count ++;
		temp = n % 10;
		if(count == 1) {
			strvec.push_back(pro[temp]);
			if(temp == 0)
				geflag = true;
		}
		else if(count == 2) {
			if(temp == 0) {
				shiflag = true;
				strvec.push_back(pro[temp]);
			}
			else {
				if(geflag == true) 
					strvec.pop_back();
				strvec.push_back(pro[10]);
				strvec.push_back(pro[temp]);
			}
		} else if(count == 3) {
			if(geflag == true && shiflag == true){
				strvec.pop_back();
				strvec.pop_back();
			}
			strvec.push_back(pro[11]);
			strvec.push_back(pro[temp]);
		}
		n /= 10;
	}

	for(int i = strvec.size()-1; i >= 0; i--) {
		result = result + strvec[i];
	}

	return result;
}

int main(void) {
	pro.push_back("ling");
	pro.push_back("yi");
	pro.push_back("er");
	pro.push_back("san");
	pro.push_back("si");
	pro.push_back("wu");
	pro.push_back("liu");
	pro.push_back("qi");
	pro.push_back("ba");
	pro.push_back("jiu");
	pro.push_back("shi");
	pro.push_back("bai");

	string result;
	//vector<int> input;
	int temp;
	while(cin >> temp) {
		result = fromNumberToString(temp);
		cout << result << endl;
	}
	/*
	for(int i = 0; i < input.size(); ++i) {
		result.push_back(fromNumberToString(input[i]));
	}

	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
	*/

	return 0;
}