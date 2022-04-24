#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#define ll long long

using namespace std;
const int maxn=2e5+10;
char s[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int flag=0;
    int len=strlen(s);
    for(int i=0;i<len;++i)
    {
       if(s[i]=='(')
       {
          flag++;
          cout<<flag%2; 
       } 
       else{ 
        cout<<flag%2;
        flag--;
       }
    }
    return 0;
}
