#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=100005;
int a[maxn],b[maxn],c[maxn],n;
void add(int x,int y)
{
	for(;x<=n;x+=x&-x)c[x]+=y;
}
int count(int x)
{
	int ans=0;
	for(;x;x-=x&-x)ans+=c[x];
	return ans;
}
int ask(int x)
{
	int l = 1, r = n;
    int p;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (count(mid) >= x)
        {
            p = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return p;
}
int main()
{
	scanf("%d",&n);
	add(1,1);
	for(int i=2;i<=n;++i)
	{
		scanf("%d",&a[i]);
		add(i,1);
	}
	for(int i=n;i>=1;--i)
	{
		b[i]=ask(a[i]+1);
		add(b[i],-1);
	}
	for(int i=1;i<=n;++i)
		printf("%d\n",b[i]);
	return 0;
} 
