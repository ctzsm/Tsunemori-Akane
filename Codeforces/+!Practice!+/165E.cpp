#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int up = 1 << 22;
int n,a[1000005];
int c[4440000];
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) scanf("%d",&a[i]);
	for(int i = 0;i < n; ++i) c[a[i]] = a[i];
	for(int i = 0;i < up; ++i){
		if(c[i] == 0){
			for(int j = 0;j < 22; ++j){
				if(i & (1 << j)){
					if(c[i - (1 << j)] > 0){
						c[i] = c[i - (1 << j)];
						break;
					}
				}
			}
		}
	}
	
	for(int i = 0;i < n; ++i){
		int x = c[up - 1 - a[i]];
		if(x == 0) x = -1;
		printf("%d%c",x,i == n - 1 ? '\n' : ' ');
	}
	return 0;
}

