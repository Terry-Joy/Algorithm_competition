#include<bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
using ll=long long;
const int maxn=2e5+5;
int n,m,c[maxn],v[maxn],pre[maxn],col[maxn];
set<int>preS[maxn];
//set<int>Pos[maxn];
vector<int>tmpCol;
vector<int>Colsum[maxn];
struct SegmentTree{
    int mx[maxn<<2];
    ll sum[maxn<<2];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
        mx[p]=max(mx[ls],mx[rs]);
    }
    void build(int p,int l,int r){
        if(l==r){
            mx[p]=pre[l];
            sum[p]=v[l];
            return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    int query(int p,int l,int r,int L,int R,int ps){
        if(mx[p]<ps)return -1;
        if(l==r)return l;
        int mid=l+r>>1;
		if(L<=mid){
			int res=query(lson,L,R,ps);
			if(res!=-1)return res;
		}
		if(R>mid)return query(rson,L,R,ps);
	}
    ll queryS(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[p];
        int mid=l+r>>1;
        ll ans=0;
        if(L<=mid)ans+=queryS(lson,L,R);
        if(R>mid)ans+=queryS(rson,L,R);
        return ans;
    }
	void update(int p,int l,int r,int x){
		if(l==r){
			mx[p]=pre[l];
			sum[p]=v[l];
			return;
		}
		int mid=l+r>>1;
		if(x<=mid)update(lson,x);
		else update(rson,x);
		pushUp(p);
	}
}tr;   
int best[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>c[i]>>v[i];
    for(int i=1;i<=n;++i){
        pre[i]=col[c[i]];
        col[c[i]]=i;
        preS[c[i]].insert(i);
        //pos[c[i]].insert(i);
    }
    tr.build(1,1,n);
   // for(int i=1;i<=n;++i)cout<<pre[i]<<" ";
    for(int i=1;i<=m;++i){
        int op;
        cin>>op;
        if(op==1){
            int x,cc,vv;
            cin>>x>>cc>>vv;
            auto it=preS[c[x]].upper_bound(x);
            if(it!=preS[c[x]].end())
            {
                pre[*it]=pre[x];
                tr.update(1,1,n,*it);
            }   
            preS[c[x]].erase(x);
            it=preS[cc].upper_bound(x);
            if(it!=preS[cc].end()){
                pre[*it]=x;
                tr.update(1,1,n,*it);
            }
            if(it!=preS[cc].begin()){
                it--;
                pre[x]=*it;
            }else{
                pre[x]=0;
            }
            preS[cc].insert(x);
            c[x]=cc;
            v[x]=vv;
            tr.update(1,1,n,x);
        }else if(op==2){
            int s,k;
            cin>>s>>k;
			int fir=tr.query(1,1,n,s,n,s);
			if(fir==-1)fir=n+1;
            for(int j=1;j<=k&&fir<=n;++j){//找了k个空后还能再找!!
				if(Colsum[c[fir]].empty()){
					tmpCol.eb(c[fir]);
					Colsum[c[fir]].eb(v[fir]);
					Colsum[c[fir]].eb(v[pre[fir]]);
				}else{
					Colsum[c[fir]].eb(v[fir]);
				}            
				if(fir+1<=n)fir=tr.query(1,1,n,fir+1,n,s);
				else fir=-1;
				if(fir==-1){
					fir=n+1;
					break;
				}
			}
            ll ans=tr.queryS(1,1,n,s,fir-1);
            for(auto&u:tmpCol){
                sort(Colsum[u].begin(),Colsum[u].end());
                for(int j=0;j<Colsum[u].size()-1;++j){
                    ans-=Colsum[u][j];
                }
            }
            cout<<ans<<"\n";
            for(auto&u:tmpCol){
                Colsum[u].clear();
			}
            tmpCol.clear();
        }
    }
    return 0;
}