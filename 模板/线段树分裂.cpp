//线段树分裂 分裂其实可看作区间查询 每次最多增加O(2logn)结点
//维护多个可重集 合并带内存回收
//0.p集合中值从x到y的放入放入新集合
//1.把t合并到p中，清空t(t以后不出现) 这里用了内存回收 2.p中加入x个q
//3.查询p中x到y数量     4.查询p中第k小
#include<bits/stdc++.h>
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
typedef long long ll;
#define N maxn*32
const int maxn=2e5+5;
int n,m,op,cntset=1,a[maxn],rt[maxn];
struct SementTree{
    int lc[N],rc[N],tot,rub[N],cnt=0;
    ll sum[N];
    int New(){//内存回收  分裂合并同时有的时候必须使用
        if(cnt)return rub[cnt--];
        return ++tot;
    }
    void del(int&p){
        ls=rs=sum[p]=0;
        rub[++cnt]=p;
        p=0;
    }
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void build(int&p,int l,int r){
        if(!p)p=New();
        if(l==r){
            sum[p]=a[l];return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void update(int&p,int l,int r,int x,int val){
        if(!p)p=New();
        if(l==r){
            sum[p]+=val;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    int merge(int &p,int &q,int l,int r){
        if(!p||!q)return p+q;
        if(l==r){
            sum[p]+=sum[q];
            del(q);
            return p;
        }
        int mid=l+r>>1;
        ls=merge(ls,lc[q],l,mid);
        rs=merge(rs,rc[q],mid+1,r);
        del(q);
        pushUp(p);
        return p;
    }
    void split(int&p,int&q,int l,int r,int L,int R){
        if(L>r||R<l)return;
        if(!p)return;
        if(L<=l&&r<=R){
            q=p;
            p=0;return;//直接断边接上
        }
        if(!q)q=New();
        int mid=l+r>>1;
        if(L<=mid)split(ls,lc[q],l,mid,L,R);
        if(R>mid)split(rs,rc[q],mid+1,r,L,R);
        pushUp(p);//两颗更新
        pushUp(q);
    }
    ll query(int p,int l,int r,int L,int R){
        if(!p)return 0;
        if(L<=l&&r<=R)return sum[p];
        int mid=l+r>>1;
        ll ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
    int kth(int p,int l,int r,int k){
        if(l==r)return l;
        int mid=l+r>>1;
        if(sum[ls]>=k)return kth(lson,k);
        else return kth(rson,k-sum[ls]);
    }
}tr;
int main(){
    int x,y,z;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    tr.build(rt[1],1,n);
    for(int i=1;i<=m;++i){
        cin>>op;
        if(!op){
            cin>>x>>y>>z;
            tr.split(rt[x],rt[++cntset],1,n,y,z);
        }else if(op==1){
            cin>>x>>y;
            rt[x]=tr.merge(rt[x],rt[y],1,n);
        }else if(op==2){
            cin>>x>>y>>z;
            tr.update(rt[x],1,n,z,y);
        }else if(op==3){
            cin>>x>>y>>z;
            cout<<tr.query(rt[x],1,n,y,z)<<"\n";
        }else if(op==4){
            cin>>x>>y;
            if(tr.sum[rt[x]]<y)cout<<-1<<"\n";
            else cout<<tr.kth(rt[x],1,n,y)<<"\n";
        }
    }
    return 0;
}

//区间排序后求某点
#include<bits/stdc++.h>
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define N maxn*54
using namespace std;
typedef set<int>::iterator IT;
const int maxn=1e5+5;
int n,m,a,L,R,pos;
int op,Op[maxn],rt[maxn];
set<int>s;//存储有序区间的左端点(根结点)方便分裂与合并
struct SegmentTree{
    int lc[N],rc[N],sum[N],rub[N],tot,cnt=0;
     int New(){//内存回收 衡量垃圾桶与点数越界的内存差
        if(cnt)return rub[cnt--];
        return ++tot;
    }
    void del(int&p){
        ls=rs=sum[p]=0;
        rub[++cnt]=p;
        p=0;
    }
    int merge(int p,int&q,int l,int r){
        if(!p||!q)return p+q;
        sum[p]+=sum[q];
        if(l==r){del(q);return p;}
        int mid=l+r>>1;
        ls=merge(ls,lc[q],l,mid);
        rs=merge(rs,rc[q],mid+1,r);
        del(q);
        return p;
    }
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void update(int&p,int l,int r,int x){
        if(!p)p=New();
        if(l==r){
            sum[p]++;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x);
        else update(rson,x);
        pushUp(p);
    }
    int query(int p,int l,int r){
        if(l==r)return l;
        int mid=l+r>>1;
        if(ls)return query(lson);
        else return query(rson);
    }
    void split(int p,int&q,int k,int op){//把p分裂成左p右q的两个区间 给p留指定的k个
        if(!p)return;//有重复元素的时候叶子也可以是k 防空结点
        if(sum[p]==k)return;
        if(!q)q=New();
        sum[q]=sum[p]-k;sum[p]=k;
        if(op){//1降序找前k大
            if(sum[rs]>=k){
                split(rs,rc[q],k,op);
                lc[q]=lc[p];lc[p]=0;//左边直接断给q
            }else
                split(ls,lc[q],k-sum[rs],op);
        }else{//0升序找前k小
            if(sum[ls]>=k){
                split(ls,lc[q],k,op);
                rc[q]=rc[p];rc[p]=0;
            }else
                split(rs,rc[q],k-sum[ls],op);
        }
    }
}tr;
IT Split(int x){
    auto v=s.lower_bound(x);
    if(*v==x)return v;
    --v;
    Op[x]=Op[*v];//拆分的时候保证前k大还是前k小选择正确
    tr.split(rt[*v],rt[x],x-*v,Op[x]);
    return s.insert(x).first;//插入分裂的区间的新的左端点
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    s.insert(n+1);
    for(int i=1;i<=n;++i){
        cin>>a;
        tr.update(rt[i],1,n,a);
        s.insert(i);
    }
    for(int i=1;i<=m;++i){
        cin>>op>>L>>R;
        auto st=Split(L);
		auto ed=Split(R+1);
        for(auto it=++st;it!=ed;++it){
			rt[L]=tr.merge(rt[L],rt[*it],1,n);
		}
        Op[L]=op;s.erase(st,ed);//最多2个
    }
    cin>>pos;
    Split(pos);Split(pos+1);//分裂成单点 求整个区间每个i分裂一次就好了
    cout<<tr.query(rt[pos],1,n)<<"\n";
    return 0;
}