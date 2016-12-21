#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[105];
int main() {
	// freopen("in", "r", stdin);
	scanf("%s", s);
	int n = strlen(s), m = 0;
	for (int i = 0; i < n; ++i) {
		if (islower(s[i]))
			m ++;
	}
	for (int i = 0; i < n; ++i)
		if (m >= n - m)
			s[i] = tolower(s[i]);
		else
			s[i] = toupper(s[i]);
	printf("%s\n", s);
	return 0;
}
