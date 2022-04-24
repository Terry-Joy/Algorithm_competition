#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5+10;
int a[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){ 
        int sum=0,cnt=0,ans=0;
        cin>>n;
        for(int i=1;i<=n;++i){ 
            cin>>a[i];
            if(a[i]&1)sum++;
        }
        if((n&1)&&(sum!=(n+1)/2&&(n-sum!=(n+1)/2))){ 
            cout<<"-1\n";continue;
        }else if(!(n&1)){ 
            if(sum!=n/2){ 
                cout<<"-1\n";continue;
            }
        }
        if(!(n&1)){ 
            int cnt=1;
            for(int i=1;i<=n;++i){ 
                if(a[i]&1)ans+=abs(i-cnt),cnt+=2;
            }
            cnt=2;
            int num=0;
            for(int i=1;i<=n;++i){ 
                if(a[i]&1)num+=abs(i-cnt),cnt+=2;
            }
            cout<<min(num,ans)<<"\n";
        }else{ 
            bool f=(sum==(n+1)/2);
            int cnt=1;
            for(int i=1;i<=n;++i){ 
                if(f){ 
                    if(a[i]&1)ans+=abs(i-cnt),cnt+=2;
                }else 
                    if(!(a[i]&1))ans+=abs(i-cnt),cnt+=2;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
