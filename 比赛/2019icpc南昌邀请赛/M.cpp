#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int dp[maxn][26],n,pos;
char s[maxn],t[maxn];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<=len;++i)
        for(int j=0;j<26;++j)
            dp[i][j]=-1;
    for(int i=len-1;i>=0;--i){
        for(int j=0;j<26;++j){
            dp[i][j]=dp[i+1][j];
        }
        dp[i][s[i]-'a']=i;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%s",t);
        int len2=strlen(t);
        pos=0;
        bool f=1;
        for(int j=0;j<len2;++j){
            pos=dp[pos][t[j]-'a'];
            if(pos==-1){f=0;break;}
            pos++;
        }
        puts(f?"YES":"NO");
    }
    return 0;
}