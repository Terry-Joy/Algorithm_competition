#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
    int ans=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n+m;++i){
        scanf("%d",&a);
        ans+=(a==0);
    }
    cout<<abs(m-ans)<<"\n";
    return 0;
}