#include <bits/stdc++.h>
using namespace std;
int n,k,sum=0;
int a[500000],cha[500000];
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        if(i>=2) cha[i-1]=a[i]-a[i-1];
    }
    //for(int i=1;i<n;++i) printf("%d\n",cha[i]);
    sum=a[n]-a[1];
    sort(cha+1,cha+n,cmp);                          //从大到小排序
    //for(int i=1;i<n;++i) printf("%d\n",cha[i]);
    for(int i=1;i<=k-1;++i) sum-=cha[i];
    printf("%d\n",sum);
    return 0;
}