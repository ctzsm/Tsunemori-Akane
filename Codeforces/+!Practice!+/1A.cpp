#include <iostream>

long long n, m, a;
int main() {
	std::cin >> n >> m >> a;
	std::cout << ((n - 1) / a + 1) * ((m - 1) / a + 1) << std::endl;
	return 0;
}