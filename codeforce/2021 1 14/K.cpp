#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
const db eps=1e-6;
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
bool isSegInter(P p1,P p2,P q1,P q2){//判 线段p1p2与q1q2是否相交 不用管重点
    return cha(p1,p2,q1)*cha(p1,p2,q2)<0&&cha(q1,q2,p1)*cha(q1,q2,p2)<0;
}

const int maxm=90005;
typedef pair <int,int> PP;
PP x1[maxm],x2[maxm];
int A,B;
bool del[maxm];

int main(){ 
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%lf%lf",&a[i].x,&a[i].y);
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j){
			A++;
            x1[A].fi=i;
			x1[A].se=j;
        }
    int flag=3*n-3-Convex(n);
	for (int i=n;i>=1;i--) a[i]=a[i-1];
    if(flag&1)
	{ 
        printf("1\n");
        fflush(stdout);
		del[1]=true;
		printf("%d %d\n",1,2);
		fflush(stdout);
		flag--;
		x2[++B]=x1[1];
	} else
	{
		printf("2\n");
		fflush(stdout);
    }
    PP f;
    while(1){ 
        scanf("%d%d",&f.fi,&f.se);
        if(!f.fi&&!f.se)break;
        if(f.fi>f.se)swap(f.fi,f.se);
		x2[++B]=f;
        flag--;
		for (int i=1;i<=A;i++)
            if(!del[i] && x1[i]==f)
			{ 
                del[i]=true;
				break;
            }
		for (int i=1;i<=A;i++)
			if (!del[i])
			{
				bool t=1;
				PP u=x1[i];
				for (int j=1;j<=B;j++)
				{ 
					PP v=x2[j];
					if(isSegInter(a[u.fi],a[u.se],a[v.fi],a[v.se]))
					{ 
						del[i]=true;
                        t=0;
						break;
					}
                }
				if (t)
				{ 
					printf("%d %d\n",u.fi,u.se);
					x2[++B]=u;
					del[i]=true;
					flag--;
					fflush(stdout);
					break;
				}
			}
    }
    return 0;
}
