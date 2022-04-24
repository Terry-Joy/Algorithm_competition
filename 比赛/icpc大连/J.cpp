#include<bits/stdc++.h>

using namespace std;

int main(){ 
    int t,n;
    cin>>t;
    int ans=0;
    while(t--){ 
        cin>>n;
        while(n){ 
            if(n%256==97)ans++;
            n/=256;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
