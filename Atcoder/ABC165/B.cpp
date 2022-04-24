#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=2e5+5;
char s[maxn];
int main(){
    scanf("%s",s);
    int sum=0;
    for(int i=0;i<strlen(s);++i){
        sum+=(s[i]-'0');
    }
    if(sum%9==0)puts("Yes");
    else puts("No");
    return 0;
}