#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int mod=1e9+7;
const int maxn=2e5+5;
int fac[maxn],inv[maxn],num1[maxn],num2[maxn];
char s[maxn];
int C(int n,int m){
    return 1ll*fac[n]*inv[n-m]%mod*inv[m]%mod;
}
int mypow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1ll*ans*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return ans;
}
void init(){
    fac[1]=1;
    for(int i=2;i<maxn;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[maxn-1]=mypow(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;    
}
int main(){
    init();
    scanf("%s",s+1);
    int len=strlen(s+1);
    vector<int>L;
    int L1=0,R1=0;
    for(int i=1;i<=len;++i){
        if(s[i]=='(')num1[i]=L1++;
        L.push_back(i);
    }
    for(int i=len;i>=1;--i){
        if(s[i]==')')R1++;
        else num2[i]=R1;
    }
    int ans=0;
    for(auto&v:L){//枚举(为计数DP的基准点
        ans=(1ll*ans+1ll*C(num1[v]+num2[v],num2[v]-1))%mod;
    }
    cout<<ans<<endl;
}