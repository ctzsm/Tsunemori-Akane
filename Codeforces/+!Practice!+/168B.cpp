#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[1050000];

int main(int argc, char** argv) {
	freopen("in", "r", stdin);
	int cnt = 0;
	bool need = false;
	bool out;
	while (gets(s)) {
		bool flag = false;
		int len = strlen(s);
		//		printf("len = %d\n",len);
		if (s[len - 1] == '\r' && s[len - 2] == '\n') {
			s[len - 1] = '\0';
			s[len - 2] == '\0';
			len -= 2;
		}
		for (int i = 0; i < len; ++i) {
			if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r') continue;
			if (s[i] == '#') {
				flag = true;
				break;
			} else {
				flag = false;
				break;
			}
		}
		out = flag;
		if (flag) {
			if (need) putchar('\n');
			puts(s);
//			putchar('\n');
			need = false;
		} else {
			for (int i = 0; i < len; ++i) {
				if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r') continue;
				putchar(s[i]);
			}
			need = true;
		}
	}
	if(!out) putchar('\n');
	return 0;
}

