#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[65];
char s[55];
const int mod=2008;
int cnt=0;
void add(ll x){
    for(int i=52;i>=0;--i){
        if(x&(1ll<<i)){
            if(d[i])x^=d[i];
            else{
                cnt++;
                d[i]=x;
                break;
            }
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        ll sum=0;
        scanf("%s",s);
        int len=strlen(s);
        for(int j=0;j<len;++j){
            if(s[j]=='O')sum+=(1ll<<j);
        }
        add(sum);
    }
    cout<<(1ll<<cnt)%mod<<"\n";
    return 0;
}