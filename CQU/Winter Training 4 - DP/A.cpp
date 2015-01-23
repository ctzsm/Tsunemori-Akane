#include <bits/stdc++.h>

using namespace std;

int n, a[105], ans = 0;
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)  {
			int cnt = 0;
			for (int k = 0; k < n; ++k)
				if (k < i || k > j)
					cnt += a[k];
				else
					cnt += 1 - a[k];
			ans = max(ans, cnt);
		}
	printf("%d\n", ans);
	return 0;
}