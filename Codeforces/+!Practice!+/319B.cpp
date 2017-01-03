#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int n, a[maxn], b[2][maxn], l[2], f[maxn];
bool removed[maxn];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return;
	f[fx] = fy;
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i <= n; ++i) f[i] = i;
	for (int i = 0; i < n; ++i)
		b[0][l[0] ++] = i;
	int ans = 0, now = 0, pre = 1;
	bool flag = false;
	do {
		flag = false;
		swap(now, pre);
		l[now] = 0;
		for (int i = 0; i < l[pre]; ++i) {
			int c = b[pre][i];
			int nxt = find(c) + 1;
			if (nxt != n && a[c] > a[nxt]) {
				removed[nxt] = flag = true;
				merge(c, nxt);
				if (!removed[c])
					b[now][l[now] ++] = c;
			}
		}
		if (flag)
			ans ++;
	} while (flag);
	printf("%d\n", ans);
	return 0;
}
