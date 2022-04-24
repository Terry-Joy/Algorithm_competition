#include<bits/stdc++.h>
using namespace std;
using INT=__int128;
const int maxn=(1<<18)+5;
const INT INF=(INT)9e18*9e18;
int n,p[20],q[20];
INT f[(1<<18)+5][2],limit[2],c;
template<class T>
bool mn(T&x,const T&y){ 
    if(x>y){ x=y;return 1;}
    return 0;
}
void print(INT A){ 
    if(A<0)putchar('-'),A=-A;
    if(A>=10)print(A/10);
    putchar(A%10+48);
}
void dfs(int pos,int st,INT sum,bool s){ 
    if(pos>=n){ 
        if(sum>=limit[s])
         mn(f[st][s],sum-limit[s]);
        return;   
    }
    for(int i=0;i<=q[pos];++i){ 
        dfs(pos+1,(i==q[pos])?(st|(1<<pos)):st,sum,s);
        sum*=p[pos];
    }
}
__int128 read(){ 
    char c=getchar();__int128 x=0;
    while(c<'0'||c>'9'){ c=getchar();}
    while(c>='0'&&c<='9'){ x=x*10+c-'0';c=getchar();}
    return x;
}
int main(){ 
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d%d",&p[i],&q[i]);
    INT num=1;
    for(int i=0;i<n;++i)
        for(int j=1;j<=q[i];++j){ 
            num*=p[i];
        }
    limit[0]=read();limit[1]=read();
    for(int i=0;i<(1<<n);++i)
        f[i][0]=f[i][1]=INF;
    for(int i=0;i<2;++i)
        dfs(0,0,1,i);
    for(int k=0;k<2;++k)
        for(int i=(1<<n)-1;i>=0;--i)
            for(int j=0;j<n;++j){ 
                if(i&(1<<j)){ 
                    mn(f[i^(1<<j)][k],f[i][k]);
                }
        }
    INT ans=2*num;
    for(int i=0;i<(1<<n);++i) 
        mn(ans,f[i][0]+f[((1<<n)-1)^i][1]);
    print(ans);
    return 0;
}


