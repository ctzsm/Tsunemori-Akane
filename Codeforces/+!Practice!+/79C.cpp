#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;


string s,match[15];
int n;
int len = 0,pos = 0,l = 0;
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	cin >> s >> n;
	for(int i = 0;i < n; ++i) cin >> match[i];
	for(int i = 1;i <= s.length(); ++i){
		for(int j = 0;j < n; ++j){
			if(i < match[j].length()) continue;
			bool flag = true;
			for(int k = 0;k < match[j].length(); ++k){
				if(s[i - k - 1] != match[j][match[j].length() - k - 1]){
					flag = false;break;
				}
			}
			if(flag){
				l = max(l,(int)(i - match[j].length() + 1));
			}
		}
		if(i - l > len){
			len = i - l;
			pos = l;
		}
	}
	printf("%d %d\n",len,pos);
	return 0;
}
