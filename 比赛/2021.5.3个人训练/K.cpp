#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
char s[maxn];
int cnt1[27],cnt2[27];
int main(){
    char c;
    while((c=getchar())){
        if(c==' ')continue;
        if(c=='\n')break;
        cnt1[c-'a']++;
    }
    while((c=getchar())){
        if(c==' ')continue;
        if(c=='\n')break;
        cnt2[c-'a']++;
    }
    for(int i=0;i<26;++i){
        if(cnt1[i]!=cnt2[i]){
            putchar(i+'a');
        }
    }
    return 0;
}