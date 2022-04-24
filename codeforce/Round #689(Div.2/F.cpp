#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int>P;
typedef long long ll;
const int maxn=1e5+5;
int n,a[maxn],cnt=0,posL[maxn],posR[maxn],pre[maxn];//pre[i]表示第i的上一个加号在pre[i]以前
char s[5];
ll dp[maxn],c[maxn];
map<char,int>mp;
vector<P>pos;
char ans[maxn];
void solve(int l,int r){ 
    if(l>r)return;
    ll mul=1,sum=0;
    int l1=l-1;
    cnt=0;
    for(int i=l;i<=r;++i){ 
        if(a[i]==1){ 
            if(l1+1<=i-1)posL[++cnt]=l1+1,posR[cnt]=i-1,c[cnt]=mul;//前面至少有一个非1的时候
            mul=1;l1=i;
        }
        else{ 
            mul*=a[i];
            if(mul>9e5)mul=9e5;
        }
    } 
    if(l1!=r)posL[++cnt]=l1+1,posR[cnt]=r,c[cnt]=mul;//尾部还有
    for(int i=1;i<=cnt;++i)dp[i]=0;
    mul=1;
    posR[0]=l-1;//边界
    for(int i=1;i<=cnt;++i){ 
        mul*=c[i];//i与cnt
        if(mul>9e5)mul=9e5;
    }
    if(mul==9e5)pre[cnt]=1;
    else{ 
        for(int i=1;i<=cnt;++i){ 
            mul=1;
            for(int j=i;j>=1;--j){ 
                mul*=c[j];
                if(dp[i]<dp[j-1]+posL[j]-posR[j-1]-1+mul){ 
                    dp[i]=dp[j-1]+posL[j]-posR[j-1]-1+mul;
                    pre[i]=j;
                }
            }
        }
    }
    for(int i=l+1;i<=posL[1];++i)ans[i]='+';
    for(int i=posR[cnt]+1;i<=r;++i)ans[i]='+';
    int k=cnt;
    while(k){ 
        int x=pre[k];
        for(int i=posR[x-1]+1;i<=posL[x];++i)ans[i]='+',k=x-1;
    }

}
int main(){
    scanf("%d",&n); 
    for(int i=1;i<=n;++i)scanf("%d",&a[i]); 
    a[0]=a[n+1]=0;
    scanf("%s",s+1);
    mp['+']=-3;mp['-']=1;mp['*']=2;
    int len=strlen(s+1),flag=0;
    for(int i=1;i<=len;++i){ 
        flag+=mp[s[i]];
    }
    if(flag==-2||flag==-3||flag==1||flag==2){ 
        cout<<a[1];
        if(n==1)return 0;
        else{ 
            if(flag==-3||flag==-2){ 
                for(int i=2;i<=n;++i)
                    putchar('+'),printf("%d",a[i]);
            }else if(flag==1){ 
                for(int i=2;i<=n;++i)
                    putchar('-'),printf("%d",a[i]);
            }else if(flag==2){ 
                for(int i=2;i<=n;++i)
                    putchar('*'),printf("%d",a[i]);
            }
        }
    }
    else if(flag==3){ 
        bool is=0;
        cout<<a[1];
        for(int i=2;i<=n;++i){ 
            if(!a[i]&&!is)is=1,putchar('-');
            else putchar('*');
            cout<<a[i];
        }
    }else if(flag==-1||flag==0){ 
        int h=1,l=0,r=0;
        for(;;){ 
            if(a[h]&&a[h-1]==0)l=h;
            if(a[h]&&a[h+1]==0)r=h;
            if(l&&r){ 
                pos.pb({l,r});
                l=0;r=0;
            }
            h++;
            if(h>n)break;
        }
        for(auto&v:pos){ 
            solve(v.fi,v.se);
        }
        for(int i=2;i<=n;++i){
            if(!a[i])ans[i]='+',ans[i+1]='+';
        }
        cout<<a[1];
        for(int i=2;i<=n;++i){ 
            if(ans[i]=='+')putchar('+');
            else putchar('*');
            cout<<a[i];
        }
    }   
    return 0;
}
