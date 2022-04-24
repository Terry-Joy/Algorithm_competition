#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int is_used[10],answer[10];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j,k,l,f,q,num,sum;bool is_exit=1;
		if(n==0)
		break;
		else
		{
			for(i=1;i<=9;++i)
				for(j=0;j<=9;++j)
					for(k=0;k<=9;++k)
						for(l=0;l<=9;++l)
							for(f=0;f<=9;++f)
							{
								memset(is_used,0,sizeof(is_used));
								is_used[i]++;
								is_used[j]++;
								is_used[k]++;
								is_used[l]++;
								is_used[f]++;				
								num=i*10000+j*1000+k*100+l*10+f;
								sum=num;
								if(num%n==0)
								{
									num=num/n;
									while(num>0)
									{	
										int p=1;
										q=num%10;
										answer[p]=q;
										p++;
										is_used[q]++;
										num/=10;				
									}
									for(int z=0;z<=9;++z)
									{
										if(is_used[z]>=2||is_used[z]<=0)
										is_exit=0;
										break;
									}	
									if(is_exit!=0)
									{
									cout<<num<<"/"<<answer[5]<<answer[4]<<answer[3]<<answer[2]<<answer[1]<<" = "<<n<<endl;
									}
								}
								else continue;	
							}
			 if(is_exit==0)
				cout<<"There are no solutions for "<<n<<"."<<endl<<endl;
		   	else 
				cout<<num<<"/"<<answer[5]<<answer[4]<<answer[3]<<answer[2]<<answer[1]<<" = "<<n<<endl;
		}
	}
	return 0;
} 
