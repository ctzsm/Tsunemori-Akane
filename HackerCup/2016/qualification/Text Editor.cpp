#include <sys/resource.h>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct trie {
	int ch[26], id, cnt;
}pool[100005];
int n, k, f[1005][305], g[1005], root, inp, pt;
char s[100005];
int newNode() {
	memset(pool[pt].ch, 0, sizeof pool[pt].ch);
	pool[pt].id = pool[pt].cnt = 0;
	return pt++;
}
void add(char s[], int id) {
	int p = root;
	for (int i = 0; s[i]; ++i) {
		int c = s[i] - 'a';
		if (!pool[p].ch[c]) {
			pool[p].ch[c] = newNode();
			pool[p].cnt ++;
		}
		if (pool[p].cnt > 1 && pool[p].id == 0 && p != 0)
			pool[p].id = inp ++;
		p = pool[p].ch[c];
	}
	pool[p].id = id;
}
vector<int> adj[605];
void dfs1(int u, int p, int w) {
	if (pool[u].id) {
		adj[p].push_back(pool[u].id);
		g[pool[u].id] = w;
	}
	for (int i = 0; i < 26; ++i) if (pool[u].ch[i]) {
		if (pool[u].id) {
			dfs1(pool[u].ch[i], pool[u].id, 1);
		} else {
			dfs1(pool[u].ch[i], p, w + 1);
		}
	}
}
void dfs2(int u) {
	f[u][0] = g[u];
	if (0 < u && u <= n) f[u][1] = g[u];
	for (int i = 0; i < adj[u].size(); ++i)
		dfs2(adj[u][i]);
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		for (int a = k; a >= 0; --a) {
			for (int b = 0; a + b <= k; ++b) {
				f[u][a + b] = min(f[u][a + b], f[u][a] + f[v][b]);
			}
		}
	}
}
int solve() {
	pt = 0;
	root = newNode();
	scanf("%d%d", &n, &k);
	inp = n + 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s);
		add(s, i);
	}
	for (int i = 0; i < inp; ++i) adj[i].clear();
	memset(g, 0, sizeof g);
	dfs1(0, 0, 0);
	memset(f, 0x3f, sizeof f);
	dfs2(0);
	return f[0][k] * 2 + k;
}
int main() {
	const rlim_t kStackSize = 32 * 1024 * 1024;   // min stack size = 256 MB
	struct rlimit rl;
	int result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0) {
		if (rl.rlim_cur < kStackSize) {
			rl.rlim_cur = kStackSize;
			result = setrlimit(RLIMIT_STACK, &rl);
			if (result != 0) {
				fprintf(stderr, "setrlimit returned result = %d\n", result);
			}
		}
	}
	freopen("text_editor.txt", "r", stdin);
	freopen("text_editor.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case #%d: %d\n", _, solve());
	return 0;
}
