#include<bits/stdc++.h>
using namespace std;
char s1[10000],s2[10000];
int cnt=0;
void dfs(int l,int r){
    if(l>r)return;
    cnt++;
    if(l==r){
        putchar(s2[l]);
        return;
    }
    int rt=cnt;
    for(int i=l;i<=r;++i){
        if(s2[i]==s1[rt]){
            dfs(l,i-1);
            dfs(i+1,r);
            break;
        }
    }
    putchar(s1[rt]);
}

int main(){
    while(~scanf("%s%s",s1+1,s2+1)){
        cnt=0;
        int len1=strlen(s1+1),len2=strlen(s2+1);
        dfs(1,len1);
        puts("");
    }
    return 0;
}