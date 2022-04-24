//区间排序后输出某点值

#include<bits/stdc++.h>
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define N maxn*40
using namespace std;
typedef set<int>::iterator IT;
const int maxn=1e5+5;
int n,m,L,R,pos;
int op,Op[maxn],val[100];
char a[maxn],mp[150];
set<int>s;//存储有序区间的左端点(根结点)方便分裂与合并
struct SegmentTree{
    int rt[maxn],lc[N],rc[N],sum[N],rub[N],tot,cnt=0;
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
    	if(!p)return 0;
        if(l==r)return l;
        int mid=l+r>>1;
        if(ls)return query(lson);
        else return query(rson);
    }
    void split(int p,int&q,int k,int op){//把p分裂成左p右q的两个区间 给p留指定的k个
 		if(!p)return;//有重复值，必须加
        if(sum[p]==k)return;
        if(!q)q=New();
        sum[q]=sum[p]-k;sum[p]=k;
        if(!op){//1降序找前k大
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
    tr.split(tr.rt[*v],tr.rt[x],x-*v,Op[x]);
    return s.insert(x).first;//插入分裂的区间的新的左端点
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>(a+1);
    s.insert(n+1);
    for(int i=97;i<=97+26-1;++i)val[i-'a']=i-'a'+1;
	for(int i=97;i<=97+26-1;++i)mp[i]=i;	
    for(int i=1;i<=n;++i){
        tr.update(tr.rt[i],1,26,val[a[i]-'a']);
        s.insert(i);
    }
    for(int i=1;i<=m;++i){
        cin>>L>>R>>op;
        auto st=Split(L);
		auto ed=Split(R+1);
        for(auto it=++st;it!=ed;++it){
			tr.rt[L]=tr.merge(tr.rt[L],tr.rt[*it],1,26);
		}
        Op[L]=op;s.erase(st,ed);
    }
    for(int i=1;i<=n;++i){
		Split(i); 
	}
	for(int i=1;i<=n;++i) 
		cout<<mp[(tr.query(tr.rt[i],1,26)+96)];
    return 0;
}