#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int t,n,k,wm,mw,qq,cnt[maxn];
char s[maxn];
int main()
{
	scanf("%d",&t);
	while (t--){
		wm=mw=qq=0;
		int zz=0,zx=0,xe=0;
		bool ff=1;
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		for (int i=0;i<k;i++) 
			cnt[i]=-1;
		for (int i=1;i<=k;i++){
			int m=i%k;
			if (s[i]=='?') qq++;
			if (s[i]=='0') wm++,cnt[m]=0;
			if (s[i]=='1') mw++,cnt[m]=1;
		}
		if (abs(mw-wm)>qq)	{
			puts("NO");
			continue;
		}
		for (int i=1;i<=k;i++){
			for (int j=k+i;j<=n;j+=k){
				int f=j%k;
				if (s[j]=='?') continue;
				if (cnt[f]==-1) {
					cnt[f]=s[j]-'0';
					continue;
				}
				if (cnt[f]!=s[j]-'0') {
					ff=0;
					break;
				}
			}
			if (ff==0) break;
		}
		for (int i=0;i<k;i++){
			if (cnt[i]==1) zx++;if (cnt[i]==-1) xe++;if (cnt[i]==0) zz++;
		}
		if (abs(zx-zz)>xe) 
			ff=0;
		if(ff)puts("YES");
			else puts("NO");
	}
	return 0;
}

