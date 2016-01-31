#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;
char s[1005];
int n;
int diff(int p) {
	set<char> cs;
	for (int i = max(0, p - 1); i <= min(n - 1, p + 1); ++i) {
		cs.insert(s[i]);
	}
	return cs.size();
}
long long main2() {
	scanf("%s", s);
	n = strlen(s);
	long long ans = 1;
	for (int i = 0; s[i]; ++i) {
		ans = ans * diff(i) % mod;
	}
	return ans;
}
int main() {
	// freopen("in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case #%d: %lld\n", _, main2());
	return 0;
}
