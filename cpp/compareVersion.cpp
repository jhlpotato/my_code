#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;


vector<int> convertVersion(const string version) {
        vector<int> result;
        int start = 0;
        for(int i = 0; i <= version.length(); ++i) {
            if(version[i] == '.' || version[i] == '\0') {
                string str = version.substr(start, i-start);
                const char* temp = str.c_str();
                int itemp = atoi(temp);
                result.push_back(itemp);
                start = i+1;
            }
        }
        return result;
    }

int main(void) {
	//Solution s;
	vector<string> result;
	vector<int> vec;

	vec = convertVersion("123.123.213.123");
	for(int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
	cout << atoi("01") << endl;
	string str = "1212313";
	cout << stoi(str) << endl;
	
	return 0;
}