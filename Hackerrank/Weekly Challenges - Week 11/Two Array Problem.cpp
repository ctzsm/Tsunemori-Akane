#include <set>
#include <map>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1000000;
const double eps = 1e-8;

struct pnt {
	double x, y;
	pnt() {}
	pnt(double _x, double _y): x(_x), y(_y) {}
} point[maxn + 10], central;
typedef struct item* pitem;
struct item {
	int prior, value, cnt;
	bool rev;
	pitem l, r;
	item() {}
	item(int _prior, int _value, int _cnt): prior(_prior), value(_value), cnt(_cnt) {
		l = NULL, r = NULL, rev = false;
	}
};
pitem root[2];
int N, M;
double dis(pnt &a, pnt &b) {
	return hypot(a.x - b.x, a.y - b.y);
}
pnt threePoint(pnt &a, pnt &b, pnt &c) {
	double a1 = b.x - a.x, b1 = b.y - a.y;
	double c1 = (a1 * a1 + b1 * b1) / 2.0;
	double a2 = c.x - a.x, b2 = c.y - a.y;
	double c2 = (a2 * a2 + b2 * b2) / 2.0;
	double d = a1 * b2 - a2 * b1;
	return pnt(a.x + (c1 * b2 - c2 * b1) / d, a.y + (a1 * c2 - a2 * c1) / d);
}
int cnt (pitem it) {
	return it ? it->cnt : 0;
}
void upd_cnt (pitem it) {
	if (it)
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
}
void push (pitem it) {
	if (it && it->rev) {
		it->rev = false;
		swap (it->l, it->r);
		if (it->l) it->l->rev ^= true;
		if (it->r) it->r->rev ^= true;
	}
}
void merge (pitem &t, pitem l, pitem r) {
	push (l);
	push (r);
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	upd_cnt (t);
}

void split (pitem t, pitem &l, pitem &r, int k) {
	if (!t)
		return void( l = r = 0 );
	push (t);
	if (k <= cnt(t->l)) {
		r = t;
		split (t->l, l, t->l, k);
		upd_cnt(r);
	} else {
		l = t;
		split (t->r, t->r, r, k - cnt(t->l) - 1);
		upd_cnt(l);
	}
}
void output (pitem t) {
	if (!t)  return;
	push (t);
	output (t->l);
	printf ("%d ", t->value);
	output (t->r);
}
int X[maxn + 10], Y[maxn + 10];
int *W;
int tt = 0;
void getPoint(pitem x) {
	if (!x) return;
	push(x);
	getPoint(x->l);
	W[tt++] = x->value;
	getPoint(x->r);
}
void calc(pitem x, pitem y) {
	tt = 0, W = X;
	getPoint(x);
	tt = 0, W = Y;
	getPoint(y);
	// printf("%d\n", tt);
	for (int i = 0; i < tt; ++i) point[i].x = X[i], point[i].y = Y[i];
	// for (int i = 0; i < tt; ++i) {
	// 	printf("%f %f\n", point[i].x, point[i].y);
	// }
	random_shuffle(point, point + tt);
	pnt central = point[0];
	double R = 0.0;
	for (int i = 1; i < tt; ++i) {
		if (dis(central, point[i]) > R) {
			central = point[i], R = 0.0;
			for (int j = 0; j < i; ++j)
				if (dis(central, point[j]) > R) {
					central.x = (point[i].x + point[j].x) / 2.0;
					central.y = (point[i].y + point[j].y) / 2.0;
					R = dis(central, point[j]);
					for (int k = 0; k < j; ++k)
						if (dis(central, point[k]) > R) {
							central = threePoint(point[i], point[j], point[k]);
							R = dis(central, point[k]);
						}
				}
		}
	}
	printf("%.2f\n", R);
}
int main() {
	freopen("in", "r", stdin);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine g(seed);
	scanf("%d%d", &N, &M);
	for (int j = 0; j < 2; ++j)
		for (int i = 0; i < N; ++i) {
			int x; scanf("%d", &x);
			pitem p = new item(g(), x, 1);
			merge(root[j], root[j], p);
		}
	while (M--) {
		int t, id, l1, r1, l2, r2; scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d%d", &id, &l1, &r1);
			pitem t1, t2, t3;
			split (root[id], t2, t3, r1);
			split (t2, t1, t2, l1 - 1);
			t2->rev ^= true;
			merge (t1, t1, t2);
			merge (root[id], t1, t3);
		}
		if (t == 2) {
			scanf("%d%d%d%d%d", &id, &l1, &r1, &l2, &r2);
			pitem t1, t2, t3, t4, t5;
			split(root[id], t4, t5, r2);
			split(t4, t3, t4, l2 - 1);
			split(t3, t2, t3, r1);
			split(t2, t1, t2, l1 - 1);
			merge(root[id], t1, t4);
			merge(root[id], root[id], t3);
			merge(root[id], root[id], t2);
			merge(root[id], root[id], t5);
		}
		if (t >= 3) {
			scanf("%d%d", &l1, &r1);
			pitem t1, t2, t3, t4, t5, t6;
			split(root[0], t2, t3, r1);
			split(t2, t1, t2, l1 - 1);
			split(root[1], t5, t6, r1);
			split(t5, t4, t5, l1 - 1);
			if (t == 3) {
				merge(root[0], t1, t5);
				merge(root[0], root[0], t3);
				merge(root[1], t4, t2);
				merge(root[1], root[1], t6);
			} else {
				calc(t2, t5);
				merge(root[0], t1, t2);
				merge(root[0], root[0], t3);
				merge(root[1], t4, t5);
				merge(root[1], root[1], t6);
			}
		}
	}
	return 0;
}