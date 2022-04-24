#include <queue>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=20010;
struct edge{
    int to,cost,val;
    edge(){}
    edge(int a,int b,int c){to=a;cost=b;val=c;}
};
typedef pair<int,int>P;
vector<edge>G[maxn];
int dis[maxn],value[maxn];
void dijkstra(int st){
    priority_queue<P,vector<P>,greater<P> >que;
    fill(dis,dis+maxn,inf);
    fill(value,value+maxn,inf);
    dis[st]=0;
    que.push(P(0,st));
    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        if(dis[v]<p.first) continue;
        for(unsigned int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(dis[e.to]>dis[v]+e.cost){
                dis[e.to]=dis[v]+e.cost;
                value[e.to]=e.val;
                que.push(P(dis[e.to],e.to));//��Ϊ���Ǵ�1����������1��3��С������ͨ��1->2->3�����ģ����ǽ�1->3�ķ��þͼ�Ϊ
                                            //2->3�ķ��ã���Ϊ1->2�ķ��ÿ϶��Ѿ��Ứ�ģ�Ҫ�����õ�ÿ��·�ķ��ã��������1��
                                            //ÿ����ķ��ü�����������
            }else if(dis[e.to]==dis[v]+e.cost){//���ʱҪС�ķ���
                value[e.to]=min(value[e.to],e.val);
            }
        }
    }
}
int main(){
    int n,m,a,b,c,d;
    while(scanf("%d%d",&n,&m)!=-1){
        if(n==0&&m==0) break;
        for(int i=0;i<maxn;i++) G[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            G[a].push_back(edge(b,c,d));
            G[b].push_back(edge(a,c,d));
        }
        dijkstra(1);
        int ans=0;
        for(int i=2;i<=n;i++) ans+=value[i];
        printf("%d\n",ans);
    }
    return 0;
}

