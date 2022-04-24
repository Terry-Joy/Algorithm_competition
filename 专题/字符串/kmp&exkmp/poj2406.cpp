#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
int len,nxt[maxn];
void getKmp(){
    for(int i=2,j=0;i<=len;++i){
        while(j&&s[i]!=s[j+1])j=nxt[j];
        if(s[i]==s[j+1])j++;
        nxt[i]=j;
    }   
}
int main(){
    while(~scanf("%s",s+1)&&s[1]!='.'){
        len=strlen(s+1);
        getKmp();
        int n=len;
        if(n%(n-nxt[len])==0){
            cout<<n/(n-nxt[len])<<"\n";
        }else puts("1");
    }
    return 0;
}