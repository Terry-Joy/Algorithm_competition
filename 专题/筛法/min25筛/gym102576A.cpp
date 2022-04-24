#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=6e5+5;//根号n
const int maxm=2e6+5;
const int mod=1e9+7;
int cnt,id1[maxn],id2[maxn],sqr;
ll sum1[maxn],sum2[maxn],n,w[maxm],g1[maxm],inv6;//sum1表示p的前缀和,sum2表示p^2的前缀和
ll prime[maxn],inv2,m=0;//注意g1 g2 w等根号分块的数组大小很可能大于根号N！！
bool v[maxn];
void init(int maxn){
    v[1]=1;
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){ 
        cnt=0;
        scanf("%lld",&n);
        sqr=sqrt(n+0.5);
        init(sqr+5);
        m=0;
        for(ll i=1,j;i<=n;i=j+1){//初始化g以及记录分块下要处理的数及其对应下标
            j=(n/(n/i));
            w[++m]=n/i;
            g1[m]=w[m];//g1 g2分别为对应要处理的p^k的前缀和 g1先当中间变量 w[m]为传进去处理的前缀和
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
                g1[j]=(g1[j]-(g1[x]-(i-1)));//如果要卡常必要可以删去此处所有模数，因子数*根号n*K会不会炸 但用g的时候必须保证加回正数,最好只在有一个g的时候用
            }
        }
        ll k=g1[1]-g1[2];
        printf("%lld\n",k+(n-k)/2+1);
    }
}
