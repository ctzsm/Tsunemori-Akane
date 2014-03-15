#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int k, ans = 0;
char s[100005];
char p[15][5];

int main(int argc, char** argv) {
	scanf("%s%d", s, &k);
	for (int i = 0; i < k; ++i) scanf("%s", p[i]);
	int len = strlen(s);
	for (int j = 0; j < k; ++j) {
		int cnt1 = 0,cnt2 = 0;
		for (int i = 0; i < len; ++i) {
			if(s[i] == p[j][0]){
				cnt1++;
			}else if(s[i] == p[j][1]){
				cnt2++;
			}else{
				ans += min(cnt1,cnt2);
				cnt1 = cnt2 = 0;
			}
		}
		ans += min(cnt1,cnt2);
	}
	printf("%d\n",ans);
	return 0;
}

