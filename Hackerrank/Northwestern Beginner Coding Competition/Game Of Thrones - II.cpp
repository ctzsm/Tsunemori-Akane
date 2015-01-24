#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;
int cnt[26];
long long f[100005] = {1};
long long modPow(long long x, long long k, long long m) {
	long long res = 1, p = x;
	while (k) {
		if (k & 1) res = res * p % m;
		p = p * p % m;
		k >>= 1;
	}
	return res;
}
int main() {
	freopen("in", "r", stdin);
	string s; cin >> s;
	for (int i = 0; i < (int)s.size(); ++i)
		cnt[s[i] - 'a'] ++;
	for (int i = 1; i < (int)s.size(); ++i) 
		f[i] = f[i - 1] * i % mod;
	long long ans = f[s.size() / 2];
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] / 2 == 0) continue;
		ans = ans * modPow(f[cnt[i] / 2], mod - 2, mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}