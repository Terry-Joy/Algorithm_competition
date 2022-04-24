#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
typedef long long ll;
int n,len,nxt[maxn];
char s[maxn];
void getKmp(){
    for(int i=2,j=0;i<=len;++i){
        while(j&&(s[i]!=s[j+1]))j=nxt[j];
        if(s[i]==s[j+1])j++;
        nxt[i]=j;
    }
}
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    len=strlen(s+1);
    getKmp();
    ll ans=0;
    for(int i=1;i<=len;++i){
        int j=i;
        while(nxt[j])j=nxt[j];
        if(nxt[i]!=0)nxt[i]=j;//记搜
        ans+=(i-j);
    }
    cout<<ans;
    return 0;
}