#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct Trie{
	int child[26];
	void clear() {
		memset(child, -1, sizeof child);
	}
}pool[1000005];
int tp = 0;
int add(string& s) {
	int p = 0, res = 0, flag = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		int ch = s[i] - 'a';
		if (pool[p].child[ch] == -1) {
			pool[tp].clear();
			pool[p].child[ch] = tp++;
			flag = 1;
		} else {
			res ++;
		}
		p = pool[p].child[ch];
	}
	return res + flag;
	return min(res + 1, (int)s.size());
}
void solve() {
	int ans = 0, n;
	cin >> n;
	tp = 1,	pool[0].clear();
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		int res = add(s);
		// printf("%d\n", res);
		ans += res;
	}
	printf("%d\n", ans);
}
int main() {
	freopen("autocomplete.txt", "r", stdin);
	freopen("autocomplete.out", "w", stdout);
	int __; scanf("%d", &__);
	for (int _ = 1; _ <= __; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}