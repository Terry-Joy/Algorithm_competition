#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n;
        int x;
        for(int i=1;i<=n;++i){ 
            if(i==1)x=9;
            else if(i==2)x=8;
            else x=(x+1)%10;
        cout<<x;
        }
        cout<<"\n";
    }
    return 0;
}
