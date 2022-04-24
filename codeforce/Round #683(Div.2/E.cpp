//terryjoy 
#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define push_back pb
#define insert ins
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>PI;
int t,n;
int cnt[35],a,ans;
int Bit(int x){ 
    int k=0;
    while(x){ 
        k++;
        x>>=1;
    }
    return k;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>n;
    for(int i=1;i<=n;++i){ 
        cin>>a;
        cnt[Bit(a)]++;
    }
    int h=-1,t=-1;
    for(int i=0;i<=31;++i){ 
        if(cnt[i]){ h=i;break;}
    }
    for(int i=31;i>=0;--i){ 
        if(cnt[i])t=i;
    }
    if(h==t)cout<<0<<endl;
    else{ 
        ans=0x3f3f3f3f;
        int mx=0;
        for(int i=h;i<=t;++i){ 
            if(cnt[i]){ 
                int s1=i-1,s2=i+1;
                while(s1>=h){ 
                    if(cnt[i]>=1)mx+=(cnt[i]-1);
                }
                while(s2<=t){ 
                    if(cnt[i]>=1)mx+=(cnt[i]-1);
                }
                ans=max(ans,mx);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

