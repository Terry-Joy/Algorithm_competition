#include<bits/stdc++.h>

using namespace std;
const int maxn=1e6+5;
int n,m,a[maxn],dp[maxn],pre[maxn];
int main(){
    while(~scanf("%d%d",&m,&n)){ 
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=0;i<=n;++i)dp[i]=0;
        for(int i=0;i<=n;++i)pre[i]=0;
        int tmp=-2e9;
        for(int i=1;i<=m;++i){ 
            tmp=-2e9;
            for(int j=i;j<=n;++j){ 
                dp[j]=max(pre[j-1],dp[j-1])+a[j];
                pre[j-1]=tmp;
                tmp=max(tmp,dp[j]);    
            }
        }
        cout<<tmp<<"\n";
    } 
    return 0;
}
