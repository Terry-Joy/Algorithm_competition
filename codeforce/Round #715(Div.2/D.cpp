#include<bits/stdc++.h>
#define fi first 
#define se second
#define pb push_back
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int n,t,cnt0,cnt1,cnt;
char s1[maxn],s2[maxn],s3[maxn];
pair<int,int>sum[5];
vector<int>ans;
int main(){
    scanf("%d",&t);
    while(t--){
        ans.clear();
        bool f=0;
        cnt=0;
        scanf("%d",&n);
        scanf("%s%s%s",s1+1,s2+1,s3+1);
        int num0=0,num1=0;
        for(int i=1;i<=2*n;++i){
            if(s1[i]=='0')num0++;else num1++;
        }
        if(num0==num1){
            cnt0++;cnt1++;
        }else if(num0>num1)cnt0++;
        else cnt1++;
        num0=num1=0;
        for(int i=1;i<=2*n;++i){
            if(s2[i]=='0')num0++;else num1++;
        }
        if(num0==num1){
            cnt0++;cnt1++;
        }else if(num0>num1)cnt0++;
        else cnt1++;
        num0=num1=0;
        for(int i=1;i<=2*n;++i){
            if(s3[i]=='0')num0++;else num1++;
        }
        if(num1>=num0){
            num0=0;num1=0;
            for(int i=1;i<=2*n;++i){
                if(s1[i]=='0')num0++;else num1++;
            }
            sum[++cnt]={1,num1-num0};
            num0=0;num1=0;
            for(int i=1;i<=2*n;++i){
                if(s2[i]=='0')num0++;else num1++;
            }
            sum[++cnt]={2,num1-num0};
            num0=0;num1=0;
            for(int i=1;i<=2*n;++i){
                if(s3[i]=='0')num0++;else num1++;
            }
            sum[++cnt]={3,num1-num0};
            f=1;
        }else{
            num0=0;num1=0;
            for(int i=1;i<=2*n;++i){
                if(s1[i]=='0')num0++;else num1++;
            }
            sum[++cnt]={1,num0-num1};
            num0=0;num1=0;
            for(int i=1;i<=2*n;++i){
                if(s2[i]=='0')num0++;else num1++;
            }
            sum[++cnt]={2,num0-num1};
            num0=0;num1=0;
            for(int i=1;i<=2*n;++i){
                if(s3[i]=='0')num0++;else num1++;
            }
            sum[++cnt]={3,num0-num1};
            f=0;
        }
        sort(sum+1,sum+1+cnt);
        reverse(sum+1,sum+1+cnt);
        int id1=sum[1].fi,id2=sum[2].se;
        int i=1;j=1;
        while(i<=2*n&&j<=2*n){
            if()
        }
    }
    return 0;
}