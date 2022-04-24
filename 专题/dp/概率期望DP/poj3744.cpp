#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e3+5;
double dp[maxn],p;
int n,cnt=0,a[15];
bool v[maxn];
int main(){ 
    while(~scanf("%d%lf",&n,&p)){ 
        dp[1]=1.0;
        dp[0]=0;
        memset(dp,0,sizeof(dp));
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        for(int i=0;i<n;++i){ 
            if(a[i+1]-a[i]>100){ 
                for(int j=n;j>=i+1;--j)
                    a[j]-=(a[i+1]-a[i]-100);
            }
        }
        for(int i=1;i<=n;++i)v[a[i]]=1;
        dp[1]=1;
        for(int i=2;i<=a[n]+1;++i){ 
            if(v[i-1]&&v[i-2])continue;
            if(v[i-1])
                dp[i]+=(1-p)*dp[i-2];
            else if(v[i-2])
                dp[i]+=p*dp[i-1];
            else 
                dp[i]+=p*dp[i-1]+(1-p)*dp[i-2];
        }
        printf("%.7f\n",dp[a[n]+1]);
    }
    return 0;
}
