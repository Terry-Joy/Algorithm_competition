#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
char s1[maxn],s2[maxn];
int len1,pre,len2,f[maxn],nxt[maxn],ans;
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
        if(f[i]==len2){ans++;j=0;}
    }
}
int main(){
    while(~scanf("%s",s1+1)&&s1[1]!='#'){
        ans=0;
        scanf("%s",s2+1);
        len1=strlen(s1+1);
        len2=strlen(s2+1);
        getKmp();
        pre=0;
        //for(int i=1;i<=len1;++i){
        //    if(f[i]==len2&&i-len2+1>pre)ans++,pre=i;
        //}
        cout<<ans<<"\n";
    }    
    return 0;
}