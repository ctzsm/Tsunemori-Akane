#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
struct basket {
	int num, idx;
	basket(int _num, int _idx):num(_num),idx(_idx){}
	bool operator < (const basket &x) const {
		double r1 = fabs((m + 1) / 2.0 - idx);
		double r2 = fabs((m + 1) / 2.0 - x.idx);
		if (num == x.num && r1 == r2) return idx > x.idx;
		if (num == x.num) return r1 > r2;
		return num > x.num; 
	}
};
priority_queue<basket> q;
int main(void) {
//	freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
		q.push(basket(0, i + 1));
	for (int i = 1; i <= n; ++i) {
		basket now = q.top(); q.pop();
		printf("%d\n", now.idx);
		q.push(basket(now.num + 1, now.idx));
	}
	return 0;
}
