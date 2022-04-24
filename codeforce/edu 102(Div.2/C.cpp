#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
typedef long long ll;
int n,t,k;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n>>k;
        int li=n-k;
        int f=k-li-1;
        for(int i=1;i<=f;++i){ 
            cout<<i<<" ";
        }
        for(int i=k;i>f;--i){ 
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
