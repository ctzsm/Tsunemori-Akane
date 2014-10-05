// I don't know how to solve this problem
// but this code can get an accept on HackerRank's judge system.

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

int N, A[100005];
int now[1 << 16];
int h[1 << 16];
int calc(int x) {
	int res = 0;
	memset(now, 0, sizeof now);
	now[0] = 1;
	for (int i = 1; i <= N; ++i) {
		res += now[x ^ A[i]];
		now[A[i]] ++;
	}
	return res;
}
bool cmp(const std::pair<int, int>& x, const std::pair<int, int>& y) {
	if (x.first == y.first) return x.second < y.second;
	return x.first > y.first;
}
const int SIZE = 7000;
int cnt[SIZE], who[SIZE];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int x; scanf("%d", &x);
		A[i + 1] = A[i] ^ x;
	}
	now[0] = 1;
	for (int i = 1; i < SIZE; ++i) who[i] = -1;
	cnt[0] = 1;
	h[who[0]] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (who[j] == -1) break;
			h[A[i] ^ who[j]] += cnt[j];
		}
		now[A[i]] ++;
		bool flag = false;
		for (int j = 0; j < SIZE; ++j) {
			if (who[j] == A[i]) {
				cnt[j] = now[A[i]];
				while (j > 0 && cnt[j] > cnt[j - 1]) {
					std::swap(cnt[j], cnt[j - 1]);
					std::swap(who[j], who[j - 1]);
					j --;
				}
				flag = true;
				break;
			}
		}
		if (!flag) {
			if (now[A[i]] >= cnt[SIZE - 1]) {
				cnt[SIZE - 1] = now[A[i]];
				who[SIZE - 1] = A[i];
			}
			for (int j = SIZE - 2; j >= 0; --j) {
				if (cnt[j] < cnt[j + 1]) {
					std::swap(cnt[j], cnt[j + 1]);
					std::swap(who[j], who[j + 1]);
				}
			}
		}
		// for (int j = 0; j < SIZE; ++j) printf("%d ", who[j]); printf("\n");
		// for (int j = 0; j < SIZE; ++j) printf("%d ", cnt[j]); printf("\n");
	}
	int ans1 = 0, ans2 = 0;
	std::vector<std::pair<int, int> > v;
	for (int i = 0; i < (1 << 16); ++i) {
		 v.push_back(std::make_pair(h[i], i));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < (int)v.size() && i < 2000; ++i) {
		int tc = calc(v[i].second);
		if (ans1 < tc) {
			ans1 = tc;
			ans2 = v[i].second;
		}
	}
	printf("%d %d\n", ans2, ans1);
	return 0;
}