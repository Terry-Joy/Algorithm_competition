#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
multiset<int>s;
const int maxn=2e5+7;
const int inf=2e9+5;
const int INF=0x3f3f3f3f;
int tr[maxn<<2],op[maxn],a[maxn],b[maxn],q,cnt[maxn];
void build(int p,int l,int r)
{//一开始初始化为最大值
    tr[p]=inf;
    if(l==r)return;
    int mid=l+r>>1;
    build(lson);
    build(rson); 
}
void update(int p,int l,int r,int pos,int val)
{
    if(l==r){ 
        tr[p]=val;
        return;    
    } 
    int mid=l+r>>1;
    if(pos<=mid)update(lson,pos,val);
    else update(rson,pos,val);
    tr[p]=min(tr[ls],tr[rs]);
}
int query(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)return tr[p];
    int mid=l+r>>1,ans1=inf,ans2=inf;
    if(L<=mid)ans1=query(lson,L,R);
    if(R>mid)ans2=query(rson,L,R);
    return min(ans1,ans2); 
}
int main()
{
    s.insert(-INF);s.insert(-INF);//正负无穷作为哨兵
    s.insert(inf);
    scanf("%d",&q);
    for(int i=1;i<=q;++i)
        scanf("%d%d",&op[i],&a[i]),b[i]=a[i];
    sort(a+1,a+1+q);
    int len=unique(a+1,a+1+q)-(a+1);
    build(1,1,len);
    for(int i=1;i<=q;++i)
    {
        if(op[i]==1){ 
            s.insert(b[i]);
            int x=lower_bound(a+1,a+1+len,b[i])-a;
            cnt[x]++;
            if(cnt[x]==1){//只有一个的时候是上一个和当前的差值
                update(1,1,len,x,*s.upper_bound(b[i])-b[i]);
                auto it=s.lower_bound(b[i]);
                it--;  
                int tmp=*it;
                int y=lower_bound(a+1,a+1+len,tmp)-a;
                if(cnt[y]==1)update(1,1,len,y,b[i]-tmp);//只有上一个数只剩一个的时候才更新
            } 
            else if(cnt[x]==2)update(1,1,len,x,0);//因为如果超过1个，最小差值肯定是0
        } 
        else if(op[i]==2) {
            s.erase(s.find(b[i]));
            int x=lower_bound(a+1,a+1+len,b[i])-a;
            cnt[x]--;
            if(cnt[x]==1)update(1,1,len,x,*s.upper_bound(b[i])-b[i]);//删到只剩一个的时候更新
            else if(!cnt[x]){ //删没的时候要更新前面那个
                update(1,1,len,x,inf);
                auto it=s.lower_bound(b[i]);
                it--;
                int tmp=*it;
                int y=lower_bound(a+1,a+1+len,tmp)-a;
                if(cnt[y]==1)update(1,1,len,y,*s.lower_bound(b[i])-tmp);
            }
        } 
        else{ 
            bool flag=0;
            auto it=s.lower_bound(b[i]);
            int t1=*it,t2=*(--it),t3=*(--it);
            int x=lower_bound(a+1,a+1+len,b[i])-a;
            if(t2+t3>b[i]||t2+b[i]>t1)flag=1;//判断第一种和第二种能否成三角形
            if(query(1,1,len,x,len)<b[i])flag=1;//第三种查询最小差值
            if(flag)puts("Yes");
            else puts("No"); 
        }
    }
    return 0; 
}
