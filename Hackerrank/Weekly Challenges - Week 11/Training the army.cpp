#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

const int M = 300;
const int inf = 100000000;

int N, T;
int m[M][M];
int A[51], B[51];
struct CNode{
	int v, i;
	CNode(int v, int i){
		this->v = v, this->i = i;
	}
};
std::vector<CNode> a[M];
std::vector<int> flow;
std::vector<int> cap;
int cur[M], sumd[M], d[M], pre[M];

void AddEdge(int u, int v, int c) {
	a[u].push_back(CNode(v, cap.size()));
	a[v].push_back(CNode(-u, cap.size()));
	cap.push_back(c);
	flow.push_back(0);
}

int SAP(int s, int t, int n) {
	memset(sumd, 0, sizeof(sumd));
	memset(cur, 0, sizeof(cur));
	memset(d, 0, sizeof(d));
	sumd[0] = n;
	pre[s] = s;
	int ans = 0;
	int now = s;
	int modify = inf;
	while (d[s] < n) {
		bool flag = false;
		if (now == s)
			modify = inf;
		for (int &j = cur[now]; j < a[now].size(); ++j) {
			int i = a[now][j].i;
			int v = a[now][j].v;
			if (v > 0 && d[now] == d[v] + 1 && flow[i] < cap[i]) {
				flag = true;
				pre[v] = now;
				now = v;
				modify = std::min(modify, cap[i] - flow[i]);
				break;
			}
			if (v < 0 && d[now] == d[-v] + 1 && flow[i] > 0) {
				flag = true;
				pre[-v] = now;
				now = -v;
				modify = std::min(modify, flow[i]);
				break;
			}
		}
		if (now == t) {
			ans += modify;
			while (now != s) {
				now = pre[now];
				if (a[now][cur[now]].v > 0)
					flow[a[now][cur[now]].i] += modify;
				else
					flow[a[now][cur[now]].i] -= modify;
			}
		}
		if (flag)
			continue;
		cur[now] = 0;
		int mind = n;
		for (int tt = 0; tt < a[now].size(); ++tt) {
			int i = a[now][tt].i;
			int v = a[now][tt].v;
			if (v > 0 && d[v] < mind && flow[i] < cap[i])
				mind = d[v];
			if (v < 0 && d[-v] < mind && flow[i] > 0)
				mind = d[-v];
		}
		sumd[d[now]]--;
		if (sumd[d[now]] == 0)
			d[s] = n;
		sumd[d[now] = mind + 1]++;
		now = pre[now];
	}
	return ans;
}

int main() {
	freopen("in", "r", stdin);
	scanf("%d%d", &N, &T);
	for (int i = 1; i <= N; ++i) {
		int x; scanf("%d", &x);
		m[0][i] += x;
		m[i][N + T + 1] ++;
	}
	N ++;
	for (int i = 0; i < T; ++i) {
		int a, b;
		scanf("%d", &a);
		for (int j = 0; j < a; ++j) {
			scanf("%d", &A[j]);
			m[A[j]][i + N] ++;
		}
		scanf("%d", &b);
		for (int j = 0; j < b; ++j) {
			scanf("%d", &B[j]);
			m[i + N][B[j]] ++;
		}
	}
	N += T;
	for (int i = 0; i < N + 1; ++i) {
		for (int j = 0; j < N + 1; ++j) {
			if (m[i][j])
				AddEdge(i, j, m[i][j]);
			// printf("%d ", m[i][j]);
		}
		// printf("\n");
	}
	printf("%d\n", SAP(0, N, N + 1));
	return 0;
}