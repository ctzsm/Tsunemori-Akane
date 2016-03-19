#include <queue>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
	int fail, child[26], ind, cnt;
	void clear() {
		memset(child, -1, sizeof child);
		fail = ind = -1;
		cnt = 0;
	}
}pool[250005];
int counter = 0, root = 0;
int new_node() {
	pool[counter++].clear();
	return counter - 1;
}
int n, ans[505];
char s[505], t[1000005];
void insert(char s[], int ind) {
	int p = root;
	for (int i = 0; s[i]; ++i) {
		int c = s[i] - 'a';
		if (pool[p].child[c] == -1)
			pool[p].child[c] = new_node();
		p = pool[p].child[c];
	}
	if (pool[p].ind == -1)
		pool[p].ind = ind;
	else
		ans[ind] = -pool[p].ind;
}
void init() {
	queue<int> q; q.push(root);
	while (!q.empty()) {
		int p = q.front(); q.pop();
		for (int i = 0; i < 26; ++i) {
			int c = pool[p].child[i];
			if (c == -1) continue;
			int fail = pool[p].fail;
			while (~fail) {
				if (~pool[fail].child[i]) {
					pool[c].fail = pool[fail].child[i];
					break;
				}
				fail = pool[fail].fail;
			}
			if (fail == -1)
				pool[c].fail = root;
			q.push(c);
		}
	}
}
int match[250005];
void query() {
	int p = root, cnt = 0;
	for (int i = 0; t[i]; ++i) {
		int c = t[i] - 'a';
		while (pool[p].child[c] == -1 && p != 0) p = pool[p].fail;
		if (pool[p].child[c] == -1) continue;
		p = pool[p].child[c];
		if (pool[p].cnt == 0)
			match[cnt++] = p;
		pool[p].cnt ++;
	}
	for (int i = 0; i < cnt; ++i) {
		int t = match[i];
		int tot = pool[t].cnt;
		while (t) {
			if (~pool[t].ind) ans[pool[t].ind] += tot;
			t = pool[t].fail;
		}
	}
}
void solve() {
	counter = 0;
	root = new_node();
	scanf("%d", &n);
	scanf("%s", t);
	memset(ans, 0, sizeof ans);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		insert(s, i);
	}
	init();
	query();
	for (int i = 0; i < n; ++i) {
		if (ans[i] >= 0)
			printf("%d\n", ans[i]);
		else
			printf("%d\n", ans[-ans[i]]);
	}
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		solve();
	}
	return 0;
}
