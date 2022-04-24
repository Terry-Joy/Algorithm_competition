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
ll W;
const int maxn=2e5+5;
struct Node{ 
    ll w;
    int id;
    bool operator<(const Node&a)const{ 
        return w<a.w;
    }
}a[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    while(t--){ 
        cin>>n>>W;
        int ans=0;
        for(int i=1;i<=n;++i){ 
            cin>>a[i].w;
            a[i].id=i;
            if(a[i].w>=ceil(W/2.0)&&a[i].w<=W)
                ans=i;
        }   
        if(ans){ 
            cout<<1<<endl;
            cout<<ans<<endl;
        }else{ 
            sort(a+1,a+1+n);
            ll sum=0;
            int k=0;
            bool flag=1;
            for(int i=1;i<=n;++i){
                sum+=a[i].w;
                if(sum>=ceil(W/2.0)&&sum<=W){ 
                    k=i;
                    break;
                }
                if(i==n&&sum<ceil(W/2.0))flag=0;
            }
            if(!flag)cout<<-1<<endl;
            else{ 
                if(!k)cout<<-1<<endl;
                else cout<<k<<endl;
                for(int i=1;i<=k;++i)
                    cout<<a[i].id<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}

