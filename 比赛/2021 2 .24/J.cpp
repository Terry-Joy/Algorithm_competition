#include<bits/stdc++.h>

using namespace std;
const int maxn=1e6+5;
char s[maxn];
int Q,k,q[maxn],t,h,sum[maxn];
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;++i)
        sum[i]=sum[i-1]+(s[i]=='1');
    scanf("%d",&Q);
    while(Q--){
        h=1,t=0;
        int ans=0;
        scanf("%d",&k);
        q[++t]=0;
        for(int i=1;i<=len;++i){
            while(h<=t&&q[t]-2*sum[q[t]]>i-2*sum[i])t--;
                q[++t]=i;
            while(h<=t&&sum[q[t]]-sum[q[h]]>k)h++;
            if(h<=t)ans=max(ans,i-2*sum[i]-(q[h]-2*sum[q[h]])+k);
        }
        printf("%d\n",min(ans,len-sum[len]));
    }
    return 0;
}