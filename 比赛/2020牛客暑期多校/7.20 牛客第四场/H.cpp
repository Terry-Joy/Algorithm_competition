#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int prime[maxn/20],cnt=0,ans1[maxn/2],ans2[maxn/2],sum[maxn/2];
bool v[maxn/2],v1[maxn];

void init(int maxm){ 
    v[1]=1;
    for(int i=2;i<=maxm;++i){ 
        if(!v[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<=maxm;++j){ 
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main()
{
   init(100000);
   int t,n;
   scanf("%d",&t);
   while(t--){ 
       scanf("%d",&n);
       for(int i=1;i<=n;++i)
           v1[i]=0;
       int k=n/2,m=0;
       int f=upper_bound(prime+1,prime+1+min(cnt,k),k)-prime-1;
       for(int i=f;i>=1;--i){ 
            int num=0;
            sum[++num]=prime[i];
            for(int j=2;prime[i]*j<=n;++j){ 
                int h=prime[i]*j;
                if(!v1[h])
                    sum[++num]=h;
            }
            if(num&1){ 
                ans1[++m]=sum[1];ans2[m]=sum[3];
                v1[sum[1]]=1;v1[sum[3]]=1;
                for(int i=4;i<=num;i+=2)
                    ans1[++m]=sum[i],ans2[m]=sum[i+1],v1[sum[i]]=1,v1[sum[i+1]]=1;
            }
            else{ 
                for(int i=1;i<=num;i+=2)
                    ans1[++m]=sum[i],ans2[m]=sum[i+1],v1[sum[i]]=1,v1[sum[i+1]]=1;
            }
       }
       printf("%d\n",m);
       for(int i=1;i<=m;++i)
           printf("%d %d\n",ans1[i],ans2[i]);
   } 
   return 0; 
}


