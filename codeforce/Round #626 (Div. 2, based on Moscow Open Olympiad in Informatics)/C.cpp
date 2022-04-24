#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
const int maxn=1e6+10; 
char c;
int a[maxn],sum[maxn],cnt[maxn];
int main()
{
	int n;  
	scanf("%d",&n);
	char ar[n+1];
	scanf("%s",ar);
	int a=0,b=0,f=0,ans=0;
	for(int i=0;i<n;++i){
		if(ar[i]=='(')
			a++;
		else 
			b++;
		if(b>a)f=1;
		if(a==b&&f){
			ans+=a+b;
			a=0,b=0,f=0;
		}
		else if(a==b){
			a=0,b=0,f=0;
		}
	}
	if(a||b)//假如不全为0
		ans=-1;
		printf("%d\n",ans); 
	return 0;
} 
