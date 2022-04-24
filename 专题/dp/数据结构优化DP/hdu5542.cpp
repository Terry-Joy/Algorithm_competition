#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e3+5;
const int mod=1e9+7;
ll dp[maxn][maxn];
int n,m,t,a[maxn],num,b[maxn];
void add(int x,int y,int val){
    while(x<=num){
        dp[x][y]+=val;
        if(dp[x][y]>=mod)dp[x][y]-=mod;
        x+=x&-x;
    }
}
ll query(int x,int y){
    ll ans=0;
    while(x){
        ans+=dp[x][y];
        if(ans>=mod)ans-=mod;
        x-=x&-x;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int f=1;f<=t;++f){
        cin>>n>>m;
        for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
        for(int i=0;i<=n;++i)
            for(int j=0;j<=m;++j)
                dp[i][j]=0;
        sort(b+1,b+1+n);
        num=unique(b+1,b+1+n)-(b+1);
        for(int i=1;i<=n;++i)a[i]=lower_bound(b+1,b+1+num,a[i])-b;
        for(int i=1;i<=n;++i){//限制数组下标
            int k=min(i,m);
            for(int j=1;j<=k;++j){
                if(j==1){
                    add(a[i],1,1);//限制了大小
                }else{
                    ll tmp=query(a[i]-1,j-1);
                    add(a[i],j,tmp);
                }
            }
        }
        cout<<"Case #"<<f<<": "<<query(num,m)<<"\n";
    }
    return 0;
}