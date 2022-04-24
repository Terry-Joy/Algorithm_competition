#include<bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
struct Node{
    int id,numb,numc;
    bool operator<(const Node&a)const{
        if(numb==a.numb)return numc>a.numc;
        return numb>a.numb;
    }
}num[maxn];
int n,a[maxn],m,b[maxn],c[maxn],sum[maxn],d[maxn],cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;++i)cin>>b[i]; 
    for(int i=1;i<=m;++i)cin>>c[i];
    for(int i=1;i<=m;++i)num[i].id=i;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i){
        if(i==1||a[i]!=a[i-1])
            d[++cnt]=a[i];
    }
    for(int i=1;i<=n;++i){
        int id=lower_bound(d+1,d+1+cnt,a[i])-d;
        sum[id]++;
    }
    for(int i=1;i<=m;++i){
        int id=lower_bound(d+1,d+1+cnt,b[i])-d;
        if(d[id]==b[i])
            num[i].numb+=sum[id];
        id=lower_bound(d+1,d+1+cnt,c[i])-d;
        if(d[id]==c[i])
            num[i].numc+=sum[id];
    }
    sort(num+1,num+1+m);
    cout<<num[1].id<<endl;
    return 0;
}