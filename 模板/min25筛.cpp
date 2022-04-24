#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;//根号n
const int maxm=2e6+5;
const int mod=1e9+7;
int cnt,id1[maxn],id2[maxn],sqr;
ll sum1[maxn],sum2[maxn],n,w[maxm],g1[maxm],g2[maxm],inv6;//sum1表示p的前缀和,sum2表示p^2的前缀和
ll prime[maxn],inv2,m=0;//注意g1 g2 w等根号分块的数组大小很可能大于根号N！！
bool v[maxn];
void init(){
    v[1]=1;
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=1;i<=cnt;++i){//预处理f(p)中几个单项式的和
        sum1[i]=(sum1[i-1]+prime[i])%mod;
        sum2[i]=(sum2[i-1]+prime[i]*prime[i]%mod)%mod;   
    }
}
ll mypow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
ll S(ll x,int j){//递归求S  从2开始 不算S(1)
    if(prime[j]>=x)return 0;
    int t=((x<=sqr)?id1[x]:id2[n/x]);
    ll ans=((g2[t]-g1[t])+mod-(sum2[j]-sum1[j])+mod)%mod;//质数部分 
    for(int i=j+1;i<=cnt&&prime[i]*prime[i]<=x;++i){
        ll sp=prime[i];
        for(int e=1;sp<=x;sp*=prime[i],++e){
            int tmp=sp%mod;
            ans=(ans+1ll*tmp*(tmp-1)%mod*(S(x/sp,i)+(e>1)))%mod;
        }
    }
    return ans;
}
int main(){
    init();
    inv2=mypow(2,mod-2);
    inv6=mypow(6,mod-2);
    scanf("%lld",&n);
    sqr=sqrt(n+0.5);
    for(ll i=1,j;i<=n;i=j+1){//初始化g以及记录分块下要处理的数及其对应下标
        j=(n/(n/i));
        w[++m]=n/i;
        g1[m]=w[m]%mod;//g1 g2分别为对应要处理的p^k的前缀和 g1先当中间变量 w[m]为传进去处理的前缀和
        g2[m]=(g1[m]*(g1[m]+1)%mod*(2*g1[m]+1)%mod*inv6)%mod;
        g2[m]--;//前缀和得减去1
        g1[m]=(g1[m]*(g1[m]+1)%mod*inv2)%mod;
        g1[m]--;
        if(w[m]<=sqr)id1[w[m]]=m;
        else id2[n/w[m]]=m;
    }
    //dp处理出g(n)，质数处f(p)前缀和
    for(int i=1;i<=cnt;++i){
        ll pr=prime[i]*prime[i];
        for(int j=1;j<=m&&pr<=w[j];++j){
            ll x=w[j]/prime[i];
            x=((x<=sqr)?id1[x]:id2[n/x]);
            g1[j]=(g1[j]-prime[i]*(g1[x]-sum1[i-1])%mod+mod)%mod;//如果要卡常必要可以删去此处所有模数，因子数*根号n*K会不会炸 但用g的时候必须保证加回正数,最好只在有一个g的时候用
            g2[j]=(g2[j]-prime[i]*prime[i]%mod*(g2[x]-sum2[i-1]+mod)%mod+mod)%mod;
        }
    }
    printf("%d\n",(S(n,0)+1)%mod);
}
