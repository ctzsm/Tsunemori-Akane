#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
const int base[3] = {26 * 26, 26, 1};
int T;
char s[4], a[30], b[30], c[30];
int d[20000];
int encode(char x[]) {
	int res = 0;
	for (int i = 0; i < 3; ++i) {
		res *= 26;
		res += x[i] - 'a';
	}
	return res;
}
int solve() {
	scanf("%s", s);
	int start = encode(s);
	scanf("%s", s);
	int finish = encode(s);
	memset(d, 0x3f, sizeof d);
	int m; scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%s%s%s", a, b, c);
		int la = strlen(a), lb = strlen(b), lc = strlen(c);
		for (int x = 0; x < la; ++x)
			for (int y = 0; y < lb; ++y)
				for (int z = 0; z < lc; ++z) {
					char t[3] = {a[x], b[y], c[z]};
					d[encode(t)] = -1;
				}
	}
	queue<int> q;
	if (d[start] != -1) d[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == finish) break;
		if (d[now] == -1) continue;
		int x[3], y = now;
		for (int i = 0; i < 3; ++i) {
			x[2 - i] = y % 26;
			y /= 26;
		}
		for (int i = 0; i < 3; ++i)
			for (int j = -1; j < 2; j += 2) {
				int digit = (x[i] + j + 26) % 26;
				int nxt = now - base[i] * x[i] + base[i] * digit;
				if (d[nxt] != oo) continue;
				d[nxt] = d[now] + 1;
				if (nxt == finish) return d[nxt];
				q.push(nxt);
			}
	}
	return d[finish] == oo ? -1 : d[finish];
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
