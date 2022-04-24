#include<bits/stdc++.h>
#define lson p<<1
#define rson p<<1|1
#define ls p<<1&1
#define rs p<<1+1
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int t,len1,len2;
char ww[maxn];
int main()
{
    scanf("%d",&t);
    while(t--){ 
        scanf("%s",ww+1);
        int sum=strlen(ww+1);
        len1=len2=0;
        int tmp=strlen(ww+1);
        for(int i=tmp;i>=1;--i){ 
            if(len1!=0&&ww[i]=='B'){ 
                    len2++;
                    len1=0;
            }
            else if(ww[i]=='A'){ 
                len1++;
                if(len2>0){ 
                    sum-=2;
                    len1--;len2--;
                } 
            }else{ 
                if(ww[i]=='B'){ 
                    len2++;
                }
            }
        }
        while(len2>=2){ 
            sum-=2;
            len2-=2;
        }
        printf("%d\n",sum);
    }
	return 0;
}

