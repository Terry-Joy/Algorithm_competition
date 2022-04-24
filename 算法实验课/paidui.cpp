#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
 
	int a[1000],b[0100],n,m;
	scanf("%d%d",&n,&m);
	int i,sum=0;
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		for(i=0;i<m;i++)
		b[i]=a[i];
		for(i=m;i<n;i++)
		b[i]=b[i-m]+a[i];
		for(i=0;i<n;i++)
		sum=sum+b[i];
		printf("%d\n",sum);
}