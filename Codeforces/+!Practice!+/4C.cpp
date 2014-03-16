#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
map<string, int> dict;
int main(void) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		if (dict.find(s) == dict.end()) {
			cout << "OK" << endl;
			dict[s] = 0;
		} else {
			dict[s] ++;
			cout << s << dict[s] << endl;
		}
	}
	return 0;
}