#include <bits/stdc++.h>

using namespace std;

int T;
int main() {
	scanf("%d", &T);
	while (T--) {
		string s; cin >> s;
		int ans = 0, n = (int)s.size();
		for (int i = 0; i < (int)s.size() / 2; ++i) {
			ans += abs(s[i] - s[n - i - 1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}