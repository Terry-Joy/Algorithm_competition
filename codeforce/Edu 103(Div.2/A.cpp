#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
int t,n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    while(t--){ 
        cin>>n>>k;
        if(n>=k){ 
            if(n%k==0)cout<<1<<"\n";
            else cout<<2<<"\n";
        }else{ 
            if(k%n==0)cout<<k/n<<"\n";
            else cout<<k/n+1<<"\n";
        }
    }
    return 0;
}
