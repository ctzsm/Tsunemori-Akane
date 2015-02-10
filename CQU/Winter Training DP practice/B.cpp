#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int N, n, c, m[35];
bool f[3000005];
double T, p;
char s[50];
int main() {
	freopen("in", "r", stdin);
	while (true) {
		scanf("%lf%d", &T, &N);
		if (N == 0) break;
		n = 0;
		for (int i = 0; i < N; ++i) {
			double p, tot[3] = {0.0, 0.0, 0.0};
			bool flag = true;
			scanf("%d", &c);
			for (int i = 0; i < c; ++i) {
				scanf("%s", s);
				p = atof(s + 2);
				if (!('A' <= s[0] && s[0] <= 'C'))
					flag = false;
				else
					tot[s[0] - 'A'] += p;
			}
			double x = tot[0] + tot[1] + tot[2];
			if (flag && x <= 1000.0 && tot[0] <= 600.0 && tot[1] <= 600.0 && tot[2] <= 600.0)
				m[n++] = (int)(x * 100);
		}
		int V = (int)(T * 100);
		memset(f, false, sizeof f); f[0] = true;
		for (int i = 0; i < n; ++i) 
			for (int j = V; j >= m[i]; --j)
				f[j] |= f[j - m[i]];
		for (int i = V; i >= 0; --i) {
			if (f[i]) {
				printf("%.2lf\n", i / 100.0);
				break;
			}
		}
	}
	return 0;
}