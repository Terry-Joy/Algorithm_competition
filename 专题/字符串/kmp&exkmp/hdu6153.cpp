#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
const int mod=1e9+7;
int n,nxt[maxn],t,len1,len2;
ll dp[maxn];
char s1[maxn],s2[maxn];
void getKmp(){
    for(int i=2,j=0;i<=len2;++i){
        while(j&&s2[i]!=s2[j+1])j=nxt[j];
        if(s2[i]==s2[j+1])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=len1;++i){
        while(j&&(j==len2||s1[i]!=s2[j+1]))j=nxt[j];
        if(s1[i]==s2[j+1])j++;
        dp[j]++;
    }
    for(int i=len2;i>=1;--i){
        dp[nxt[i]]+=dp[i];
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s1+1);
        scanf("%s",s2+1);
        len1=strlen(s1+1);len2=strlen(s2+1);
        memset(dp,0,sizeof(dp));//len1不一定等于len2!!
        reverse(s1+1,s1+1+len1);
        reverse(s2+1,s2+1+len2);
        getKmp();
        ll ans=0;
        for(int i=1;i<=len2;++i){
            ans+=1ll*dp[i]*i;
            ans%=mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}