#include <stack>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[5005];
int m[20];
long long eval(int i, int j, int mi, int mj, bool flag = true) {
	stack<long long> S;
	long long res = 0;
	for (int k = i + 1; k < j; k += 2) {
		if (k > i + 1 && s[k - 1] == '*') {
			long long x = S.top(); S.pop();
			if (k - 1 == mi && flag) {
				S.push(x * eval(mi, mj, 0, 0, false));
				k = mj - 1;
			} else S.push(x * (s[k] - '0'));
		} else {
			if (k - 1 == mi && flag) {
				S.push(eval(mi, mj, 0, 0, false));
				k = mj - 1;
			} else S.push(s[k] - '0');
		}
	}
	while (!S.empty()) {
		res += S.top();
		S.pop();
	}
	return res;
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%s", s + 1);
	int n = strlen(s + 1), mc = 0;
	m[mc++] = 0;
	for (int i = 1; i <= n; ++i) if (s[i] == '*')
		m[mc++] = i;
	m[mc++] = n + 1;
	long long ans = eval(0, n + 1, 0, 0, false);
	for (int i = 0; i < mc; ++i)
		for (int j = i + 1; j < mc; ++j)
			ans = max(ans, eval(0, n + 1, m[i], m[j]));
	printf("%lld\n", ans);
	return 0;
}
