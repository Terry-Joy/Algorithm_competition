#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6;
int n;
ll ask(int x,int y){
    ll d;
    cout<<x<<" "<<y<<endl;
    cin>>d;
    return d;
}
void get(){
    ll d=ask(0,0);
    if(!d)return;
    for(int i=0;i<=maxn&&1ll*i*i<=d;++i){
        int j=sqrt(d-1ll*i*i);
        if(1ll*i*i+1ll*j*j==d&&j<=maxn)
            if(ask(i,j)==0)return;
    }
}
int main(){
    scanf("%d",&n);
    while(n--){
        get();
    }
    return 0;
}