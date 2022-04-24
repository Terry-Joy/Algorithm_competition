#include<bits/stdc++.h>
using namespace std; 
char s1[105], s2[105];
int n,pos1,pos2,val,num;
int main()
{
	scanf("%d",&n);
    pos1 = 0,val=n,num=1;
    while(val > 0){
        s1[pos1++] = '0' + num;
        val -= num;
        if(val<0){  pos1 = 0;break;}
        num = 3 - num;
    }
    s1[pos1] = 0;
    int pos2 = 0,val=n,num=2;
    	while(val> 0){
        	s2[pos2++] = '0' + num;
        	val -= num;
        	if(val<0){pos2=0;break;}
    		num = 3 - num;
	}
    s2[pos2] = 0;
    if(pos1 != pos2){
        puts(pos1 > pos2 ? s1 : s2);
    }
    else{
        puts(strcmp(s1, s2) > 0 ? s1 : s2);
    }
	return 0;
}
