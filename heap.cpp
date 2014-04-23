#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
class heap {
private:
	std::vector<T> a;
	size_t parent(int idx) {
		return (idx >> 1);
	}
	size_t left(int idx) {
		return (idx << 1);
	}
	size_t right(int idx) {
		return (idx << 1) + 1;
	}
	void heapify (int idx) {
		while (idx > 1) {
			if (a[parent(idx)] < a[idx])
				std::swap(a[parent(idx)], a[idx]);
			else break;
			idx = parent(idx);
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
		for (int i = a.size() - 1; i > a.size() / 2; --i) {
			heapify(i);
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
		std::swap(a[idx], a[1]);
		T x = a[idx];
		a.pop_back();
		if (empty()) {
			return x;
		}
		idx = 1;
		while (idx < a.size()) {
			int id = idx;
			T now = a[idx];
			if (left(idx) < a.size() && now < a[left(idx)]) {
				now = a[left(idx)];
				id = left(idx);
			}
			if (right(idx) < a.size() && now < a[right(idx)]) {
				now = a[right(idx)];
				id = right(idx);
			}
			if (id == idx) break;
			else {
				std::swap(a[idx], a[id]);
				idx = id;
			}
		}
		return x;
	}
	bool empty() {
		if (a.size() <= 1) return true;
		return false;
	}
};
int main() {
	std::vector<int> a;
	a.push_back(5);
	a.push_back(8);
	a.push_back(-1);
	a.push_back(9);
	a.push_back(20);
	a.push_back(40);
	heap<int> h(a);
	h.push(30);
	h.push(-10);
	while (!h.empty()) {
		std::cout << h.pop() << std::endl;
	}
	return 0;
}