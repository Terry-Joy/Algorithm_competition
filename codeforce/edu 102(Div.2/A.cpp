#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
typedef long long ll;
int n,t,a[105],d;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n>>d;
        bool flag=1;
        for(int i=1;i<=n;++i){ 
            cin>>a[i];
        }
        for(int i=1;i<=n;++i){ 
            if(a[i]>d){ flag=0;break;}
        }
        if(flag==1){ 
            cout<<"YES"<<"\n";
            continue;
        }
        bool f=0;
        for(int i=1;i<=n;++i){ 
            if(f==1)break;
            for(int j=i+1;j<=n;++j)
                if(a[i]+a[j]<=d){ 
                    f=1;
                    break;
                }
        }
        if(f==1)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}
