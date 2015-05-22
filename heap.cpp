#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
class heap {
private:
	std::vector<T> a;
	void heapify (int idx) {
		while (idx > 1) {
			if (a[idx >> 1] < a[idx])
				std::swap(a[idx >> 1], a[idx]);
			else break;
			idx >>= 1;
		}
	}
	void down(int idx) {
		while (idx < a.size()) {
			int l = idx << 1, r = idx << 1 | 1, c = 0;
			if (r < a.size()) {
				c = a[r] > a[l] ? r : l;
			} else if (l < a.size()) {
				c = l;
			}
			if (c && a[idx] < a[c]) {
				std::swap(a[c], a[idx]);
				idx = c;
			} else break;
		}
	}
	void debug() {
		for (int i = 1; i < (int)a.size() - 1; ++i)
			std::cout << a[i] << " ";
		std::cout << a[a.size() - 1] << std::endl;
	}
public:
	heap(std::vector<T> _a):a(_a) {
		a.insert(a.begin(), T(0)); // shift right
		for (int i = a.size() / 2; i > 0; --i) {
			down(i);
		}
	}
	void push(T x) {
		a.push_back(x);
		heapify(a.size() - 1);		
	}
	T pop() {
		if (empty()) {
			std::cout << "empty heap" << std::endl;
			exit(1);
		}
		int idx = a.size() - 1;
		std::swap(a[1], a[idx]);
		int x = a[idx];
		a.pop_back();
		down(1);
		return x;
	}
	bool empty() {
		if (a.size() <= 1) return true;
		return false;
	}
};
int main() {
	srand(time(NULL));
	std::vector<int> a, b;
	for (int i = 0; i < 100000; ++i) 
		a.push_back(rand());
	heap<int> h(a);
	for (int i = 0; i < 100000; ++i)
		h.push(rand());
	while (!h.empty())
		b.push_back(h.pop());
	std::reverse(b.begin(), b.end());
	std::cout << is_sorted(b.begin(), b.end()) << std::endl;
	return 0;
}
