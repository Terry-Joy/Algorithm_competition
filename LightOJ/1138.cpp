#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=5e8;
int solve(int x)
{
	int sum=0;
	while(x)
	{
		sum+=x/5;
		x/=5;
	}
	return sum;
}
int is_ok(int n)
{
	int l=1,r=maxn+1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(solve(mid)<n)l=mid+1;
		else r=mid;
	}
	if(solve(r)==n)return r;
	else return 0;
}
int main()
{
	int t,a;
	scanf("%d",&t);
	int k=1;
	while(t--)
	{
		scanf("%d",&a);
		 if(is_ok(a)==0)
            printf("Case %d: impossible\n",k++);
        else
            printf("Case %d: %d\n",k++,is_ok(a));
	} 
}
