#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct trie {
	int child[4], cnt;
}pool[50000 * 20];
int tcnt = 0, root = 0;
inline int getId(char c) {
	switch (c) {
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}
	return -1;
}
inline void newNode(int x) {
	memset(pool[x].child, -1, sizeof pool[x].child);
	pool[x].cnt = 0;
}
void add(char s[], int p) {
	for (int i = 0; s[i]; ++i) {
		int u = getId(s[i]);
		if (pool[p].child[u] == -1) {
			pool[p].child[u] = tcnt;
			newNode(tcnt++);
		}
		p = pool[p].child[u];
		pool[p].cnt ++;
	}
}
int bfs() {
	queue<pair<int, int> > q;
	q.push(make_pair(root, 0));
	int res = 0;
	while (!q.empty()) {
		pair<int, int> u = q.front(); q.pop();
		res = max(res, pool[u.first].cnt * u.second);
		for (int i = 0; i < 4; ++i) {
			int v = pool[u.first].child[i];
			if (v == -1) continue;
			q.push(make_pair(v, u.second + 1));
		}
	}
	return res;
}
char s[55];
int solve() {
	int n; scanf("%d", &n);
	tcnt = 0;
	newNode(tcnt++);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		add(s, root);
	}
	return bfs();
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
