#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#define ll long long

using namespace std;
const int maxn=1e6+10;
int n,x,l[maxn],r[maxn],l1[maxn],r1[maxn],a[maxn];
//[i,n]最前面的pos [1,i]最后的位置
int main()
{ 
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    memset(l,0x3f,sizeof(l));
    for(int i=1;i<=n;++i)
    {
       l[a[i]]=min(i,l[a[i]]);
       r[a[i]]=i; 
    }
    memset(l1,0x3f,sizeof(l1));
    for(int i=x;i>=1;--i)
        l1[i]=min(l1[i+1],l[i]);
    for(int i=1;i<=x;++i)
        r1[i]=max(r1[i-1],r[i]);
    int m=x;
    //[m,x]非递减
    for(;m>1&&r[m]<=l1[m+1];--m);//找最小的x1

    ll ans=x-m+1;
    //[1,i-1],[m+1,x]满足
    for(int i=2;i<=x&&r1[i-2]<=l[i-1];++i)
    {
       for(;m<i||r1[i-1]>l1[m+1];++m);//第一个m
       ans+=x-m+1; 
    }
    printf("%lld\n",ans);
    return 0;
}
