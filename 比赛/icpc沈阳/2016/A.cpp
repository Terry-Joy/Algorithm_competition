#include<bits/stdc++.h>

using namespace std;

int main(){ 
    int a,b,t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>a>>b;
        cout<<2*max(a,b)+min(a,b)<<"\n";
    }
    return 0;
}
