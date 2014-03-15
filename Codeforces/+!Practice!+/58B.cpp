#include <cstdio>
#include <cstdlib>

using namespace std;

int n,cnt = 1;
int ans[50];
int main(int argc, char** argv) {
	scanf("%d",&n);
	ans[0] = n;
	for(int i = n - 1;i >= 1; --i){
		bool flag = true;
		for(int j = 0;j < cnt; ++j){
			if(ans[j] % i != 0){ flag = false;break; }
		}
		if(flag) ans[cnt++] = i;
	}
	for(int i = 0;i < cnt; ++i) printf("%d ",ans[i]);
	return 0;
}

