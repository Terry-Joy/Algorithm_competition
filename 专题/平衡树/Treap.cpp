#include<bits/stdc++.h>
#define Rt tr.rt
using namespace std;
const int maxn=1e5+5;
const int INF=2e9;

struct Treap{
	#define ls lc[p]
	#define rs rc[p]
	//rnd 随机值 sz 子树大小 cnt 某节点值出现次数
	int lc[maxn],rc[maxn],val[maxn],rnd[maxn],sz[maxn],cnt[maxn];
	int rt,sumS;
	void pushUp(int p){
		sz[p]=sz[ls]+sz[rs]+cnt[p];
	}
	void lrotate(int&p){
		int t=rs;
		rs=lc[t];
		lc[t]=p;
		sz[t]=sz[p];
		pushUp(p);
		p=t;
	}
	void rrotate(int&p){
		int t=ls;
		ls=rc[t];
		rc[t]=p;
		sz[t]=sz[p];
		pushUp(p);
		p=t;	
	}
	void insert(int&p,int x){//p为根插入x
		if(!p){
			sumS++;
			p=sumS;
			sz[p]=cnt[p]=1;
			val[p]=x;
			rnd[p]=rand();
			return;
		}
		sz[p]++;
		if(val[p]==x){
			cnt[p]++;
		}else if(val[p]>x){
			insert(ls,x);
			if(rnd[ls]<rnd[p])
				rrotate(p);
		}else{
			insert(rs,x);
			if(rnd[rs]<rnd[p])
				lrotate(p);
		}
	}
	bool del(int&p,int x){
		if(!p)return 0;
		if(val[p]==x){
			if(cnt[p]>1){
				cnt[p]--;
				sz[p]--;
				return 1;
			}
			if(!ls||!rs){
				p=ls+rs;
				return 1;
			}else if(rnd[ls]<rnd[rs]){
				rrotate(p);
				return del(p,x);
			}else{
				lrotate(p);
				return del(p,x);
			}
		}else if(val[p]<x){
			bool ok=del(rs,x);
			if(ok)
				sz[p]--;
			return ok;
		}else{
			bool ok=del(ls,x);
			if(ok)
				sz[p]--;
			return ok;
		}
	}
	int qrank(int p,int x){//x数的排名 <算重复 =取最小
		if(!p)return 0;
		if(val[p]==x)
			return sz[ls]+1;
		else if(val[p]<x)
			return sz[ls]+cnt[p]+qrank(rs,x);
		else 
			return qrank(ls,x);
	}
	int qnum(int p,int x){//排名第x的数 算重复
		if(!p)return 0;
		if(sz[ls]>=x)
			return qnum(ls,x);
		else if(sz[ls]+cnt[p]<x)
			return qnum(rs,x-sz[ls]-cnt[p]);
		else return val[p];
	}
	int qPre(int p,int x){//前驱 <x最大数
		if(!p)return -INF;
		if(val[p]>=x)
			return qPre(ls,x);
		else
			return max(val[p],qPre(rs,x));
	}
	int qSuf(int p,int x){//后缀 >x最小数
		if(!p)return INF;
		if(val[p]<=x)
			return qSuf(rs,x);
		else
			return min(val[p],qSuf(ls,x));
	}
}tr;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,op,x;
	cin>>n;
	while(n--){
		cin>>op>>x;
		if(op==1)
			tr.insert(Rt,x);
		else if(op==2)
			tr.del(Rt,x);
		else if(op==3)
			cout<<tr.qrank(Rt,x)<<"\n";
		else if(op==4)
			cout<<tr.qnum(Rt,x)<<"\n";
		else if(op==5)
			cout<<tr.qPre(Rt,x)<<"\n";
		else
			cout<<tr.qSuf(Rt,x)<<"\n";
	}
}