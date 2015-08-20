#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

string s[10005];
bool solve() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	sort(s, s + n);
	for (int i = 0, j = 1; j < n; ++i, ++j) {
		if (s[i].size() > s[j].size()) continue;
		bool flag = true;
		for (int k = 0; k < s[i].size(); ++k) {
			if (s[i][k] != s[j][k]) {
				flag = false;
				break;
			}
		}
		if (flag) return false;
	}
	return true;
}
int main() {
	freopen("in", "r", stdin);
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %s\n", _, solve() ? "YES" : "NO");
	return 0;
}
