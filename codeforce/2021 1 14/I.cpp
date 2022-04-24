#include<bits/stdc++.h>

using namespace std;
#define fi first
#define se second
typedef double db;
const db eps=1e-10;
int n;
const int maxn=305;
int sign(db a){ 
    return a<-eps?-1:a>eps;
}

int dcmp(db a,db b){ 
    return sign(a-b);
}
struct P{ 
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){ }
    P operator+(P p){ return P(x+p.x,y+p.y);}
    P operator-(P p){ return P(x-p.x,y-p.y);}
    bool operator<(P p)const{ 
        int c=dcmp(x,p.x);
        if(c)return c==-1;
        return dcmp(y,p.y)==-1;
    }
};
db dot(P a,P b){ return a.x*b.x+a.y*b.y;}
db det(P a,P b){ return a.x*b.y-a.y*b.x;}
P a[maxn],ch[maxn];
P LineInter(P a,P b,P c,P d){ 
    db t=det(a-c,c-d)/det(a-b,c-d);
    return P(a.x+(b.x-a.x)*t,a.y+(b.y-a.y)*t);
}
int Convex(int n){ 
    sort(a,a+n);
    int m=0;
    for(int i=0;i<n;++i){ 
        while(m>1&&sign(det(ch[m-1]-ch[m-2],a[i]-ch[m-2]))<0)
            m--;
        ch[m++]=a[i];
    }
    int k=m;
    for(int i=n-2;i>=0;--i){ 
        while(m>k&&sign(det(ch[m-1]-ch[m-2],a[i]-ch[m-2]))<0)
            m--;
        ch[m++]=a[i];
    }
    if(n>1)m--;
    return m;
}
bool operator==(P a,P b){return !dcmp(a.x,b.x)&&!dcmp(a.y,b.y);}
#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))
bool recInter(db l1,db r1,db l2,db r2){ 
    if(l1>r1)swap(l1,r1);if(l2>r2)swap(l2,r2);
    return !(dcmp(r1,l2)==-1||dcmp(r2,l1)==-1);
}
bool isSegInter(P p1,P p2,P q1,P q2){//判 线段p1p2与q1q2是否相交 不用管重点
    return recInter(p1.x,p2.x,q1.x,q2.x)&&recInter(p1.y,p2.y,q1.y,q2.y)&&
        cha(p1,p2,q1)*cha(p1,p2,q2)<=0&&cha(q1,q2,p1)*cha(q1,q2,p2)<=0;
}
set<pair<int,int>>x1,x2;
int main(){ 
    scanf("%d",&n);
    for(int i=0;i<n;++i){ 
        scanf("%lf%lf",&a[i].x,&a[i].y);
    }
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j){ 
            x1.insert(make_pair(i+1,j+1));
        }
    int flag=3*n-3-Convex(n);
    if(flag&1){ 
        printf("1\n");
        fflush(stdout);
        int k=1;
        for(auto&x:x1){ 
            printf("%d %d\n",x.fi,x.se);
            x1.erase(x);
            flag--;
            pair<int,int>f=x;
            x2.insert(f);
            k--;
            if(!k)break;
        }
        fflush(stdout);
    }
    else { 
        printf("2\n");
        fflush(stdout);
    }
    pair<int,int>f;
    while(1){ 
        scanf("%d %d",&f.fi,&f.se);
        if(!f.fi&&!f.se)break;
        if(f.fi>f.se)swap(f.fi,f.se);
        x2.insert(f);
        flag--;
        for(auto&v:x1){ 
            if(v==f){ 
                x1.erase(v);break;
            }
        }
        for(auto&u:x1){ 
            bool t=1;
            for(auto&v:x2){ 
                if(a[u.fi]!=a[v.fi]&&a[u.fi]!=a[v.se]&&a[u.se]!=a[v.se]&&a[u.se]!=a[v.fi]){ 
                    if(isSegInter(a[u.fi],a[u.se],a[v.fi],a[v.se])){ 
                        x1.erase(u);
                        t=0;break;
                    }
                }
                else continue;
            }
            if(t){ 
                printf("%d %d\n",u.fi,u.se);
                f=u;
                x2.insert(f);
                x1.erase(u);
                flag--;
                fflush(stdout);
                break;
            }
            else continue;
        }
    }
    return 0;
}
