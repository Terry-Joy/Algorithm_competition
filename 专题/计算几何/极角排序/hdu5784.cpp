#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
typedef long long ll;
struct P{ 
    int x,y;
    P(int _x=0,int _y=0):x(_x),y(_y){ }
    P operator+(P p){ return P(x+p.x,y+p.y);}
    P operator-(P p){ return P(x-p.x,y-p.y);}
    ll len2(){ return (ll)x*x+(ll)y*y;}
}p[maxn],tmp[maxn<<1];


ll det(P a,P b){ 
    return (ll)a.x*b.y-(ll)a.y*b.x;
}
ll dot(P a,P b){
    return (ll)a.x*b.x+(ll)a.y*b.y;
}

int Qua(P a){ 
    if(a.x>0&&a.y>=0)return 1;
    if(a.x<=0&&a.y>0)return 2;
    if(a.x<0&&a.y<=0)return 3;
    if(a.x>=0&&a.y<0)return 4;
}
bool cmp2(P a,P b){ 
    int f1=Qua(a),f2=Qua(b);
    if(f1==f2){ 
        ll tmp=det(a,b);
        if(tmp>0)return 1;
        else if(!tmp&&a.len2()<b.len2())return 1;
        return 0;
    }
    return f1<f2;
}
int cnt;
int main(){ 
    int n;
    while(~scanf("%d",&n)){ 
        for(int i=1;i<=n;++i)scanf("%d%d",&p[i].x,&p[i].y);
        ll sum1=0,sum2=0;
        for(int i=1;i<=n;++i){ 
            cnt=0;
            for(int j=1;j<=n;++j){ 
                if(j==i)continue;
                tmp[++cnt]=p[j]-p[i];
            }
            sort(tmp+1,tmp+1+cnt,cmp2);
            for(int j=1;j<=n-1;++j)tmp[j+n-1]=tmp[j];
            int id1=1,id2=1,id3=1,id4=1;
            for(int j=1;j<=n-1;++j){ 
                while(id1<j+n-1&&det(tmp[j],tmp[id1])==0&&dot(tmp[j],tmp[id1])>0)id1++;//同向向量
                id2=max(id2,id1);
                while(id2<j+n-1&&det(tmp[j],tmp[id2])>0&&dot(tmp[j],tmp[id2])>0)id2++;//锐角
                id3=max(id3,id2);
                while(id3<j+n-1&&det(tmp[j],tmp[id3])>0&&dot(tmp[j],tmp[id3])==0)id3++;//直角
                id4=max(id4,id3);
                while(id4<j+n-1&&det(tmp[j],tmp[id4])>0)id4++;//钝角
                sum1+=id2-id1;//锐角
                sum2+=id4-id3+id3-id2;//钝角+直角
            }
        }
        cout<<(sum1-sum2*2)/3<<"\n";
    }
    return 0;
}
