#include<bits/stdc++.h>

using namespace std;
const int maxn=4005;
typedef double db;
struct Node{ 
    int x,y,v;
    bool operator<(const Node&a)const{return v<a.v;}
}P[maxn];
db dp[maxn];
int t,sx,sy,tx,ty,vf,vp,vh,cnt=0,n;
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        cnt=0;
        scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
        scanf("%d%d%d",&vf,&vp,&vh);
        scanf("%d",&n);
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        P[cnt++]={ a,b,c};
        for(int i=1;i<=n;++i){ 
            scanf("%d%d%d",&a,&b,&c);
            if(c<=P[0].v)continue;
            P[cnt++]={ a,b,c};
        }  
        sort(P,P+cnt);
        P[cnt++]={ tx,ty,1000000000};
        cnt--;
        for(int i=1;i<=cnt;++i)dp[i]=9e18;
        for(int i=1;i<=cnt;++i){ 
            for(int j=0;j<i;++j){ 
                db dis=sqrt((P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y));
                dp[i]=min(dp[i],dp[j]+dis/vh+dis/vh*vp/(P[j].v-vp));
            }
        }
        printf("%.15lf\n",dp[cnt]);
    }
    return 0;
}
