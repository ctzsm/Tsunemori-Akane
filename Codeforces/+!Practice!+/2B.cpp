#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int n;
int a[2][1005][1005],dp[2][1005][1005];
bool dir[2][1005][1005];
bool zero = false;
int zeroi, zeroj;

int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			int x;scanf("%d", &x);
			if (x == 0) {
				a[0][i][j] = a[1][i][j] = 1;
				zero = true,zeroi = i,zeroj = j;
			} else {
				while (x % 2 == 0) a[0][i][j]++, x /= 2;
				while (x % 5 == 0) a[1][i][j]++, x /= 5;
			}
		}
	for (int t = 0; t < 2; ++t) {
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			int rec = 0x7fffffff;
			if(i == 0 && j == 0) rec = 0;
			if(i != 0 && dp[t][i-1][j] < rec) rec = dp[t][i-1][j];
			if(j != 0 && dp[t][i][j-1] < rec) { rec = dp[t][i][j-1];dir[t][i][j] = true; }
			dp[t][i][j] = rec + a[t][i][j];
		}
	}
	int t = 0;
	if(dp[0][n-1][n-1] > dp[1][n-1][n-1])  t = 1;
	if(dp[t][n-1][n-1] > 1 && zero){
		string s;
		for(int i = 0;i < zeroj; ++i) s += 'R';
		for(int i = 0;i < zeroi; ++i) s += 'D';
		for(int i = 0;i < n - 1 - zeroi; ++i) s += 'D';
		for(int i = 0;i < n - 1 - zeroj; ++i) s += 'R';
		cout << 1 << endl << s << endl;
	}else{
		int i = n - 1,j = n - 1;
		string s;
		while(i > 0 || j > 0){
			if(dir[t][i][j]){
				j--; s += 'R';
			}else{
				i--; s += 'D';
			}
		}
		reverse(s.begin(),s.end());
		cout << dp[t][n-1][n-1] << endl << s << endl;
	}
	return 0;
}

