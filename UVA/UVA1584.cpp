#include<iostream>
#include<cstring>
using namespace std;
char st[110];
char sn[110];

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		cin>>st;
		int k=strlen(st);
		for(int i=1;i<=k-1;++i)
		{
			for(int s=i;s<k;++s)
				sn[s-i]=st[s];
			int j=k-i;
			while(j<k)  
				for(int g=0;g<i;++g)
				{
					sn[j]=st[g];
					j++;
				}
			if(strcmp(st,sn)>0)
				for(int q=0;q<k;q++)
					st[q]=sn[q];
		}
		for(int i=0;i<k;++i)
			cout<<st[i];
		putchar('\n');
		
	}
	return 0;
}
