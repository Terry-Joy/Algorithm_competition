
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
char s[maxn];
int n,c[maxn];
queue<int>G[maxn];
void add(int x,int val){
    while(x<=n){
        c[x]+=val;
        x+=x&-x;
    }
}
int ask(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=x&-x;
    }
    return ans;
}
int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;++i){
        G[s[i]-'a'].push(i);
        add(i,1);
    }
    ll ans=0;
    for(int i=n;i;i--){
        int pos=G[s[i]-'a'].front();
        G[s[i]-'a'].pop();
        ans+=(ask(pos)-1);
        add(pos,-1);
    }
    cout<<ans<<"\n";
    return 0;
}