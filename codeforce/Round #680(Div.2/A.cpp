#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define pb push_back
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long ll;
const int maxn=55;
int a[maxn],b[maxn],t,n,x;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    while(t--){ 
        cin>>n>>x;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i)cin>>b[i];
        bool f=1;
        for(int i=1;i<=n;++i){ 
            if(a[i]+b[n-i+1]>x)f=0;
        }
        if(f)puts("Yes");
        else puts("No");
    }
    return 0;
}
