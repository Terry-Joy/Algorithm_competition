#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=305;
int dep[maxn];
int map[maxn][maxn],n,m;
bool bfs(int start,int ed){
    if(start==ed) return false;
    queue<int>Q;
    while(!Q.empty()) Q.pop();
    Q.push(start);
    memset(dep,-1,sizeof(dep));
    dep[start]=0;
    while(!Q.empty()){
        int index=Q.front();
        Q.pop();
        for(int i=1;i<=m;i++){
            if(map[index][i]>0&&dep[i]==-1){
                dep[i]=dep[index]+1;
                Q.push(i);
            }
        }
    }
    return dep[ed]!=-1;
}
int bt=0;
int dfs(int start,int ed,int cnt){
    if(start==ed) return cnt;
    int d;
    for(int i=1;i<=m;i++){
        if(dep[i]==dep[start]+1&&map[start][i]>0){
                d = dfs(i,ed, min(cnt, map[start][i]));
                if(d>0){
                    map[start][i]-=d;
                    map[i][start]+=d;
                    return d;
                }
            }
        }
    return 0;
}
int Max_flow(int start,int ed){
    int ans=0;
    while(bfs(start,ed)){
        while(true){
            int d=dfs(start,ed,0x3f3f3f3f);
            if(d==0) break;
            ans+=d;
        }
    }
    return ans;
}
int main(){
    int start,ed,w;
    while(~scanf("%d%d",&n,&m)){
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++){
            cin>>start>>ed>>w;
            map[start][ed]+=w;
        }
        cout<<Max_flow(1,m)<<endl;
    }
    return 0;
}