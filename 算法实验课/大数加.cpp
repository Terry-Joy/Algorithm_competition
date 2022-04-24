#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
char s1[maxn],s2[maxn];
int a[maxn],b[maxn],ans[maxn];
int main(){
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    int len1=strlen(s1+1),len2=strlen(s2+1);
    reverse(s1+1,s1+len1+1);reverse(s2+1,s2+len2+1);
    for(int i=1;i<=len1;++i)a[i]=s1[i]-'0';
    for(int i=1;i<=len2;++i)b[i]=s2[i]-'0';
    for(int i=1;i<=max(len1,len2);++i){
        int tmp=a[i]+b[i];
        ans[i]=ans[i]+tmp%10;
        if(tmp>=10)ans[i+1]=1;
    }
    for(int i=max(len1,len2);i>=1;--i){
        cout<<ans[i];
    }
    return 0;
}