#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char s1[maxn],s2[maxn];
int nxt[maxn],len1,len2,f[maxn],ans=0;
void getKmp(){
    nxt[1]=0;
    for(int i=2,j=0;i<=len2;++i){
        while(j&&s2[i]!=s2[j+1])j=nxt[j];
        if(s2[i]==s2[j+1])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=len1;++i){
        while(j&&(j==len2||s1[i]!=s2[j+1]))j=nxt[j];
        if(s1[i]==s2[j+1])j++;
        f[i]=j;
        if(f[i]==len2)ans++;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%s",s2+1);
        scanf("%s",s1+1);
        len1=strlen(s1+1);
        len2=strlen(s2+1);
        getKmp();
        cout<<ans<<"\n";
    }
    return 0;
}  