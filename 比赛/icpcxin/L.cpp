#include<bits/stdc++.h>

using namespace std;
const int maxn=2e6+5;
bool v[maxn];
int prime[maxn],cnt,f[maxn];
void init(){
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main(){
    init();
    for(int i=2;i<maxn;++i)
        if(v[i]){
            for(int j=i;j<maxn;j+=i)
                f[j]++;
        }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int a;
        scanf("%d",&a);
        cout<<f[a]+1<<"\n";
    }
    return 0;
}