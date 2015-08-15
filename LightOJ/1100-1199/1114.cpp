#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, q;
void solve() {
	map<string, int> h;
	cin >> n;
	string s; 
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (s.size() > 2)
			sort(s.begin() + 1, s.end() - 1);
		h[s]++;
	}
	cin >> q;
	getline(cin, s);
	while (q--) {
		int ans = 1;
		getline(cin, s);
		string t = "";
		for (int i = 0; i < s.size(); ++i) {
			if (isalpha(s[i])) {
				t += s[i];
			} else {
				if (t.size() > 0) {
					if (t.size() > 2)
						sort(t.begin() + 1, t.end() - 1);
					if (h.find(t) == h.end()) {
						ans = 0;
						break;
					}
					ans *= h[t];
				}
				t = "";
			}
		}
		if (t.size() > 0) {
			if (t.size() > 2)
				sort(t.begin() + 1, t.end() - 1);
			if (h.find(t) == h.end())
				ans = 0;
			else
				ans *= h[t];
		}
		printf("%d\n", ans);
	}
}
int main() {
	freopen("in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		solve();
	}
	return 0;
}
