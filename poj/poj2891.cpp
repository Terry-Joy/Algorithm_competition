#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
#define ll long long 
using namespace std;
const int maxn=100010;
int n;
ll ai[maxn],bi[maxn];

ll mul(ll a,ll b,ll mod)
{
    ll res=0;
    while(b>0)
    {
        if(b&1) res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res;
}

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0){x=1;y=0;return a;}
    ll gcd=exgcd(b,a%b,x,y);
    ll tp=x;
    x=y; y=tp-a/b*y;
    return gcd;
}

ll excrt()
{
    ll x,y,k;
    ll M=bi[1],ans=ai[1];//��һ�����̵Ľ����� M=lcm(m1,...mn),ans���ǽ� 
    for(int i=2;i<=n;i++)
    {
        ll a=M,b=bi[i],c=((ai[i]-ans)%b+b)%b;//ax��c(mod b)
        ll gcd=exgcd(a,b,x,y),bg=b/gcd;
        if(c%gcd!=0) return -1; //�ж��Ƿ��޽⣬Ȼ��������ʵ����

        x=mul(x,c/gcd,bg);//exgcd���x�Ľ� 
        ans+=x*M;//�ӷ�����ǰk��������Ĵ�
        M*=bg;//MΪǰk��m��lcm
        ans=(ans%M+M)%M;
    }
    return (ans%M+M)%M;
}

int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
   		scanf("%lld%lld",&bi[i],&ai[i]);
   	printf("%lld",excrt()); 
   	return 0;
}
