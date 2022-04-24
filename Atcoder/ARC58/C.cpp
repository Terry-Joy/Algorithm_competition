#include<bits/stdc++.h>
using namespace std;
int n,k,d[12];
bool check(int x){ 
    while(x){ 
        int bit=x%10;
        if(d[bit])return 0;
        x/=10;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    int x;
    for(int i=0;i<k;++i){ 
        cin>>x;
        d[x]=1;
    }
    for(int i=n;i<=999999;++i){ 
        if(check(i)){ 
            cout<<i;
            return 0;
        }
    }
    return 0;
}
