#include<iostream>
using namespace std;


bool isdigi(int x)
{
	if(x%4==0&&x%100!=0||x%400==0)
	return true;
	else 
	return false; 
}
int main()
{	
int ms[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int y,m;
	while(cin>>y>>m)
	{
	cout<<"Su Mo Tu We Th Fr Sa\n";
	if(isdigi(y))
		ms[2]=29;
	else ms[2]=28;
	int sum=0;
	for(int i=1;i<y;++i)
	{
		if(isdigi(i))
		sum+=366;
		else sum+=365;
	}
	for(int i=1;i<m;++i)
	sum+=ms[i];
	sum+=1;
	int flag=sum%7,sum1=0;
	switch(flag)
	{
		case 0: printf(" 1");sum1=1;break;
			case 1: printf("    1");sum1=2;break;
			case 2: printf("       1");sum1 = 3;break;
			case 3: printf("          1");sum1=4;break;
			case 4: printf("             1");sum1 = 5;break;
			case 5: printf("                1");sum1=6;break;
			case 6: printf("                   1"); sum1=7;break; 



	}
	if(sum1%7==0)
	printf("\n");
	for(int k=2;k<=ms[m];k++)
	{
		sum1++;
		if(sum1%7==0)
		{
			printf(" ");
			if(k>=1&&k<=9)
			printf(" %d\n",k);
			else printf("%d\n",k);
		}
		else if(sum1%7==1)
		{
			if(k>=1&&k<=9)
			printf(" %d",k);
			else 
			printf("%d",k);
		}
		else {
		printf(" "); 
		if(k>=1&&k<=9)
		printf(" %d",k);
		else printf("%d",k);
		}
		
		
	}
	}return 0;
}


