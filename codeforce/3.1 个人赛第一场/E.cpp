
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
char str1[maxn],str2[maxn];
 
int main()
{
	int l=0,r=0;
	scanf("%s",str1);
	scanf("%s",str2);
	int len=strlen(str1);
	for(int i=0;i<len;i++)
	{
		if(str1[i]!=str2[i])
		{
			l=i;
			break;
		}
	}
	for(int i=len-1;i>=0;i--)
	{
		if(str1[i]!=str2[i])
		{
			r=i;
			break;
		}
	}
	reverse(str2+l,str2+r+1);
	int flag=1;
	for(int i=0;i<len;i++)
	{
		if(str1[i]!=str2[i])
		{
			flag=0;
			break;
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
}

