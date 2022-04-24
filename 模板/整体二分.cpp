//整体二分带修第k大
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,a[maxn*3],val[maxn*3],b[maxn*3],tot,cnt;
struct BIT{
	#define lowb(i) (i&(-i))
	int c[maxn];
	void add(int x,int val){
		for(int i=x;i<=n;i+=lowb(i))
			c[i]+=val;
	}
	int ask(int x){
		int ans=0;
		for(int i=x;i;i-=lowb(i))
			ans+=c[i];
		return ans;
	}
}bit;
struct Opt {
  int x, y, k, type, id;
  // 对于询问, type = 1, x, y 表示区间左右边界, k 表示询问第 k 小
  // 对于修改, type = 0, x 表示修改位置, y 表示修改后的值,
  // k 表示当前操作是插入(1)还是擦除(-1), 更新树状数组时使用.
  // id 记录每个操作原先的编号, 因二分过程中操作顺序会被打散
}q[maxn*3],q1[maxn*3],q2[maxn*3];
int ans[maxn];
void solve(int l,int r,int ql,int qr){
	if(l>r||ql>qr)return;
	if(l==r){
		for(int i=ql;i<=qr;++i){
			if(q[i].type==1)ans[q[i].id]=l;
		}
		return;
	}
	int cnt1=0,cnt2=0,mid=l+r>>1;
	for(int i=ql;i<=qr;++i){
		if(q[i].type==1){
			int x=bit.ask(q[i].y)-bit.ask(q[i].x-1);
			if(q[i].k<=x)
				q1[++cnt1]=q[i];
			else{
				q[i].k-=x;
				q2[++cnt2]=q[i];
			}
		}else{
			if(q[i].y<=mid){
				bit.add(q[i].x,q[i].k);//贡献给>mid
				q1[++cnt1]=q[i];
			}else{
				q2[++cnt2]=q[i];
			}
		}
	}
	for(int i=1;i<=cnt1;++i){//roll back
		if(!q1[i].type)	
			bit.add(q1[i].x,-q1[i].k);	
	}
	for(int i=1;i<=cnt1;++i)q[i+ql-1]=q1[i];
	for(int i=1;i<=cnt2;++i)q[ql+i+cnt1-1]=q2[i];
	solve(l,mid,ql,ql+cnt1-1);
	solve(mid+1,r,ql+cnt1,qr);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],b[++cnt]=a[i];
	for(int i=1;i<=n;++i){
		q[++tot]={i,a[i],1,0,0};
	}
	char s[2];
	int l,r,k;
	for(int i=1;i<=m;++i)ans[i]=-1;
	for(int i=1;i<=m;++i){
		cin>>s;
		if(s[0]=='Q'){
			cin>>l>>r>>k;
			q[++tot]={l,r,k,1,i};
		}else{//a_l改为k
			cin>>l>>k;
			b[++cnt]=k;
			q[++tot]={l,a[l],-1,0,i};
			a[l]=k;
			q[++tot]={l,k,1,0,i};
		}
	}
	//离散化
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-(b+1);
	for(int i=1;i<=cnt;++i){
		val[i]=b[i];
	}
	for(int i=1;i<=tot;++i){
		if(q[i].type==0)
			q[i].y=lower_bound(b+1,b+1+cnt,q[i].y)-b;
	}

	solve(1,cnt,1,tot);
	for(int i=1;i<=m;++i){
		if(ans[i]!=-1)cout<<val[ans[i]]<<"\n";
	}
	return 0;
}