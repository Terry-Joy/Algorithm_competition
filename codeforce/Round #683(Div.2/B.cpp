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
int t,n,a,m,cnt,sum=0,mn;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    while(t--){ 
        cin>>n>>m;
        mn=101;
        cnt=sum=0;
        bool flag=0;
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=m;++j){ 
                cin>>a;
                mn=min(mn,abs(a));
                if(!a){ flag=1;}
                sum+=abs(a);
                if(a<0)cnt++;
            }
        }
        if(flag){ 
            cout<<sum<<endl;
        }else{ 
            if(cnt%2==0)cout<<sum<<endl;
            else{ 
                cout<<sum-2*mn<<endl;
            }
        }
    }
    return 0;
}

