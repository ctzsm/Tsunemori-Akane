#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, k;
long long a[200005], b[200005];
int m[200005];
int main(void) {
//	freopen("in", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
	long long sum = 0;
	for (int i = 0; i < k - 1; ++i) sum += a[i];
	for (int i = k - 1; i < n; ++i)	{
		sum += a[i];
		b[i - k + 1] = sum;
		sum -= a[i + 1 - k];
	}
//	for (int i = 0; i <= n - k; ++i) printf("%d ", b[i]); printf("\n");
	int id = -1; 
	long long now = 0;
	for (int i = n - k; i >= 0; --i) {
		if (now <= b[i]) {
			now = b[i];
			id = i;
		}
		m[i] = id;
	}
//	for (int i = 0; i <= n - k; ++i) printf("%d ", m[i]); printf("\n");
	int p1 = 0, p2 = 0;
	long long answer = 0;
	for (int i = n - 2 * k; i >= 0; --i) {
		if (answer <= b[i] + b[m[i+k]]) {
			answer = b[i] + b[m[i+k]];
			p1 = i, p2 = m[i+k];
		}
	}
	printf("%d %d\n", p1 + 1, p2 + 1);
	return 0;
}