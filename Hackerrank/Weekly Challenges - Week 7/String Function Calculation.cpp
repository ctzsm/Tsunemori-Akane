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

using namespace std;

#define SIZE 26       /* The size of alphabet  */
#define MAXS 1000010  /* The size of node pool */
#define UNDEF -1      /* magic number for undefined */

struct node {
	int child[SIZE];
	int parent;
	pair<int, int> edge[SIZE];
	int suffixLink;
	int accept;
	int start;

	node() : suffixLink(UNDEF), accept(UNDEF) {
		memset(child, UNDEF, sizeof child);
	}

	void init() {
		suffixLink = accept = parent = start = UNDEF;
		memset(child, UNDEF, sizeof child);
	}

	/* add edge from current node to node c with label (j, l). */
	void addEdge(int id, int c, int j, int l) {
		child[id] = c;
		edge[id] = make_pair(j, l);
	}

	/* delete edge from current node to node c. */
	void delEdge(int id, int c) {
		child[id] = UNDEF;
	}
} pool[MAXS];

class SuffixTree {
private:
	int root;
	int nodeCnt;
	int n;
	string y;

	/* counters */
	// int fast_count;
	// int slow_count;

	int target(int p, char x) {
		return pool[p].child[x - 'a'];
	}

	pair<int, int> label(int f, int c) {
		if (pool[f].child[pool[c].start] == UNDEF)
			return make_pair(UNDEF, UNDEF);
		else
			return pool[f].edge[pool[c].start];
	}

	int fastFind(int r, int j, int k) {
		// fast_count ++;
		if (j >= k) return r;
		else {
			int q = target(r, y[j]);
			pair<int, int> x = label(r, q);
			int jj = x.first, l = x.second;
			if (j + l <= k) return fastFind(q, j + l, k);
			else {
				pool[r].delEdge(pool[q].start, q);

				int p = nodeCnt++;
				pool[p].init();
				pool[p].start = y[jj] - 'a';
				pool[p].parent = r;

				pool[r].addEdge(pool[p].start, p, jj, k - j);

				pool[q].start = y[jj + k - j] - 'a';
				pool[p].addEdge(pool[q].start, q, jj + k - j, l - k + j);
				pool[q].parent = p;
				return p;
			}
		}
	}

	pair<int, int> slowFind(int p, int k) {
		// slow_count ++;
		while (k < n && target(p, y[k]) != UNDEF) {
			int q = target(p, y[k]);
			pair<int, int> x = label(p, q);
			int j = x.first, l = x.second;
			int i = j;
			do {
				i++; k++;
			} while (i < j + l && k < n && y[i] == y[k]);

			if (i < j + l) {
				pool[p].delEdge(pool[q].start, q);

				int r = nodeCnt++;
				pool[r].init();
				pool[r].start = y[j] - 'a';
				pool[r].parent = p;

				pool[p].addEdge(pool[r].start, r, j, i - j);

				pool[q].start = y[i] - 'a';
				pool[r].addEdge(pool[q].start, q, i, l - i + j);
				pool[q].parent = r;
				return make_pair(r, k);
			}
			p = q;
		}
		return make_pair(p, k);
	}

public:
	long long ans;
	SuffixTree(string _y) {

		ans = 0;

		n = _y.size();
		y = _y;

		nodeCnt = 0;
		root = nodeCnt++;
		pool[root].init();
		pool[root].suffixLink = root;
		// cout << "root = " << root << endl;
		int fork = root, k = 0;
		for (int i = 0; i < n; ++i) {
			k = max(k, i);

			/* The suffix link of fork is not defined*/
			// cout << "fork = " << fork << endl;
			if (pool[fork].suffixLink == UNDEF) {
				int t = pool[fork].parent;
				pair<int, int> x = label(t, fork);
				int j = x.first, l = x.second;
				if (t == root)
					l -= 1;
				pool[fork].suffixLink = fastFind(pool[t].suffixLink, k - l, k);
			}

			pair<int, int> x = slowFind(pool[fork].suffixLink, k);
			fork = x.first, k = x.second;

			int q;
			if (k < n) {
				q = nodeCnt++;
				pool[q].init();
				pool[q].start = y[k] - 'a';
				pool[q].parent = fork;
				pool[fork].addEdge(pool[q].start, q, k, n - k);
			} else
				q = fork;
			pool[q].accept = i;
		}
		pool[root].accept = 0;
		// cout << "invoke fastFind " << fast_count << " times." << endl;
		// cout << "invoke slowFind " << slow_count << " times." << endl;
		// cout << nodeCnt << " node in total." << endl;
		// cout << pool[nodeCnt - 1].start << endl;
	}

	int dfs(int r, int len = 0) {
		int ret = 0;
		for (int i = 0; i < SIZE; ++i) {
			if (pool[r].child[i] == UNDEF) continue;
			ret += dfs(pool[r].child[i], pool[r].edge[i].second + len);
		}
		ret += pool[r].accept >= 0;
		ans = max(ans, 1LL * ret * len);
		return ret;
	}
};
string s;
int main() {
	freopen("in", "r", stdin);
	cin >> s;
	SuffixTree st(s);
	st.dfs(0);
	cout << st.ans << endl;
	// cout << st.calc() << endl;
	return 0;
}