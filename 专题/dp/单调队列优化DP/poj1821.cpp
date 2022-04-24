#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=16005;
int n,k,dp[105][maxn],h,t;
struct Node{ 
    int l,p,s;
    bool operator<(const Node&a)const{ 
        return s<a.s;
    }
}node[105];
struct Q{ 
    int val,id;
    Q(){ }
    Q(int x,int y){ 
        val=x;id=y;
    }
}q[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=k;++i){ 
        cin>>node[i].l>>node[i].p>>node[i].s;
    }
    sort(node+1,node+1+k);
    for(int i=1;i<=k;++i){ 
        h=1;t=0;
        for(int j=max(0,node[i].s-node[i].l);j<=node[i].s-1;++j){ //入队
                Q tmp(dp[i-1][j]-j*node[i].p,j);
                while(h<=t&&q[t].val<=tmp.val)t--;
                q[++t]=tmp;
        }
        for(int j=1;j<=n;++j){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(j>=node[i].s){ 
                while(h<=t&&q[h].id<j-node[i].l)h++;//排除队头不合法决策
                if(h<=t)
                    dp[i][j]=max(dp[i][j],j*node[i].p+q[h].val);
            }
        }
    }
    cout<<dp[k][n];
    return 0;
}
