//terryjoy 
#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define push_back pb
#define insert ins
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>PI;
int t,a,b;
const int maxn=5005;
ll f[maxn][maxn];
char s1[maxn],s2[maxn];
int main(){ 
    scanf("%d%d",&a,&b);
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    //for(int i=0;i<strlen(s1);++i)cout<<s1[i];
    //for(int i=0;i<strlen(s2);++i)cout<<s2[i];
    int k=max(a,b);
    for(int i=0;i<=k;++i)f[i][0]=f[0][i]=0;
    ll num=0;
    for(int i=1;i<=a;++i){ 
        for(int j=1;j<=b;++j){ 
            if(s1[i]!=s2[j]){ 
                f[i][j]=max(f[i-1][j-1]-2,0ll);
                f[i][j]=max(f[i-1][j]-1,f[i][j]);
                f[i][j]=max(f[i][j-1]-1,f[i][j]);
                //if(i==1&&j==1)
                //cout<<f[i][j]<<endl;
                //
            }
            else
                f[i][j]=max(2ll,f[i-1][j-1]+2);
            num=max(num,f[i][j]);
            //cout<<num<<endl;
            //if(i==a&&j==b)cout<<f[i][j]<<endl;
        }
    }
    //for(int i=1;i<=a;++i){ 
    //    for(int j=1;j<=b;++j){ 
    //          cout<<f[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    printf("%lld\n",num);
    return 0;
}
//7 7
//uiibwws
//qhtkxcn
