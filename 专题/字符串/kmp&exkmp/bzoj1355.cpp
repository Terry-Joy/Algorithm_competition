#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int nxt[maxn],n,len;
char s[maxn];
void getKmp(){
    for(int i=2,j=0;i<=len;++i){
        while(j&&s[i]!=s[j+1])j=nxt[j];
        if(s[i]==s[j+1])j++;
        nxt[i]=j;
    }
}
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    len=strlen(s+1);
    getKmp();
    cout<<len-nxt[len]<<"\n";
    return 0;
}