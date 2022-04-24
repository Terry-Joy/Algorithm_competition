#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
char s[maxn];
int m,nxt[maxn];
void getKmp(){ 
    nxt[1]=0;
    for(int i=2,j=0;i<=m;++i){ 
        while(j&&s[i]!=s[j+1])j=nxt[j];
        if(s[i]==s[j+1])j++;
        nxt[i]=j;
    }
}
int main(){
    scanf("%s",s+1);
    m=strlen(s+1);
    getKmp();
    for(int i=1;i<=m;++i)cout<<nxt[i]<<" ";
    return 0;
}
