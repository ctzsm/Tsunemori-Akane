#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct trie {
	int c[2];
}pool[50000 * 32];
int R, root;
int new_node() {
	trie& t = pool[R];
	t.c[0] = t.c[1] = -1;
	return R++;
}
void add(int x) {
	int p = root;
	for (int i = 30; i > -1; --i) {
		int v = (x & (1 << i)) > 0;
		if (pool[p].c[v] == -1) {
			pool[p].c[v] = new_node();
		}
		p = pool[p].c[v];
	}
}
int find(int x) {
	int p = root, res = 0;
	for (int i = 30; i > -1; --i) {
		int v = (x & (1 << i)) > 0;
		if (pool[p].c[v] == -1) v ^= 1;
		if (v)
			res ^= (1 << i);
		p = pool[p].c[v];
	}
	return res;
}
int a[50005];
void solve(int _) {
	int n, s = 0; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	R = 0; root = new_node(); add(0);
	int mx = INT_MIN, mi = INT_MAX;
	for (int i = 0; i < n; ++i) {
		s ^= a[i];
		mx = max(mx, s);
		mi = min(mi, s);
		int x = find(s);
		int y = find(~s);
		mx = max(mx, s ^ y);
		mi = min(mi, s ^ x);
		add(s);
	}
	printf("Case %d: %d %d\n", _, mx, mi);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) solve(_);
	return 0;
}
