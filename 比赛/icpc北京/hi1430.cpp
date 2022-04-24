#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=5e4+5;
char a[maxn];
ll C[110][110],sum[110][maxn],f[110][maxn];//sum[i][j]原数组前j项和的i次方,f[i][j]表示前缀和的[0,j-1]的i次方之和
void init(){
    for(int i=0;i<=100;++i){
        for(int j=0;j<=i;++j)
            if(j==0||j==i)C[i][j]=1;
            else
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}
int t,n,k;
int main(){
    init();
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        scanf("%s",a+1);
        for(int i=1;i<=n;++i)sum[0][i]=1;
        for(int i=1;i<=n;++i)
		sum[1][i]=sum[1][i-1]+(a[i]-'0');
        for(int i=2;i<=k;++i)
            for(int j=1;j<=n;++j)
                sum[i][j]=sum[i-1][j]*sum[1][j]%mod;
        for(int i=1;i<=n;++i)
            f[0][i]=i;
        for(int i=1;i<=k;++i)
            f[i][1]=0;
        for(int i=1;i<=k;++i)
            for(int j=2;j<=n;++j)
                f[i][j]=(f[i][j-1]+sum[i][j-1])%mod;
        for(int i=1;i<=n;++i){
            ll ans=0;
            for(int j=0;j<=k;++j){
                ll x=C[k][j]*sum[j][i]%mod*f[k-j][i]%mod;
                if((k-j)&1)
                    ans=(ans-x+mod)%mod;
                else
                    ans=(ans+x)%mod;
            }
            if(i!=n)
                cout<<ans<<" ";
            else
                cout<<ans<<"\n";
        }
    }
    return 0;
}