#include<bits/stdc++.h>

using namespace std;
bool dp[805][805];
int n,a[42];
typedef double db;
db S(int a,int b,int c){
    db p=(a+b+c)/2.0;
    return 100*sqrt(p*(p-a)*(p-b)*(p-c));
}
bool isTri(int a,int b,int c){
    vector<int>tri={a,b,c};
    sort(tri.begin(),tri.end());
    return tri[0]+tri[1]>tri[2];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;++i)cin>>a[i],sum+=a[i];
    dp[0][0]=1;
    int sum2=sum/2,ans=-1;
    for(int i=1;i<=n;++i){
        for(int j=sum2;j>=0;--j){
            for(int k=j;k>=0;--k){
                if(j-a[i]>=0&&dp[j-a[i]][k])
                    dp[j][k]=1;
                if(k-a[i]>=0&&dp[j][k-a[i]])
                    dp[j][k]=1;
            }
        }
    }
    for(int j=sum2;j>=0;--j){
        for(int k=j;k>=0;--k){
            if(!dp[j][k])continue;
            if(!isTri(j,k,sum-j-k))continue;
                ans=max(ans,(int)(floor(S(j,k,sum-j-k))));
        }
    }
    if(ans==-1)cout<<"-1";
    else cout<<ans;
    return 0;
}