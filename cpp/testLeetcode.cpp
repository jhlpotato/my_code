#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> result;

void format(string& str, int i, int w) {
    int nums = 0;
    for(int in = i; in < w; ++ in) {
      if(str[in] != str[i] + nums)
        str[in] = str[i] + nums;
      nums ++;
    }
}

void func(int s, int t, int w, string str) {
  //int flag = t;
  for(int j = 0; j < 5; ++j) {
    int flag = t;
    for(int i = w-1; i >= 0; --i) {
      flag --;
      if(str[i] < ('a' + flag)) {
          str[i] += 1;
        format(str, i, w);
        result.push_back(str);
        break;
      } else {
        continue;
      }
    }
  }
}

int main(void) {
  int s, t, w;
  string str;
  cin >> s;
  cin >> t;
  cin >> w;
  cin >> str;
  func(s, t, w, str);
  for(int i = 0; i < result.size(); ++i) {
    cout << result[i] << endl;
  }
}