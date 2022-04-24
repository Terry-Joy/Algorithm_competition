#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n,k;
int main(){
    scanf("%d",&t);
    while(t--){ 
        scanf("%lld%lld",&n,&k);
        if(k+1>=n)puts("Yes");
        else puts("No");
    } 
    return 0;
}
