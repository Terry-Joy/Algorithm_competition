#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int INF=1e5+10;
int w[30];LL sum[INF];
map<LL,int>mmap[30];
char s[INF];
int main() 
{
	for(int i=0;i<26;++i)
		cin>>w[i];
	LL ans=0;
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;++i)
		sum[i]=sum[i-1]+w[s[i]-'a'];
	for(int i=1;i<=len;++i)
	{
		int idx=s[i]-'a';
		if(mmap[idx].count(sum[i-1]))
			ans+=mmap[idx][sum[i-1]];
			mmap[idx][sum[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
} 
