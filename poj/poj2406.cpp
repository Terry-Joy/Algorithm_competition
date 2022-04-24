#include<cstdio>
#include<cstring> 
#include<iostream>
const int maxn=1e6+10;
using namespace std;
int next[maxn],len;
char s[maxn];
void KMP(int len)
{
	next[0]=-1;
	int i=0,j=-1;
	while(i<n)
	{
		if(j==-1||s[i]==s[j]) next[++i]=++j;
		else j=next[j];
	}
}
int main()
{
	while(scanf("%s",s)!=EOF)
	{
		if(s[0]=='.')
			break;
		int ans=0;
		len=strlen(s);
		KMP(len);
		if(len%(len-next[len])==0)
			ans=len/(len-next[len]);
		printf("%d\n",ans);
	}
	return 0;
}
 
