
#include<iostream>
#include<cstring>
using namespace std;
 
const int maxn=105;
const int inf=1e9;
int box[maxn][maxn];
int level[maxn];
int price[maxn];
int vis[maxn];
int n,m;
 
int dijkstra(int start){
    int dist[maxn];
    for(int i=1;i<=n;i++)  //这里需要注意，初始化为inf，不能为box[1][i]，就因为这里wa两次，查了一个多小时
        dist[i]=inf;
    dist[1]=0;  //初始化为0，以便第一次循环从1开始
    for(int i=0;i<n;i++){
        int Min=inf,k=-1;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&dist[j]<Min){
                Min=dist[j];
                k=j;
            }
        if(k==-1)
            break;
        vis[k]=1;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&dist[j]>dist[k]+box[k][j])
                dist[j]=dist[k]+box[k][j];
    }
    int Min=inf;
    for(int i=1;i<=n;i++)     //计算最短路时，记得加上原先的价格
        Min=min(Min,price[i]+dist[i]);
    return Min;
}
int main(){
    while(cin>>m>>n){
        int k;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                box[i][j]=inf;
        for(int i=1;i<=n;i++){
            cin>>price[i]>>level[i]>>k;
            for(int j=1;j<=k;j++){
                int a,b;
                cin>>a>>b;
                box[i][a]=b;
            }
        }
        int Min=inf;
        for(int i=0;i<=m;i++){   //枚举等级，一开始还担心超时。
            memset(vis,0,sizeof(vis));   //全部标识为未访问
            for(int j=1;j<=n;j++)
                if((level[1]-m+i)>level[j]||level[j]>(level[1]+i)) //等级之外标识为已访问
                    vis[j]=1;
            Min=min(Min,dijkstra(1));
        }
        cout<<Min<<endl;
    }
    return 0;
}

