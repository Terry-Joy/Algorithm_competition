#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int n,t,premx[maxn],premn[maxn],sufmx[maxn],sufmn[maxn],m,val[maxn];
char s[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n>>m;
        cin>>s;
        int len=strlen(s);
        val[0]=0;
        for(int i=0;i<len;++i){ 
            if(s[i]=='-')val[i+1]=val[i]-1;
            else val[i+1]=val[i]+1;
        }
        for(int i=1;i<=n;++i){ 
            premx[i]=max(premx[i-1],val[i]);
            premn[i]=min(premn[i-1],val[i]);
        }
        sufmx[n]=val[n];sufmn[n]=val[n];
        for(int i=n-1;i>=1;--i){ 
            sufmx[i]=max(sufmx[i+1],val[i]);
            sufmn[i]=min(sufmn[i+1],val[i]);
        }
        int l,r;
        for(int i=1;i<=m;++i){ 
            cin>>l>>r;
            int x1=val[l-1],x2=val[r];
            int mn=1e9,mx=-1e9;
                if(x1==x2){ 
                    mx=max(premx[l-1],sufmx[r]);
                    mn=min(premn[l-1],sufmn[r]);
                }else if(x1>x2){ 
                    mx=max(premx[l-1],sufmx[r]+(x1-x2));
                    mn=min(premn[l-1],sufmn[r]+(x1-x2));
                }else if(x2>x1){ 
                    mx=max(premx[l-1],sufmx[r]+(x1-x2));
                 mn=min(premn[l-1],sufmn[r]+(x1-x2));
                }
            cout<<mx-mn+1<<"\n";
        }
    }
    return 0;
}
