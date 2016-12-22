#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, f[205], ax[105], ay[105], x[105], y[105];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy)
		return;
	f[fx] = fy;
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	int nx = 0, ny = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		ax[nx ++] = x[i];
		ay[ny ++] = y[i];
	}
	sort(ax, ax + nx);
	sort(ay, ay + ny);
	nx = unique(ax, ax + nx) - ax;
	ny = unique(ay, ay + ny) - ay;
	for (int i = 0; i < nx + ny; ++i) f[i] = i;
	for (int i = 0; i < n; ++i) {
		int px = lower_bound(ax, ax + nx, x[i]) - ax;
		int py = lower_bound(ay, ay + ny, y[i]) - ay;
		merge(px, py + nx);
	}
	int cnt = 0;
	for (int i = 0; i < nx + ny; ++i)
		if (i == find(i))
			cnt ++;
	printf("%d\n", cnt - 1);
	return 0;
}
