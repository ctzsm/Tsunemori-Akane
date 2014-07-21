#include<cstdio>
#include<algorithm>
using namespace std;

#define maxn 100010
struct orzhzw {
	int key, id;
	bool operator<(const orzhzw &a) const {
		if (a.key != key) return key < a.key;
		return id < a.id;
	}
} w[maxn];
int n, l;
struct Node {
	int left, right, fa;
	int num, s;
	bool b;
} node[maxn];

struct SPLAY {
	int root;
	SPLAY() {
		root = -1;
	}
	void maintain(int x) {
		node[x].s = 1;
		node[x].s += node[node[x].left].s;
		node[x].s += node[node[x].right].s;
	}
	void push_down(int x) {
		if (node[x].b) {
			if (node[x].left != 0) node[node[x].left ].b ^= 1;
			if (node[x].right != 0) node[node[x].right].b ^= 1;
			swap(node[x].left, node[x].right);
			node[x].b = false;
		}
	}
	int newnode(int x) {
		l++;
		node[l].num = x;
		node[l].s = 1;
		node[l].b = false;
		node[l].left = -1;
		node[l].right = -1;
		return l;
	}
	void left_rotate(int x) {
		int y = node[x].fa;
		if (node[y].fa != -1) {
			if (node[node[y].fa].left == y) node[node[y].fa].left = x;
			if (node[node[y].fa].right == y) node[node[y].fa].right = x;
		}
		node[x].fa = node[y].fa;
		node[y].right = node[x].left;
		if (node[x].left != -1)
			node[node[x].left].fa = y;
		node[x].left = y;
		node[y].fa = x;
		maintain(y);
		maintain(x);
	}
	void right_rotate(int x) {
		int y = node[x].fa;
		if (node[y].fa != -1) {
			if (node[node[y].fa].left == y) node[node[y].fa].left = x;
			if (node[node[y].fa].right == y) node[node[y].fa].right = x;
		}
		node[x].fa = node[y].fa;
		node[y].left = node[x].right;
		if (node[x].right != -1)
			node[node[x].right].fa = y;
		node[x].right = y;
		node[y].fa = x;
		maintain(y);
		maintain(x);
	}
	void splay(int x, int s) {
		int father = node[s].fa;
		while (node[x].fa != father) {
			int p = node[x].fa;
			if (node[p].fa == father) {
				push_down(p);
				push_down(x);
				if (x == node[p].left) right_rotate(x);
				else left_rotate(x);
				break;
			}
			push_down(node[p].fa);
			push_down(p);
			push_down(x);
			if (x == node[p].left) {
				if (p == node[node[p].fa].left) {
					right_rotate(p);
					right_rotate(x);
				} else {
					right_rotate(x);
					left_rotate(x);
				}
			} else {
				if (p == node[node[p].fa].right) {
					left_rotate(p);
					left_rotate(x);
				} else {
					left_rotate(x);
					right_rotate(x);
				}
			}
		}
		if (father == -1) root = x;
	}
	void insert(int x) {
		int tmp = root;
		if (tmp == -1) {
			int q = newnode(x);
			root = q;
			node[q].fa = -1;
			return;
		}
		while (node[tmp].right != -1) tmp = node[tmp].right;
		int q = newnode(x);
		node[tmp].right = q;
		node[q].fa = tmp;
		splay(q, root);
	}
	int find(int x) {
		int tmp = root, ans = x;
		while (tmp != -1) {
			push_down(tmp);
			int q;
			if (node[tmp].left != -1) q = node[node[tmp].left].s; else q = 0;
			if (q > ans - 1) tmp = node[tmp].left; else if (q == ans - 1)   return tmp; else {
				ans -= q + 1;
				tmp = node[tmp].right;
			}
		}
		return 0;
	}
	void reverse(int l, int r) {
		int tmp = find(l);
		splay(tmp, root);
		tmp = find(r + 2);
		splay(tmp, node[root].right);
		node[node[node[root].right].left].b = node[node[node[root].right].left].b ^ 1;
	}
	int rank(int x) {
		splay(x, root);
		return node[root].left ? node[node[root].left].s : 0;
	}
} splay;

int main() {
	freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		w[i].key = i, w[i].id = i;
	splay.insert(0);
	for (int i = 1; i <= n; i++)
		splay.insert(i);
	splay.insert(n + 1);
	// sort(w + 1, w + n + 1);
	int q; scanf("%d", &q);
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int a, b; scanf("%d%d", &a, &b);
			splay.reverse(a, b);
		} else if (t == 2) {
			int a; scanf("%d", &a);
			printf("element %d is at position %d\n", a, splay.rank(a + 1));
		} else {
			int a; scanf("%d", &a);
			printf("element at position %d is %d\n", a, w[splay.find(a + 1) - 1].key);
		}
	}
	return 0;
	for (int i = 1; i <= n; i++) {
		int tmp = splay.rank(w[i].id + 1);
		printf("%d ", tmp);
		splay.reverse(i, tmp);
	}
	
	return 0;
}