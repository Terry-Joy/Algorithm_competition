#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    if(!k)cout<<-1;
    else{
        cout<<k;
        for(int i=1;i<k;++i)cout<<" "<<i;
        for(int i=k+1;i<=n;++i)cout<<" "<<i;
    }
    return 0;
}