#include<bits/stdc++.h>
#define ls rt<<1 
#define rs rt<<1|1
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
using namespace std;
typedef double db;
const db eps=1e-8;
const db INF=1e15;
const int maxn=505;
int t,n,m,cnt[maxn],mx[maxn*maxn*8],mn[maxn*maxn*8],add[maxn*maxn*8];
db mp[maxn*maxn*2];
void pushUp(int rt){ 
    mx[rt]=max(mx[ls],mx[rs]);
    mn[rt]=min(mn[ls],mn[rs]);
}
void pushDown(int rt){ 
    if(!add[rt])return;
    mx[ls]+=add[rt];mx[rs]+=add[rt];
    mn[ls]+=add[rt];mn[ls]+=add[rt];
    add[ls]+=add[rt];add[rs]+=add[rt];
    add[rt]=0;
}
void update(int rt,int l,int r,int L,int R,int val){ 
    if(L<=l&&r<=R){ 
        add[rt]+=val;
        mx[rt]+=val;mn[rt]+=val;return;
    }
    int mid=l+r>>1;
    pushDown(rt);
    if(L<=mid)update(lson,L,R,val);
    if(R>mid)update(rson,L,R,val);
    pushUp(rt);
}
db query(int rt,int l,int r,int val){
    db ans=0;
    if(mx[rt]==val&&mn[rt]==val){ 
        ans+=mp[r+1]-mp[l];
        return ans;
    }
    pushDown(rt);
    if(l==r)return mp[r+1]-mp[l];//叶子结点得终止 
    int mid=l+r>>1;
    if(mx[ls]==val)ans+=query(lson,val);
    if(mx[rs]==val)ans+=query(rson,val);
    return ans;
}
void build(int rt,int l,int r){ 
    add[rt]=0;
    if(l==r){ 
        mx[rt]=mn[rt]=0;return;
    }
    int mid=l+r>>1;
    build(lson);
    build(rson);
    pushUp(rt);
}
int sign(db a){ //符号正负
    return a<-eps?-1:a>eps;
}

int dcmp(db a,db b){ //两数大小
    return sign(a-b);
}

db dAbs(db a){return a*sign(a);}

struct P{ //点向量类
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){ }
    P operator+(P p){return P(x+p.x,y+p.y);}//左操作数
    P operator-(P p){ return P(x-p.x,y-p.y);}
    P operator*(db d){return P(x*d,y*d);}
    P operator/(db d){ return P(x/d,y/d);}
}p[maxn];
bool operator==(P a,P b){return !dcmp(a.x,b.x)&&!dcmp(a.y,b.y);}

db dot(P a,P b){//内积
    return a.x*b.x+a.y*b.y;
}
db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}
struct L{//ps[0]->ps[1]
    P ps[2];
    P &operator[](int i){return ps[i];}
    P dir(){return ps[1]-ps[0];}//直线方向向量
    L(P X=P(),P Y=P()){ ps[0]=X,ps[1]=Y;}
}line[maxn];
struct Seg{ 
    db l,r;
    bool operator<(const Seg&a)const{ return l<a.l;}
}seg[maxn][maxn];
int mpcnt;
P LineInter(L l1,L l2){ //两直线交点 不平行的时候用
    P a=l1.ps[0],b=l1.ps[1],c=l2.ps[0],d=l2.ps[1];
    db t=det(a-c,c-d)/det(a-b,c-d);
    return P(a.x+(b.x-a.x)*t,a.y+(b.y-a.y)*t);
}
//线段相关
bool onSeg(P c,P a,P b){//判断c是否在线段ab上
    return sign(det(c-a,b-a))==0&&sign(dot(c-a,c-b))<=0;
}
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        mpcnt=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)cnt[i]=0;
        for(int i=1;i<=n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
        for(int i=1;i<=m;++i)scanf("%lf%lf%lf%lf",&line[i].ps[0].x,&line[i].ps[0].y,&line[i].ps[1].x,&line[i].ps[1].y);
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=m;++j){ 
                P c=p[i];L x=line[j];
                P a=x.ps[0],b=x.ps[1];
                if(onSeg(c,a,b)) seg[i][++cnt[i]]={-INF,INF};//点在线段上
                else{ 
                    L line3={P(0,0),P(10000,0)};
                    if(c.y>b.y){ 
                        L line1={c,a};
                        L line2={ c,b};
                        db x1=LineInter(line1,line3).x,x2=LineInter(line2,line3).x;
                        if(x1>x2)swap(x1,x2);
                        seg[i][++cnt[i]]={ x1,x2};
                    }else if(c.y>a.y){ 
                        L line1={c,a};
                        db xx=LineInter(line1,line3).x;
                        if(a.y>b.y)swap(a,b);
                        if(sign(det(c-a,b-a))<0)seg[i][++cnt[i]]={xx,INF};
                        else seg[i][++cnt[i]]={ -INF,xx};
                    }
                }
            }
            sort(seg[i]+1,seg[i]+1+cnt[i]);
            int k=cnt[i];
            cnt[i]=1;
            for(int j=2;j<=k;++j){ 
                if(seg[i][cnt[i]].r>seg[i][j].l)
                    seg[i][cnt[i]].r=max(seg[i][cnt[i]].r,seg[i][j].r);
                else
                    seg[i][++cnt[i]]=seg[i][j];
            }
            for(int j=1;j<=cnt[i];++j){ 
                mp[++mpcnt]=seg[i][j].l;
                mp[++mpcnt]=seg[i][j].r;
            }
        }
        for(int i=1;i<=mpcnt;++i){ 
            cout<<mp[i]<<" ";
        }
        sort(mp+1,mp+1+mpcnt);
        int num=unique(mp+1,mp+1+mpcnt)-(mp+1);
        build(1,1,num-1);
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=cnt[i];++j){ 
                int l=lower_bound(mp+1,mp+1+num,seg[i][j].l)-mp;
                int r=lower_bound(mp+1,mp+1+num,seg[i][j].r)-mp;
                if(r-1>=l)
                update(1,1,num,l,r-1,1);
            }
        }
        db ans=query(1,1,num-1,n);
        if(ans>=1e9)
            puts("-1");
        else printf("%.10lf\n",ans);
    }
    return 0;
}
