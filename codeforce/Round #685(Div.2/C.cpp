#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char a[maxn],b[maxn];
int main(void){
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        scanf("%s %s",a+1,b+1);
        int num1[26]={0},num2[26]={0};
        for(int i=1;i<=n;i++){
            num1[a[i]-'a']++;
            num2[b[i]-'a']++;
        }
        int flg=0;
        int sum=0;
        for(int i=0;i<26;i++){ 
            sum+=num1[i];
            if(sum<num2[i]){
                flg=1; break;
            }
            sum-=num2[i];
            if(sum%k){
                flg=1;break;
            }
        }
        if(flg)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}