#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1e6+10;
char s[maxn];
unsigned long long f[maxn],p[maxn];//P������mod M,unsigned long long �൱���Զ� mod 2^64; 
int main() //f[i]��ʾǰ׺s[1...i]��hashֵ�� 
{
	scanf("%s",s);
	p[0]=1;//131^0 
	int n,l1,r1,l2,r2;
	scanf("%d",&n);
	int k=strlen(s);
	for(int i=0;i<k;++i)
	{
		f[i]=f[i-1]*131+(s[i]-'a'+1); //����ǰ׺ 
		p[i+1]=p[i]*131;
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(f[r1-1]-f[l1-2]*p[r1-l1+1]==f[r2-1]-f[l2-2]*p[r2-l2+1])
			puts("Yes");
		else
		 	puts("No");
	}
	return 0;
} 
