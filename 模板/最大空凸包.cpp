//O(n^3)最大空凸包面积模板
#include<bits/stdc++.h>
#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))//p2-p1叉p3-p1
#define cha1(p1,p2,p3) det(p2-p1,p3-p1)
using namespace std;
typedef double db;
const int maxn=55;
const db PI=acos(-1.0);
const db eps=1e-8;

struct P{
    db x,y;
    P():x(0),y(0){}
    P(db x,db y):x(x),y(y){}
    P operator-(P p){ return P(x-p.x,y-p.y);}
}a[maxn],p[maxn],O;
int T,n,cnt;
db ans,dp[maxn][maxn];//以三角形Oij为凸包最后一块三角形的面积 

int sign(db a){ //符号正负
    return a<-eps?-1:a>eps;
}

int dcmp(db a,db b){ //两数大小
    return sign(a-b);
}

db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}

db dis(P p1,P p2){
    return (p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y);
}
//极角排序函数，角度相同则距离小的在前面
bool cmp(P p1,P p2){
    db tmp=cha(O,p1,p2);
    if(tmp>0) return 1;
    else if(tmp==0&&dis(O,p1)<dis(O,p2)) return 1;
    return 0;
}


void solve(){
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            dp[i][j]=0.0;
    for(int i=1;i<=cnt;++i){
        int j=i-1;
        while(j&&!cha(O,p[i],p[j])) --j;//找到第一个不共线的 
        int flag=(j==i-1);//oi上有点 
        while(j){
            int k=j-1;
            while(k&&cha(p[i],p[j],p[k])>0) --k;// 
            db area=fabs(cha1(O,p[i],p[j]))/2.0;
            if(k) area+=dp[j][k];
            if(flag) dp[i][j]=area;//Oi上没点才能更新dp,否则下个点回算进内点 
            ans=max(ans,area);
            j=k;
        }
        if(flag) for(int j=1;j<i;++j) dp[i][j]=max(dp[i][j],dp[i][j-1]);//前缀最大值优化 
    }
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ans=0.0;
        for(int i=0;i<n;++i)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        for(int i=0;i<n;++i){
            O=a[i];
            cnt=0;
            for(int j=0;j<n;++j)
                if(dcmp(a[j].y,a[i].y)>0||dcmp(a[j].y,a[i].y)==0&&dcmp(a[j].x,a[i].x)>0) p[++cnt]=a[j];
            sort(p+1,p+cnt+1,cmp);
            solve();
        }
        printf("%.1lf\n",ans);
    }
    return 0;
}
