#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e7+5;
int n,t,prime[maxn],f[maxn],cnt,c,d,x;
bool v[maxn];
void init(){
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i,f[i]=1;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0){
                f[i*prime[j]]=f[i];break;
            }
            else f[i*prime[j]]=f[i]+1;
        }
    }
}
int mypow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
int cal(int y){
    if((d+y)%c)return 0;
    return mypow(2,f[(d+y)/c]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin>>t;
    while(t--){
        ll ans=0;
        cin>>c>>d>>x;
        for(int i=1;i*i<=x;++i){
            if(x%i==0){
                ans+=cal(i);
                if(i!=x/i)ans+=cal(x/i);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}