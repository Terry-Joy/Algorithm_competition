//单调队列求连续区间中最大最小值差在[M,K]之间的最长区间长度
#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=1e5+10;
int a[maxn],h1,t1,h2,t2,now,qmax[maxn],qmin[maxn];
int n,m,k;

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
       for(int i=1;i<=n;++i)
          scanf("%d",&a[i]);
       h1=1,t1=0,h2=1,t2=0,now=0;
       int ans=0;
       for(int i=1;i<=n;++i)
       {
          while(h1<=t1&&a[i]>=a[qmax[t1]])                //单调下降最大值
              t1--;
          while(h2<=t2&&a[i]<=a[qmin[t2]])                //单调上涨最小值
              t2--;
          qmax[++t1]=qmin[++t2]=i;
          while(a[qmax[h1]]-a[qmin[h2]]>k)  //假如小于，通过右移两个队列中的最小下标改变
          {
              if(qmax[h1]<qmin[h2])
                  now=qmax[h1++];
              else
                  now=qmin[h2++];
          }
          if(a[qmax[h1]]-a[qmin[h2]]>=m)    //[now+1,i]
              ans=max(ans,i-now);
       } 
       printf("%d\n",ans);
    }
    return 0;
}
