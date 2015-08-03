#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, a[10];
int g[10][10];
void print(int d) {
	for (int i = 0; i < d; ++i) printf(" ");
	printf("print( ");
	for (int k = 0; k < n; ++k) {
		if (k) printf(", ");
		printf("%c", a[k] + 'a');
	}
	printf(" );\n");
}
void dfs(int i, int j, int d) {
	if (i == n - 1) {
		print(d);
		return;
	}
	int ni = i, nj = j + 1;
	if (nj == n)
		ni = i + 1, nj = i + 2;
	if (g[a[i]][a[j]]) {
		swap(a[i], a[j]);
		dfs(ni, nj, d);
		swap(a[i], a[j]);
		return;
	}
	for (int i = 0; i < d; ++i) printf(" ");
	printf("if( %c < %c )\n", a[i] + 'a', a[j] + 'a');
	g[a[i]][a[j]] = g[a[j]][a[i]] = 2;
	dfs(ni, nj, d + 1);
	for (int i = 0; i < d; ++i) printf(" ");
	printf("else\n");
	swap(a[i], a[j]);
	dfs(ni, nj, d + 1);
	swap(a[i], a[j]);
	g[a[i]][a[j]] = g[a[j]][a[i]] = 0;
}
void solve() {
	scanf("%d", &n);
	memset(g, 0, sizeof g);
	for (int i = 0; i < n; ++i) a[i] = i;
	printf("void print( int a");
	for (int i = 1; i < n; ++i) printf(", int %c", i + 'a');
	printf(" ) {\n");
	printf(" printf( \"%%d");
	for (int i = 1; i < n; ++i) printf(" %%d");
	printf("\\n\", a");
	for (int i = 1; i < n; ++i) printf(", %c", i + 'a');
	printf(" );\n");
	printf("}\n");
	printf("void sort( int a");
	for (int i = 1; i < n; ++i) printf(", int %c", i + 'a');
	printf(" ) {\n");
	dfs(0, 1, 1);
	printf("}\n");
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
