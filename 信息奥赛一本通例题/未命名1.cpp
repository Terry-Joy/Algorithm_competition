#include<iostream>
using namespace std;
int main()
{
	int b[][4]={1,2,3,4,5};
 int(*a)[4]=b;
 cout<<a+1<<" "<<*(a+1);
	return 0;
}
