#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char s1[maxn],s2[maxn],st[maxn],tmp[maxn];
int nxt[maxn],len1,len2;
void getKmp(){
    for(int i=2,j=0;i<=len2;++i){
        while(j&&(s2[i]!=s2[j+1]))j=nxt[j];
        if(s2[i]==s2[j+1])j++;
        nxt[i]=j;
    }
}
int getLen(int fi,int se){
    int num=0;
    for(int i=fi;i<=se;++i)tmp[++num]=st[i];
    for(int i=1,j=0;i<=num;++i){
        while(j&&(tmp[i]!=s2[j+1]))j=nxt[j];
        if(tmp[i]==s2[j+1])j++;
        if(i==num)return j;
    }
}
int main(){
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    len1=strlen(s1+1);
    len2=strlen(s2+1);
    getKmp();
    int cnt=1,i=0,j=0;
    while(cnt<=len1){
        st[++i]=s1[cnt++];
        while(j&&(j==len2||st[i]!=s2[j+1]))j=nxt[j];
        if(st[i]==s2[j+1])j++;
        if(j==len2){
            int ll=getLen(max(i-2*(len2-1),0),max(i-len2,0));
            i=max(0,i-len2);j=ll;
        }
    }
    for(int f=1;f<=i;++f)putchar(st[f]);
    return 0;
}