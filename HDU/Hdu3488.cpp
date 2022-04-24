#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=210,NPOS=-1;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct Matrix
{
    int n;
    ll a[N][N];
};
struct KuhnMunkres:Matrix
{
    ll hl[N],hr[N],slk[N];
    int fl[N],fr[N],vl[N],vr[N],pre[N],q[N],ql,qr;
    int check(int i)
    {
        if(vl[i]=1,fl[i]!=NPOS)return vr[q[qr++]=fl[i]]=1;
        while(i!=NPOS)swap(i,fr[fl[i]=pre[i]]);
        return 0;
    }
    void bfs(int s)
    {
        fill(slk,slk+n,INF);
        fill(vl,vl+n,0);
        fill(vr,vr+n,0);
        q[ql=0]=s;
        vr[s]=qr=1;
        for(ll d;;)
        {
            for(; ql<qr; ++ql)
                for(int i=0,j=q[ql]; i<n; ++i)
                    if(d=hl[i]+hr[j]-a[i][j],!vl[i]&&slk[i]>=d)
                        if(pre[i]=j,d)slk[i]=d;
                        else if(!check(i))return;
            d=INF;
            for(int i=0; i<n; ++i)
                if(!vl[i]&&d>slk[i])d=slk[i];
            for(int i=0; i<n; ++i)
            {
                 if(vl[i])hl[i]+=d;
                else slk[i]-=d;
                if(vr[i])hr[i]-=d;
            }
            for(int i=0; i<n; ++i)
                if(!vl[i]&&!slk[i]&&!check(i))return;
        }
    }
    void ask()
    {
        fill(pre,pre+n,NPOS);
        fill(fl,fl+n,NPOS);
        fill(fr,fr+n,NPOS);
        fill(hr,hr+n,0);
        for(int i=0; i<n; ++i)hl[i]=*max_element(a[i],a[i]+n);
        for(int j=0; j<n; ++j)bfs(j);
    }
} km;
int main()
{
    int n,nl,nr ,m;
    int QAQ,kase=0;
    scanf("%d",&QAQ);
    while(QAQ--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                    km.a[i][j]=-INF;
        for(int i=1;i<=m;++i)
        {
           ll x,y,z;
           scanf("%lld%lld%lld",&x,&y,&z);
           km.a[x-1][y-1]=max(km.a[x-1][y-1],-z);
        }
        nl=n,nr=n;
        km.n=max(nl,nr);
        km.ask();
        long long ans=0;
        for(int i=0; i<nl; ++i)
            if(km.fl[i]!=NPOS)
                 ans+=km.a[i][km.fl[i]];
        printf("%lld\n",-ans);
    }
}
