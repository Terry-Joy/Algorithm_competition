#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll sum[32];
int main(){ 
    int t;
    cin>>t;
    ll tmp=1,pow=2;
    for(int i=0;i<31;++i){ 
        sum[i]=(tmp*(tmp+1))/2;
        tmp+=pow;
        pow*=2;
    }
    while(t--){ 
        ll n;
        cin>>n;
        int ans=0;
        while(n){ 
            if(n-sum[ans]>=0){n-=sum[ans];ans++; }
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
