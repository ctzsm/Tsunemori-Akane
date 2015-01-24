#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, vector<string> > h;
int main() {
	freopen("in", "r", stdin);
	while (true) {
		string s; cin >> s;
		if (s == "XXXXXX") break;
		string t = s;
		sort(t.begin(), t.end());
		if (h.find(t) == h.end()) {
			h[t] = vector<string>(1, s);
		} else {
			h[t].push_back(s);
		}
	}
	for (map<string, vector<string> >::iterator it = h.begin(); it != h.end(); ++it) {
		sort((it->second).begin(), (it->second).end());
	}
	while (true) {
		string s; cin >> s;
		if (s == "XXXXXX") break;
		sort(s.begin(), s.end());
		if (h.find(s) == h.end()) 
			cout << "NOT A VALID WORD" << endl;
		else {
			vector<string>& v = h[s];
			for (int i = 0; i < (int)v.size(); ++i)
				cout << v[i] << endl;
		}
		cout << "******" << endl;
	}
	return 0;
}