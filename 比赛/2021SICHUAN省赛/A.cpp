#include<bits/stdc++.h>
using namespace std;
int t,k;
bool v[10];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        if(k>12){
            puts("0");continue;
        }
        int ans=0;
        for(int i=1;i<=min(k,6);++i){
            if(i>k/2)break;
            int j=k-i;
            if(j>=1&&j<=6)
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}