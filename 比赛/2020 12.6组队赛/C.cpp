#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200010;
int n,m,op,x,y,tot,t,tail;
int fa[maxn];
bool tf[maxn];
ll d,c2[maxn];
struct Q{ 
    int l,r,rt,size;
    ll mid;
}q[maxn];
struct Node{
    int lc,rc,dis;
    ll val;
}tr[maxn];
bool cmp(const Node&a,const Node&b){ return a.val<b.val;}
int merge(int x,int y){
    if(!x||!y)return x+y;
    if(tr[x].val<tr[y].val)swap(x,y);
    tr[x].rc=merge(tr[x].rc,y);
    if(tr[tr[x].lc].dis<tr[tr[x].rc].dis)swap(tr[x].lc,tr[x].rc);
    tr[x].dis=tr[tr[x].rc].dis+1;
    return x;
}
void init(){ 
    for(int i=1;i<=n;++i)tr[i]={ 0,0,0,0};
    tail=0;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        init();
        cin>>n>>d;
        for(int i=1;i<=n;++i)cin>>tr[i].val;
        sort(tr+1,tr+1+n,cmp);
        for(int i=1;i<=n;++i){ 
            tr[i].val-=1ll*d*(i-1);
            q[++tail]={i,i,i,1,tr[i].val};
            if(i==1)continue;
            while(tail>1&&q[tail-1].mid>q[tail].mid){ 
                tail--;
                q[tail].r=q[tail+1].r;
                q[tail].rt=merge(q[tail].rt,q[tail+1].rt);
                q[tail].size+=q[tail+1].size;
                while(q[tail].size>(q[tail].r-q[tail].l+1+1)/2){ 
                    q[tail].size--;
                    q[tail].rt=merge(tr[q[tail].rt].lc,tr[q[tail].rt].rc);
                }
                q[tail].mid=tr[q[tail].rt].val;
            }
        }
        int t=1;
        ll ans=0;
        for(int i=1;i<=n;++i){ 
            tr[i].val+=d*(i-1);
            while(t<tail&&i>q[t].r)t++;
            c2[i]=q[t].mid+d*(i-1);
            if(c2[i]<0)c2[i]=0;
            if(i>1&&c2[i]-c2[i-1]<d)c2[i]+=c2[i-1]+d-c2[i];
            ans+=abs(tr[i].val-c2[i]);
        }
        cout<<ans<<"\n";
    }
}
