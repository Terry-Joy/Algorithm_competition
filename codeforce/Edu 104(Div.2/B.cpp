#include<bits/stdc++.h>
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
        if(n&1){
            int m=(k-1)/((n/2));
            int st=k-1;
            cout<<(1+(st+m)%n)<<"\n";
        }else{ 
            if(k%n==0)
                    cout<<n<<"\n";
            else 
                cout<<k%n<<"\n";
        }
    }
    return 0;
}
