#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, S, L;
int m[105][105], s[105], l[105];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &L);
		memset(m, 0x3f, sizeof m);
		memset(s, 0, sizeof s);
		memset(l, 0, sizeof l);
		for (int i = 1; i <= 100; ++i) m[i][i] = 0;
		for (int i = 0; i < L; ++i) {
			int x, y; scanf("%d%d", &x, &y);
			l[x] = y;
		}
		scanf("%d", &S);
		for (int i = 0; i < S; ++i) {
			int x, y; scanf("%d%d", &x, &y);
			s[x] = y;
		}
		for (int i = 1; i < 100; ++i) {
			for (int j = 1; j <= 6; ++j) {
				int x = i + j;
				if (x > 100) continue;
				if (s[x]) m[i][s[x]] = 1;
				else if (l[x]) m[i][l[x]] = 1;
				else m[i][x] = 1;
			}
		}
		for (int k = 1; k <= 100; ++k)
			for (int i = 1; i <= 100; ++i)
				for (int j = 1; j <= 100; ++j)
					if (m[i][k] + m[k][j] < m[i][j])
						m[i][j] = m[i][k] + m[k][j];
		printf("%d\n", m[1][100] == 0x3f3f3f3f ? -1 : m[1][100]);
	}
	return 0;
}
