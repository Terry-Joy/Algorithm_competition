#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e6+5;
bool v[maxn];
int prime[maxn/10],cnt=0;
ll c,d,e,f;
void init()
{
    v[1]=1;
    int k=maxn-5;
    for(int i=2;i<=k;++i) {
        if(!v[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<=k;++j){ 
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}

int gcd(int a,int b){ return b?gcd(b,a%b):a;}

ll exgcd(int a,int b,ll &x,ll &y){ 
    if(!b){ x=1,y=0;return a;}
    int d=exgcd(b,a%b,x,y);
    int z=x;x=y;y=z-y*(a/b);
    return d;
}
ll solve(ll a,ll b,ll c,ll &x,ll &y){ 
    ll GCD=exgcd(a,b,x,y);
    if(c%GCD){ 
        x=y=-1;
        return -1;
    }
    x*=(c/GCD);
    y*=(c/GCD);
    return 0;
}
int main()
{
   init();
   int t;
   scanf("%d",&t);
   while(t--){ 
       int a,b,GCD;
       scanf("%d%d",&a,&b);
       if((GCD=(gcd(a,b)))!=1)
       	   printf("%lld %lld %lld %lld\n",(a/GCD+1),b/GCD,1,b/GCD);
       else{ 
           if(b==1||v[b]==0){ 
               puts("-1 -1 -1 -1");
               continue;
           }
           int bb=b,time=0,tmp=0;
           for(int i=1;i<=cnt&&prime[i]*prime[i]<=b;++i){ 
                if(bb%prime[i]==0){ 
                    tmp=prime[i];
                    while(bb%prime[i]==0)
                        bb/=prime[i],time++;
                    break;
                } 
           }
           if(bb==1){ 
               puts("-1 -1 -1 -1");
               continue;
           }
           d=1;
           for(int i=1;i<=time;++i)d*=tmp;
           f=bb;
           c=e=0;
           solve(f,d,a,c,e);
           if(c<0&&e>0)
              printf("%lld %lld %lld %lld\n",e,f,-c,d);
           else 
              printf("%lld %lld %lld %lld\n",c,d,-e,f); 
       } 
   } 
   return 0; 
}
