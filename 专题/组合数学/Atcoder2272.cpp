#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5+5;
const int mod=1e9+7;
int a[maxn],cnt[maxn],sum;
int mypow(int a,int b){ 
    int ans=1;
    while(b){ 
        if(b&1)ans=(ll)ans*a%mod;
        a=(ll)a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    int now=1,sum=0;
    for(int i=1;i<=n/2;++i){ 
        if(n-now>0)
            cnt[n-now]+=2,now+=2,sum+=2;
        else break;
    }
    for(int i=1;i<=n;++i){ 
        if(cnt[a[i]])cnt[a[i]]--,sum--;
    }
    if(!sum){ 
        cout<<mypow(2,n/2);
    }else 
        cout<<0;
    return 0;
}
