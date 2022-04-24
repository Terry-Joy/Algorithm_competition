#include<iostream>
using namespace std;
int main()
{
	int a,b,c,num;
	while(cin>>a>>b>>c&&(a+b+c)!=0)
	{
		int num=0;
		for(int i=0;;++i)
		{
			if(i%2==0)
			{
				a-=b;
				num++;
				if(a<=0)
				{
				cout<<num<<endl;
				break;
				}
				if(a+c<b&&a>0)
				{
					cout<<num+2<<endl;
					break;
				}
			}
			if(i%2==1)
			{
				a+=c;
				num++;
			}
			
			
		}
	}
	return 0;
}
