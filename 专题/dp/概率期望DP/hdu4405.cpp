#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
double dp[maxn];
int n,m,d[maxn];
int main(){ 
    while(~scanf("%d%d",&n,&m)){ 
        if(!n&&!m)break;
        memset(dp,0,sizeof(dp));
        memset(d,-1,sizeof(d));
        for(int i=1;i<=m;++i){ 
            int a,b;
            scanf("%d%d",&a,&b);
            d[a]=b;
        }
        for(int i=n-1;i>=0;--i){ 
            if(d[i]!=-1){ 
                dp[i]=dp[d[i]];
            }else{ 
                for(int j=i+1;j<=i+6;++j)
                    dp[i]+=1.0/6*(dp[j]+1);
            }
        }
        printf("%.4f\n",dp[0]);
    }
    return 0;
}
