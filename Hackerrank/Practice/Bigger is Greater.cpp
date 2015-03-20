#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int T;
int main() {
	cin >> T;
	while (T--) {
		string s; cin >> s;
		if (next_permutation(s.begin(), s.end())) 
			cout << s << endl;
		else
			cout << "no answer" << endl;
	}
	return 0;
}
