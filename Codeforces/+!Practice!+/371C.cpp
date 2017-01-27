#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[105];
int n[3], p[3], c[3];
long long m;
bool check(long long x) {
	long long need = 0;
	for (int i = 0; i < 3; ++i) {
		need += max(x * c[i] - n[i], 0ll) * p[i];
	}
	return need <= m;
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%s", s);
	for (int i = 0; i < 3; ++i) scanf("%d", n + i);
	for (int i = 0; i < 3; ++i) scanf("%d", p + i);
	scanf("%lld", &m);
	int ln = strlen(s);
	for (int i = 0; i < ln; ++i) {
		switch (s[i]) {
			case 'B' : c[0] ++; break;
			case 'S' : c[1] ++; break;
			case 'C' : c[2] ++; break;
		}
	}
	long long l = 0, h = m + n[0] + n[1] + n[2];
	while (l < h) {
		long long mid = (l + h) >> 1;
		if (check(mid)) {
			l = mid + 1;
		} else {
			h = mid;
		}
	}
	printf("%lld\n", l - 1);
	return 0;
}
