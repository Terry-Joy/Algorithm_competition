#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    char str1[105],str2[105],str3[105];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        map<char,int>h;
        map<char,int>hou;
     scanf("%s%s%s",str1,str2,str3);
     int len1=strlen(str1);
    int len2=strlen(str2);
    for(int i=0;i<len1;i++)
    {
      h[str1[i]]++;
    }
    for(int i=0;i<len2;i++)
    {
      hou[str2[i]]++;
    }
    int flag=0;
    for(int i=0;i<26;i++)
    {
        if(h['a'+i]>hou['a'+i])
        {
            flag=1;
            break;
        }
        else
        {
            hou['a'+i]=hou['a'+i]-h['a'+i];
        }
    }
    if(flag==1)//如果s串中有比t串中多的，一定不行
    {
        printf("NO\n");
    }
    else
    {
        int k1=0;
        for(int i=0;i<len2;i++)
        {
            if(str2[i]==str1[k1])
            k1++;
            if(k1==len1)
            break;
        }
        if(k1!=len1)
        {
            printf("NO\n");//s串中的顺序一定跟t串一样
            continue;
        }
 
        int len3=strlen(str3);
         map<char,int>k;
        for(int i=0;i<len3;i++)
        {
          k[str3[i]]++;
        }
        for(int i=0;i<26;i++)
        {
            if(k['a'+i]<hou['a'+i])//看看第三个串能不能补上第一个
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        printf("NO\n");
        else
        printf("YES\n");
 
    }
    }
}
