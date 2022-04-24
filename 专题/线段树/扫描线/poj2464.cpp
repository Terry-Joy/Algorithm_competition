#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define lowbit(x) (x&(-x))
using namespace std;
const int maxn=2e5+5;
struct P{
    int x,y,id;
}p[maxn];
bool cmp(P a,P b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
bool cmp2(P a,P b){
    if(a.y==b.y)return a.x<b.x;
    return a.y<b.y;
}
int n,u[maxn],d[maxn],l[maxn],r[maxn],Y[maxn],cnty,mp[maxn],m,Top[maxn];
set<int>q1,ans;
struct BIT{
    int c[maxn];
    void add(int x,int val){
        while(x<=m){
            c[x]+=val;
            x+=lowbit(x);
        }
    }
    int ask(int x){
        int ans=0;
        while(x){
            ans+=c[x];
            x-=lowbit(x);
        }
        return ans;
    }
}bit;
void init(){
    sort(Y+1,Y+1+cnty);
    m=unique(Y+1,Y+1+cnty)-(Y+1);
    for(int i=0;i<=n;++i)u[i]=l[i]=r[i]=d[i]=Top[i]=bit.c[i]=0;
    for(int i=1;i<=n;++i){
        mp[p[i].id]=lower_bound(Y+1,Y+1+m,p[i].y)-Y;
    }
    sort(p+1,p+1+n,cmp2);
    int num=0,pre=1;
    for(int i=1;i<=n;++i){
        if(p[i].y!=p[i-1].y){
            num=0;
            for(int j=pre;j<=i-1;++j){
                Top[p[j].id]=n-(i-1);
            }
            pre=i;
        }
        l[p[i].id]=num;
        num++;
    }
    num=0;
    for(int i=n;i>=1;--i){
        if(p[i].y!=p[i+1].y)num=0;
        r[p[i].id]=num;
        num++;
    }
    sort(p+1,p+1+n,cmp);
    num=0;
    for(int i=1;i<=n;++i){
        if(p[i].x!=p[i-1].x)num=0;
        d[p[i].id]=num;
        num++;
    }
    num=0;
    for(int i=n;i>=1;--i){
        if(p[i].x!=p[i+1].x)num=0;
        u[p[i].id]=num;
        num++;
    }
}
int main(){
    while(~scanf("%d",&n)&&n){
        q1.clear();ans.clear();
        cnty=0;
        for(int i=1;i<=n;++i){
            scanf("%d%d",&p[i].x,&p[i].y);
            Y[++cnty]=p[i].y;
            p[i].id=i;
        }
        init();
        int pre=1,mx=2e9;
        int nowmx=0;
        for(int i=1;i<=n;++i){
            if(p[i].x!=p[i-1].x&&i!=1){
                if(mx>nowmx){
                    ans=q1;
                    nowmx=mx;
                }else if(mx==nowmx){ 
                    set<int>::iterator v;
                    for(v=q1.begin();v!=q1.end();v++)
                        ans.insert(*v);
                }
                q1.clear();
                mx=2e9;
            }
            int id=p[i].id;
            int bl=bit.ask(mp[p[i].id])-d[id]-l[id];
            int ul=i-1-d[id]-bl-l[id];
            int ur=Top[id]-ul-u[id];
            int br=n-ul-ur-bl-u[id]-l[id]-r[id]-d[id]-1;
            if(ur+bl<mx){
                mx=ur+bl;
                q1.clear();
                q1.insert(ul+br);
            }
            else if(ur+bl==mx){
                q1.insert(ul+br);
            }
            bit.add(mp[p[i].id],1);
        }       
        printf("Stan: %d; Ollie:",nowmx);
        set<int>::iterator i;
        for(i=ans.begin();i!=ans.end();i++){
            printf(" %d",*i);
        }
        if(ans.empty())
            cout<<" 0";
        puts(";");
    }
    return 0;
}
