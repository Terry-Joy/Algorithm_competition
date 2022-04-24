#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int k[4];
int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	while(t--) 
	{
		int temp=0;
		scanf("%d%d%d",&a,&b,&c); 
		if(a>0){a--;temp++;}
		if(b>0){b--;temp++;}
		if(c>0){c--;temp++;}
		k[1]=a,k[2]=b,k[3]=c;
		sort(k+1,k+4);
		if(k[2]>0&&k[3]>0){k[2]--,k[3]--,temp++;}
		if(k[1]>0&&k[3]>0){k[1]--,k[3]--,temp++;}
		if(k[1]>0&&k[2]>0){k[1]--,k[2]--,temp++;}
		if(k[1]>0&&k[2]>0&&k[3]>0){k[1]--,k[2]--,k[3]--;temp++;}
		printf("%d\n",temp);
	}
	return 0;
} 
