#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
const int maxm=4e4+5;
const ll mod=1e14;
bool v[maxn];
int prime[maxn],cnt=0,t,a[maxm];
ll f[maxm<<1],f2[maxm<<1];
ll c[maxm][32],P,c2[maxm][32];
bool is[maxm][32],ismod[maxm<<1];
ll phi(ll x){ 
    ll ans=x;
    for(int i=1;1ll*prime[i]*prime[i]<=x&&i<=cnt;++i){ 
        if(x%prime[i]==0){ 
            ans-=ans/prime[i];
            while(x%prime[i]==0)x/=prime[i];
        }
    }
    if(x>1)ans-=ans/x;
    return ans;
}
void init(){ 
    for(int i=2;i<maxn;++i){ 
        if(!v[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){ 
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=0;i<=maxm-5;++i){ 
        c2[i][0]=1;
        for(int j=1;j<=min(i,30);++j){ 
            c2[i][j]=c2[i-1][j-1]+c2[i-1][j];
            if(c2[i][j]>=mod)c2[i][j]-=mod;  
        }
    }
}
void init2(ll phi,int k,int n){ 
    c[0][0]=1;
    for(int i=1;i<=30;++i)c[i][i]=1;
    for(int i=0;i<=n;++i){ 
        c[i][0]=1;
        for(int j=1;j<=min(i,k);++j){ 
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            if(c[i][j]>=phi){ 
                c[i][j]-=phi;
            }
        }
    }
}
ll mul(ll a,ll b,ll mod){ 
    return __int128(a)*b%mod;
}
ll mypow(ll a,ll b){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=mul(ans,a,P);
        a=mul(a,a,P);
        b>>=1;
    }
    return ans;
}
void read(int &num)
{
	num=0;
	char ch=getchar();
	while (ch<48 || ch>57) ch=getchar();
	while (ch>=48 && ch<=57) num=num*10+ch-48,ch=getchar();
}
void readll(ll &num)
{
	num=0;
	char ch=getchar();
	while (ch<48 || ch>57) ch=getchar();
	while (ch>=48 && ch<=57) num=num*10+ch-48,ch=getchar();
}
int main(){ 
    init();
	read(t);
    int s,k;
    while(t--){ 
		read(s);
		read(k);
		readll(P);
        int mx=0;
        ll x=phi(P);
        init2(x,k,s);
        for(int i=1;i<=s;++i){ 
            read(a[i]);
			mx=max(mx,a[i]);
            f[a[i]]++;
        }
        for(int i=1;i<=mx;++i){ 
            for(int j=2*i;j<=mx;j+=i)
                f[i]+=f[j];
        }
        for(int i=1;i<=mx;++i)f2[i]=c2[f[i]][k],f[i]=c[f[i]][k];
        int M=(mx+1)/2;
        for(int i=M;i>=1;--i){ 
            for(int j=2*i;j<=mx;j+=i){ 
                f[i]-=f[j];
                if(f[i]<0)
                    f[i]+=x;
                f2[i]-=f2[j];
                if(f2[i]<0)
                    f2[i]+=mod;
            }   
        }
        ll ans=1;
        for(int i=1;i<=mx;++i){ 
            if(f[i]!=f2[i])f[i]+=x;
                ans=mul(ans,mypow(i,f[i]),P);
        }
        for(int i=1;i<=mx;++i)f[i]=f2[i]=0;
        cout<<ans<<"\n";
    }
    return 0;
}

