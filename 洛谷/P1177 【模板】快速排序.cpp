#include<iostream>
#include<cstdio>
using namespace std;
void qsort(int a[],int,int);
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;++i)
	scanf("%d",&a[i]);
	qsort(a,0,n-1);
	for(int i=0;i<n;++i)
	{
		if(i!=n-1)
			printf("%d ",a[i]);
		else 
			printf("%d\n",a[i]);
	}
}
void qsort(int a[],int left,int right)
{	
	if(left>right)
	return; 
	int i=left,j=right,mid,temp;
	mid=a[(i+j)/2];
	while(i<j)
	{
		while(a[i]<mid)
		++i;
		while(a[j]>mid)
		--j;
		if(i<=j)
		{
			 temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			++i;--j;
		}
	}
	if(i<right)qsort(a,i,right);
	if(j>left)qsort(a,left,j);
	
}
