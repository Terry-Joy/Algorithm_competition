//带单点修 插入区间k小值
#include<bits/stdc++.h>
using namespace std;
const int maxn=70005;
int n,big,num,pos[maxn],st=1,tmpcnt[305],tmpsum[maxn],m;
struct Block{//序列分块
    int l,r,sz;
    int cnt[305],sum[maxn];//序列前i块在值域第j块出现次数,前i块值j出现次数
    int a[605];
}b[605];
void init(){
    big=300;
    num=n/big+1;
    for(int i=0;i<=70000;++i)pos[i]=i/big+1;//这里将值域和序列块大小设为一样 需要卡常要改
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        b[pos[i]].a[++b[pos[i]].sz]=x;
    }
    for(int i=1;i<=num;++i){
        if(i>1)b[i].l=i-1;
        if(i<num)b[i].r=i+1;
        for(int j=1;j<=b[i].sz;++j){
            b[i].cnt[pos[b[i].a[j]]]++;
            b[i].sum[b[i].a[j]]++;
        }
        for(int j=0;j<=70000;++j){
            if(!j||pos[j]!=pos[j-1])b[i].cnt[pos[j]]+=b[i-1].cnt[pos[j]];
            b[i].sum[j]+=b[i-1].sum[j];
        }
    }
}
int kth(int l,int r,int k){
    int now=st,pl,pr;
    while(b[now].sz<l)l-=b[now].sz,now=b[now].r;
    pl=now,now=st;
    while(b[now].sz<r)r-=b[now].sz,now=b[now].r;
    pr=now;//块状链表上找位置 
    if(pl==pr){//[1,l][l+1,r][r+1,b.sz]
        for(int i=l;i<=r;++i)tmpcnt[pos[b[pl].a[i]]]++,tmpsum[b[pl].a[i]]++;//tmpcnt临时 值域第i块出现次数 tmpsum某数出现的次数
        now=1;//构建新的值域分块
        while(tmpcnt[now]<k)k-=tmpcnt[now],now++;
        now=(now-1)*big;
        while(tmpsum[now]<k)k-=tmpsum[now],now++;//进入值域树第三层找
        for(int i=l;i<=r;++i)tmpcnt[pos[b[pl].a[i]]]--,tmpsum[b[pl].a[i]]--;
        return now;
    }else{
        for(int i=l;i<=b[pl].sz;++i)tmpcnt[pos[b[pl].a[i]]]++,tmpsum[b[pl].a[i]]++;
        for(int i=1;i<=r;++i)tmpcnt[pos[b[pr].a[i]]]++,tmpsum[b[pr].a[i]]++;
        now=1;//值域分块中找
        while(tmpcnt[now]+b[b[pr].l].cnt[now]-b[pl].cnt[now]<k)k-=tmpcnt[now]+b[b[pr].l].cnt[now]-b[pl].cnt[now],now++;
        now=(now-1)*big;
        while(tmpsum[now]+b[b[pr].l].sum[now]-b[pl].sum[now]<k)k-=tmpsum[now]+b[b[pr].l].sum[now]-b[pl].sum[now],now++;
        for(int i=l;i<=b[pl].sz;++i)tmpcnt[pos[b[pl].a[i]]]--,tmpsum[b[pl].a[i]]--;
        for(int i=1;i<=r;++i)tmpcnt[pos[b[pr].a[i]]]--,tmpsum[b[pr].a[i]]--;
        return now;
    }
}
void update(int x,int y){
    int now=st;
    while(b[now].sz<x)x-=b[now].sz,now=b[now].r;
    int fi=b[now].a[x];
    if(fi==y)return;
    b[now].a[x]=y;
    while(now){//维护值域分块
        b[now].cnt[pos[fi]]--;
        b[now].cnt[pos[y]]++;
        b[now].sum[fi]--;
        b[now].sum[y]++;
        now=b[now].r;
    }
}
void split(int x){//直接分裂
    int newP=++num;
    b[newP].r=b[x].r;b[b[x].r].l=newP;b[x].r=newP;b[newP].l=x;
    b[newP].sz=b[x].sz/2;
    int del=b[x].sz-b[newP].sz;
    memcpy(b[newP].cnt,b[x].cnt,sizeof(b[x].cnt));
    memcpy(b[newP].sum,b[x].sum,sizeof(b[x].sum));
    for(int i=del+1;i<=b[x].sz;++i){
        b[newP].a[i-del]=b[x].a[i];
        b[x].cnt[pos[b[x].a[i]]]--;b[x].sum[b[x].a[i]]--;
        b[x].a[i]=0;
    }
    b[x].sz=del;
}
void ins(int x,int val){
    int now=st;
    while(b[now].sz<x){
        if(b[now].r)x-=b[now].sz,now=b[now].r;
        else break;
    }
    for(int i=b[now].sz;i>=x;--i)b[now].a[i+1]=b[now].a[i];
    b[now].a[x]=val;b[now].sz++;
    int on=now;
    while(now){//维护值域分块
        b[now].cnt[pos[val]]++;
        b[now].sum[val]++;
        now=b[now].r;
    }
    if(b[on].sz>=big*2)split(on);
}
int main(){
    scanf("%d",&n);
    init();
    scanf("%d",&m);
    int op,ans=0,x,y,k;
    for(int i=1;i<=m;++i){
        char s[2];
        scanf("%s",s);
        if(s[0]=='Q'){
            scanf("%d%d%d",&x,&y,&k);
            x^=ans;y^=ans;k^=ans;
            cout<<(ans=kth(x,y,k))<<"\n";
        }
        else if(s[0]=='M'){
            scanf("%d%d",&x,&y);
            x^=ans;y^=ans;
            update(x,y);
        }
        else{
            scanf("%d%d",&x,&y);
            x^=ans;y^=ans;
            ins(x,y);
        }
    }
    return 0;
}