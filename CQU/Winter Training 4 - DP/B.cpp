#include <bits/stdc++.h>

using namespace std;

int n, k, f[500005][26], p[500005][26];
char s[500005];
void print(int i, int j) {

}
int main() {
	freopen("in", "r", stdin);
	cin >> n >> k >> s;
	memset(f, 0x3f, sizeof f);
	memset(p, 0xff, sizeof p);
	for (int i = 0; i < k; ++i) f[0][i] = s[0] == i + 'A' ? 0 : 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			int c = j + 'A' == s[i] ? 0 : 1;
			for (int l = 0; l < k; ++l) {
				if (l == j) continue;
				if (f[i][j] > f[i - 1][l] + c) {
					f[i][j] = f[i - 1][l] + c;
					p[i][j] = l;
				}
			}
		}
	}
	int mj = 0;
	for (int i = 1; i < k; ++i) 
		if (f[n - 1][i] < f[n - 1][mj])
			mj = i;
	cout << f[n - 1][mj] << endl;
	string ans = "";
	for (int i = n - 1; i >= 0; --i) {
		ans += mj + 'A';
		mj = p[i][mj];
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}