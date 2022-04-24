#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll A,B,p;
const int HashMod=123456;
struct HashTable
{
	struct Line{int u,v,next;}e[1000000];
	int h[HashMod],cnt;
	void Add(int u,int v,int w){e[++cnt]=(Line){w,v,h[u]};h[u]=cnt;}
	void Clear(){memset(h,0,sizeof(h));cnt=0;}
	void Hash(int x,int k){
		int s=x%HashMod;
		Add(s,k,x);
	}
	int Query(int x){
		int s=x%HashMod;
		for(int i=h[s];i;i=e[i].next)
			if(e[i].u==x)return e[i].v;
		return -1;
	}
}Hash;
ll mypow(ll a,ll b,ll p){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
int BSGS(int A,int B,int p)
{
	if(A%p==0){return -1;}
	A%=p;B%=p;
	if(B==1){return 0;}
	int m=sqrt(p)+1;
    Hash.Clear();
	for(int i=0,t=B;i<m;++i,t=1ll*t*A%p)Hash.Hash(t,i);
	for(int i=1,tt=mypow(A,m,p),t=tt;i<=m+1;++i,t=1ll*t*tt%p){
		int k=Hash.Query(t);if(k==-1){continue; };
		return i*m-k;
	}
    return -1;
}
ll exgcd(ll a,ll b,ll &x,ll &y){ 
    if(!b){ x=1,y=0;return a;}
    ll d=exgcd(b,a%b,x,y);
    ll z=x;x=y;y=z-y*(a/b);
    return d;
}
int main(){ 
    int t,k;
    scanf("%d%d",&t,&k);
    while(t--){ 
        scanf("%lld%lld%lld",&A,&B,&p);
        if(k==1)
            cout<<mypow(A,B,p)<<"\n";
        else if(k==2){ 
            ll x=0,y=0;
            ll GCD=exgcd(A,p,x,y);
            if(B%GCD!=0)puts("Orz, I cannot find x!");
            else{ 
                ll tmp=p/GCD;
                cout<<(((x*B)/GCD)%tmp+tmp)%tmp<<"\n";
            }
        }else{ 
            ll x=BSGS(A,B,p);
            if(x==-1)puts("Orz, I cannot find x!");
            else cout<<x<<"\n";
        }
    }
    return 0;
}
