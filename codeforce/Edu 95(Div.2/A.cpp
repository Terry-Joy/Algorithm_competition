#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
       ll x,y,k;
       cin>>x>>y>>k;
       ll a=((k+k*y-1)%(x-1)==0)?(k+k*y-1)/(x-1):((k+k*y-1)/(x-1))+1;
       cout<<a+k<<endl;
    }
    return 0;
}
