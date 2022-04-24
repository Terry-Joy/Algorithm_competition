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
int n,a;
typedef pair<int,int>PI;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;++i){ 
        cin>>a;
        sum^=a; 
    }
    if(n%2==0&&sum)puts("NO");
    else { 
        cout<<"YES"<<endl;
        if(n%2==0)
        n--;
        cout<<n-1<<"\n";
        for(int i=3;i<=n;i+=2){ 
            cout<<i-2<<" "<<i-1<<" "<<i<<endl;
        }
        for(int i=3;i<=n;i+=2){ 
            cout<<i-2<<" "<<i-1<<" "<<n<<endl;
        }
    }
    return 0;
}

