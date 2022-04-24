#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
char dp[105][105];
string s;
ll Mod;
ll mypow(ll a,ll b){ 
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%Mod;
        a=a*a%Mod;
        b>>=1;
    }
    return ans;
}
char chos(char s1,char s2){ 
    if(s1==s2)return s1;
    if(s1=='P'&&s2=='R')return s1;
    if(s1=='P'&&s2=='S')return s2;
    if(s1=='R'&&s2=='P')return s2;
    if(s1=='R'&&s2=='S')return s1;
    if(s1=='S'&&s2=='P')return s1;
    if(s1=='S'&&s2=='R')return s2;
}
int main(){
    int n,k;
    cin>>n>>k;
    cin>>s;
    s='='+s;
    Mod=n;
    for(int i=1;i<=n;++i)dp[i][0]=s[i];
    for(int j=1;j<=k;++j){ 
        ll f=mypow(2,j-1);
        for(int i=1;i<=n;++i){ 
            int a=(i+f)%Mod;
            if(a==0)a=n;
            dp[i][j]=chos(dp[i][j-1],dp[a][j-1]);    
        }
    }
    cout<<dp[1][k];
	return 0;
}

