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
const int maxn=2e5+5;
int t,n,a[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    while(t--){ 
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        sort(a+1,a+1+n);
        int m=unique(a+1,a+1+n)-(a+1);
        if(m<n)puts("YES");
        else puts("NO");
    }
    return 0;
}

