#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int main(){	
	int t;
    cin>>t;
    int T=0;
    while(t--){ 
        scanf("%d",&n);
        ll ans=0;
        for(int i=1,j;i<=n;i=j+1){ 
            j=min(n,n/(n/i));
            ans+=1ll*(j-i+1)*(n/i);
        }
        cout<<"Case "<<++T<<": "<<(ans&1?"odd":"even")<<"\n";
    }

}
