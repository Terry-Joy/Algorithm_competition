#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int d[33],p[33],a,n,ask;
const int mod=10086;
void insert(int x){ 
    for(int i=30;i>=0;--i){ 
        if(x&(1<<i)){ 
            if(d[i])x^=d[i];
            else{ 
                d[i]=x;break;
            }
        }
    }
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
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){ 
        cin>>a;insert(a);
    }
    cin>>ask;
    int top=0;
    for(int i=0;i<=30;++i){ 
        if(d[i])p[top++]=i;
    }
    ll rk=0;
    for(int i=0;i<top;++i){//枚举最高的被删去的位 前面的位随便选
        if((1<<p[i])&ask)rk+=(1<<i);
    }
    cout<<(rk*mypow(2,n-top)+1)%mod;
    return 0;
}
