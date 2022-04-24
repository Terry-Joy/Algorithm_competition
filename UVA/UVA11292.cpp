#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e4+10;
int a[maxn],b[maxn];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
       for(int i=1;i<=n;++i)
          scanf("%d",&a[i]);
       for(int i=1;i<=m;++i)
          scanf("%d",&b[i]);
       sort(a+1,a+1+n);
       sort(b+1,b+1+m);
       int cnt=1,i,cost=0;
       for(i=1;i<=m;++i)
       {
           if(b[i]>=a[cnt])
           {
              cost+=b[i];
              cnt++;
              if(cnt==n+1)
               {
                  cout<<cost<<"\n";
                  break; 
                }
           }
       } 
       if(cnt<=n)
           puts("Loowater is doomed!");
    }
    return 0;
}
