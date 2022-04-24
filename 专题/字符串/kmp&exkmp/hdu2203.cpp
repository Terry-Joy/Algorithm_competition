#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s1[maxn*2],s2[maxn],s3[maxn];
int len1,len2,nxt[maxn*2];
bool getKmp(){
    for(int i=2,j=0;i<=len2;++i){
        while(j&&s2[i]!=s2[j+1])j=nxt[j];
        if(s2[i]==s2[j+1])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=len1;++i){
        while(j&&(j==len2||s1[i]!=s2[j+1]))j=nxt[j];
        if(s1[i]==s2[j+1])j++;
        if(j==len2)return 1;
    }
    return 0;
}
int main(){
    while(~scanf("%s%s",s1+1,s2+1)){
        len1=strlen(s1+1),len2=strlen(s2+1);
        if(len1<len2){
            puts("no");
        }else{
            strcpy(s3+1,s1+1);
            strcat(s1+1,s3+1);
            len1=strlen(s1+1);
            puts(getKmp()?"yes":"no");
        }
    }
    return 0;
}