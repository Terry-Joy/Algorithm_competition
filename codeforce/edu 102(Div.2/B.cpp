#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
typedef long long ll;
int n,t;
string a,b;
int gcd(int a,int b){ return b?gcd(b,a%b):a;}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        string a1,b1;
        cin>>a>>b;
        int d=gcd(a.length(),b.length());
        for(int i=0;i<int(b.length()/d);++i){ 
            a1+=a;
        }
        for(int i=0;i<int(a.length()/d);++i){ 
            b1+=b;
        }
        if(a1==b1)cout<<a1<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
