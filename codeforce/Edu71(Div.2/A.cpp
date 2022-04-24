#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
   int t;
   cin>>t;
   while(t--){ 
        ll x,y,k;
        cin>>x>>y>>k;
        ll a=((k*(y+1)-1)%(x-1)==0)?(k*(y+1)-1)/(x-1):(k*(y+1)-1)/(x-1)+1;
        cout<<a+k<<endl;
   }
   return 0;
}
