#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char s1[maxn],s2[maxn];
int nxt[maxn],f[maxn],len;
void getKmp(){
    nxt[1]=0;
    for(int i=2,j=0;i<=len;++i){
        while(j&&s2[i]!=s2[j+1])j=nxt[j];
        if(s2[i]==s2[j+1])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=len;++i){
        while(j&&(j==len||s1[i]!=s2[j+1]))j=nxt[j];
        if(s1[i]==s2[j+1])j++;
        f[i]=j;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    int T=0;
    while(t--){
        scanf("%s",s1+1);
        strcpy(s2+1,s1+1);
        len=strlen(s1+1);
        reverse(s2+1,s2+1+len);
        getKmp();
        cout<<"Case "<<++T<<": "<<len+len-f[len]<<"\n";
    }
    return 0;
}