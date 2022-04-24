#include<bits/stdc++.h>
using namespace std;
using db=double;
db dp[205];
int t;
int main(){
    cin>>t;
    int T=0;
    while(t--){    
        int p;
        cin>>p;
        db pp=p/100.0;
        dp[200]=1.0/pp;
        for(int i=199;i>=4;--i){ 
            dp[i]=pp*(1-i/200.0)*dp[min(200,i+4)]+(1-pp)*dp[min(200,i+3)]+1;
        } 
        printf("Case %d: %.10f\n",++T,dp[4]);
    }
    return 0;
}
