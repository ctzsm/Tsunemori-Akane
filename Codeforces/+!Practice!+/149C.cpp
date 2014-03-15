#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

struct boy{
	int num,skill;
	bool operator < (const boy& x)const{
		return skill < x.skill;
	}
};
int n,t = 0;
boy a[100005];
vector<int> ans1,ans2;
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) { scanf("%d",&a[i].skill);a[i].num = i + 1;t = max(t,a[i].skill); }
	sort(a,a+n);
	int g1 = 1,g2 = 0,s1 = a[0].skill,s2 = 0;
	ans1.push_back(a[0].num);
	for(int i = 1;i < n; ++i){
		if(abs(g1 + 1 - g2) <= 1 && abs(s1 + a[i].skill - s2) <= t){
			g1++;
			s1 += a[i].skill;
			ans1.push_back(a[i].num);
		}else{
			g2++;
			s2 += a[i].skill;
			ans2.push_back(a[i].num);
		}
	}
	printf("%d\n",ans1.size());
	for(int i = 0;i < ans1.size(); ++i){
		printf("%d%c",ans1[i],i == ans1.size() - 1 ? '\n' : ' ');
	}
	printf("%d\n",ans2.size());
	for(int i = 0;i < ans2.size(); ++i){
		printf("%d%c",ans2[i],i == ans2.size() - 1 ? '\n' : ' ');
	}
	return 0;
}

