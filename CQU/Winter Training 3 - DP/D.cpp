#include <cstdio>
#include <cstring>
#include <algorithm>

int c[7], nCase = 1;
char no[] = "Can't be divided.";
char yes[] = "Can be divided.";
bool f[120005];
int main() {
	freopen("in", "r", stdin);
	while (true) {
		int tot = 0, sum = 0;
		for (int i = 1; i <= 6; ++i) {
			scanf("%d", &c[i]);
			tot += c[i];
			sum += i * c[i];
		}
		if (!tot) break;
		printf("Collection #%d:\n", nCase++);
		if (sum & 1) {
			printf("%s\n\n", no);
			continue;
		}
		sum >>= 1;
		memset(f, false, sizeof f);
		f[0] = true;
		for (int i = 1; i <= 6; ++i) {
			int k = 1;
			while (true) {
				int m = i * (k > c[i] ? c[i] : k);
				for (int v = sum - m; v >= 0; --v)
					if (f[v])
						f[v + m] = true;
				if (k >= c[i]) break;
				c[i] -= k;
				k <<= 1;
			}
		}
		// for (int i = 0; i <= sum / 2; ++i) printf("%d ", f[i]); printf("\n");
		printf("%s\n\n", f[sum] ? yes : no);
	}
	return 0;
}