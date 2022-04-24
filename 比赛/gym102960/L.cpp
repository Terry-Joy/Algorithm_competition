#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
int prime[maxn],ans,cnt,n,a,b;
int v[maxn];
void init(){
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i,v[i]=i;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            if(prime[j]>v[i])break;
            v[i*prime[j]]=prime[j];
        }
    }
}
set<int>mp;
int main(){
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        mp.clear();
        scanf("%d%d",&a,&b);
        while(a!=1){
            mp.insert(v[a]);
            int x=v[a];
            while(a%x==0)a/=x;           
        }
        while(b!=1){
            mp.insert(v[b]);
            int x=v[b];
            while(b%x==0)b/=x;
        }
        cout<<mp.size()<<"\n";
    }
    return 0;
}