#include<bits/stdc++.h>
using namespace std;
const int mod=1000003;
int t,n,g[55][26],f[55][(1<<15)+10];
char s[16][55];
int Add(int x,int y){ 
    x+=y;
    if(x>=mod)x-=mod;
    return x;
}
int main(){ 
    int n,k;
    cin>>t;
    while(t--){ 
        cin>>n>>k;
        for(int i=0;i<n;++i)
            cin>>(s[i]+1);
        int len=strlen(s[0]+1);
        int lim=(1<<n);
        for(int i=1;i<=len;++i)
            memset(g[i],0,sizeof(g[i]));
        for(int i=1;i<=len;++i){ 
            for(int j=0;j<26;++j){ 
                int now=0;
                for(int k=0;k<n;++k){ 
                    if(s[k][i]=='?'||(s[k][i]-'a'==j))
                        now|=(1<<k);
                }
                g[i][j]=now;
            }
        }
        for(int i=0;i<=len;++i)
            for(int j=lim-1;j>=0;--j)f[i][j]=0;
        f[0][lim-1]=1;
        for(int i=0;i<len;++i){ 
            for(int j=lim-1;j>=0;--j){ 
                for(int k=0;k<26;++k){ 
                    f[i+1][j&(g[i+1][k])]=Add(f[i+1][j&(g[i+1][k])],f[i][j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<lim;++i){ 
            int sum=0;
            for(int j=0;j<n;++j){ 
                if(i&(1<<j))sum++;
            }
            if(sum==k)ans=Add(ans,f[len][i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
