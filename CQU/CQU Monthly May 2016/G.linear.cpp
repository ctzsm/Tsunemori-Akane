#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int n, m, cntp, f[2000005], rk[2000005];
bool d[2000005];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
int find2(int x) {
	int fx = find(x);
	if (d[fx]) {
		rk[x] = 1;
		fx = f[x] = x;
	}
	return fx;
}
void merge(int x, int y) {
	int fx = find2(x), fy = find2(y);
	if (fx == fy) return;
	if (fx <= n) {
		int tfx = cntp++;
		f[tfx] = tfx;
		rk[tfx] = rk[fx];
		f[fx] = tfx;
		fx = tfx;
	}
	if (fy <= n) {
		int tfy = cntp++;
		f[tfy] = tfy;
		rk[tfy] = rk[fy];
		f[fy] = tfy;
		fy = tfy;
	}
	if (rk[fx] >= rk[fy]) {
		rk[fx] += rk[fy];
		f[fy] = fx;
	} else {
		rk[fy] += rk[fx];
		f[fx] = fy;
	}
}
char o[5];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		memset(d, false, sizeof d);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			f[i] = i;
			rk[i] = 1;
		}
		cntp = n + 1;
		while (m--) {
			scanf("%s", o);
			if (o[0] == 'U') {
				int x, y; scanf("%d%d", &x, &y);
				merge(x, y);
			}
			if (o[0] == 'D') {
				int x; scanf("%d", &x);
				int fx = find2(x);
				if (fx > n)
					d[fx] = true;
			}
			if (o[0] == 'S') {
				int x; scanf("%d", &x);
				int fx = find2(x);
				printf("%d\n", rk[fx]);
			}
			if (o[0] == 'F') {
				int x, y; scanf("%d%d", &x, &y);
				int fx = find2(x), fy = find2(y);
				puts(fx == fy ? "Yes" : "No");
			}
		}
	}
	return 0;
}
