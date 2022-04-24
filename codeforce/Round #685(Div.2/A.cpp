#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
int t,n;
int main(){
    cin>>t;
    while(t--){ 
        cin>>n;
        if(n==1)cout<<0<<endl;
        else if(n==2)cout<<1<<endl;
        else if(n==3||n%2==0)cout<<2<<endl;
        else cout<<3<<endl;
    }
    return 0;
}
