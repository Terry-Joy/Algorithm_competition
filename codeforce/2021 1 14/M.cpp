#include<bits/stdc++.h>
#define cha(p1,p2,p3) ((det(p2-p1,p3-p1)))//p2-p1叉p3-p1
#define fi first
#define se second
using namespace std;
typedef double db;
const db eps=1e-6;

struct P{ //点向量类
    int x,y;
    P(int _x=0,int _y=0):x(_x),y(_y){ }
    P operator+(P p){return P(x+p.x,y+p.y);}//左操作数
    P operator-(P p){ return P(x-p.x,y-p.y);}
    P operator*(db d){return P(x*d,y*d);}
    P operator/(db d){ return P(x/d,y/d);}
    bool operator<(const P&a)const{ 
        if(x==a.x)return y<a.y;
        return x<a.x;
    }
    int operator*(const P&p)const{ 
        return x*p.y-y*p.x;
    }
};
int det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}
bool inter(P x, P y, P a, P b) {
    if (((y - x) * (a - x)) * ((y - x) * (b - x)) >= 0) return 0;
    if (((x - a) * (b - a)) * ((y - a) * (b - a)) >= 0) return 0;
    return 1;
}
const int maxn=305;
P a[maxn],ch[maxn];
int Convex(int n){ 
    sort(a+1,a+n+1);
    int m=0;
    for(int i=1;i<=n;++i){ 
        while(m>1&&(det(ch[m-1]-ch[m-2],a[i]-ch[m-2]))<0)
            m--;
        ch[m++]=a[i];
    }
    int k=m;
    for(int i=n-1;i>=1;--i){ 
        while(m>k&&(det(ch[m-1]-ch[m-2],a[i]-ch[m-2]))<0)
            m--;
        ch[m++]=a[i];
    }
    if(n>1)m--;
    return m;
}
int n;
bool is[maxn][maxn];
int x,y;
void update(int x,int y){ 
    is[x][y]=is[y][x]=1;
}
typedef pair<int,int>Q;
vector<Q>use;
int main(){ 
    scanf("%d",&n);
    for(int i=1;i<=n;++i){ 
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    int flag=3*n-3-Convex(n);
    if(flag&1){ 
        printf("1\n");
        fflush(stdout);
        printf("1 2\n");
        use.push_back({ 1,2});
        fflush(stdout);
        update(1,2);
    }else{ 
        printf("2\n");
        fflush(stdout);
    }
    while(1){ 
        scanf("%d%d",&x,&y);
        if(!x&&!y)break;
        if(x>y)swap(x,y);
        use.push_back(make_pair(x,y));
        update(x,y);
        int t=1;
        for(int i=1;i<=n;++i){ 
            for(int j=i+1;j<=n;++j){ 
                t=1;
                if(is[i][j])continue;
                for(auto&v:use){ 
                    if(inter(a[i],a[j],a[v.fi],a[v.se])){ 
                        t=0;break;
                    }
                }
                if(t==1){ 
                    t=2;
                    printf("%d %d\n",i,j);
                    update(i,j);
                    fflush(stdout);
                    use.push_back(make_pair(i,j));
                    break;
                }
            }
            if(t==2)break;
        }
    }
    return 0;
}
