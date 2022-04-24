#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int n,t,pre[maxn];
char s[maxn];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        int cnt=0;
        for(int i=1;i<=n;++i)pre[i]=pre[i-1]+(s[i]=='T');
        bool f=1;
        for(int i=1;i<=n;++i){
            if(s[i]=='M'){
                if(pre[i-1]<cnt+1){
                    f=0;
                }
                cnt++;
            }
        }
        if(cnt*3!=n)f=0;
        cnt=0;
        for(int i=n;i;--i){
            if(s[i]=='M'){
                if(pre[n]-pre[i]<cnt+1){
                    f=0;break;
                }
                cnt++;
            }
        }
        puts(f?"YES":"NO");
    }
    return 0;
}