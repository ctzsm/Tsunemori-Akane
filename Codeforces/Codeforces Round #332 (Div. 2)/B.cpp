#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int f[100005], b[100005], a[100005];
vector<int> invf[100005];
int main() {
	// freopen("in", "r", stdin);
	int n, m, pos = true, amb = false; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", f + i);
	for (int i = 1; i <= m; ++i) scanf("%d", b + i);
	for (int i = 1; i <= n; ++i) invf[f[i]].push_back(i);
	for (int i = 1; i <= m; ++i) {
		int l = invf[b[i]].size();
		if (l == 0) { pos = false; break; }
		if (l > 1) amb = true;
		a[i] = invf[b[i]][0];
	}
	if (!pos) { puts("Impossible"); return 0; }
	if (amb) { puts("Ambiguity"); return 0; }
	puts("Possible");
	for (int i = 1; i <= m; ++i) printf("%d%c", a[i], " \n"[i == m]);
	return 0;
}
