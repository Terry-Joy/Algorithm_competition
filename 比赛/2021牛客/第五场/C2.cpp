#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
const int mod=998244353;
int sumW[maxn],sumL[maxn],cntW,cntL,posL[maxn],posW[maxn];
int equ[maxn],n;
char s[maxn];
int main(){ 
    cin>>n;
    cin>>(s+1);
    for(int i=1;i<=n;++i){ 
        if(s[i]=='W'){ 
            sumW[i]=sumW[i-1]+1;
            sumL[i]=sumL[i-1];
            posW[++cntW]=i;
        }else{
            sumW[i]=sumW[i-1];
            sumL[i]=sumL[i-1]+1;
            posL[++cntL]=i;
        }
    }
    for(int i=n+1;i>=1;--i){ 
        if(i>=n)
            equ[i]=n+1;
        else
            equ[i]=(s[i]==s[i+1])?i+1:equ[i+2];
    }
    int ans=0,win;
    for(int i=1,num=1;i<=n;++i,num=(ll)num*(n+1)%mod){ 
        win=0;
        for(int l=1,r;l<=n;l=r+1){ 
            int nxtW=(cntW-sumW[l-1]>=i)?posW[sumW[l-1]+i]:n+1;
            int nxtL=(cntL-sumL[l-1]>=i)?posL[sumL[l-1]+i]:n+1;
            if(nxtW==n+1&&nxtL==n+1){//分不出
                r=n;
            }else if(nxtW<nxtL){ 
                if(i-(sumL[nxtW]-sumL[l-1])>=2)//第i个已经赢了
                    r=nxtW,win++;
                else if(nxtW==n)//分不出
                    r=n;
                else if(nxtW+1!=nxtL){//加一场就赢了
                    r=nxtW+1,win++;
                }else{ 
                    int pos=equ[nxtW+2];
                    if(pos==n+1)r=n;
                    else r=pos,win+=(s[pos]=='W');//破平局
                } 
            }else{ 
                if(i-(sumW[nxtL]-sumW[l-1])>=2)
                    r=nxtL;
                else if(nxtL==n)
                    r=n;
                else if(nxtL+1!=nxtW)
                    r=nxtL+1;
                else{ 
                    int pos=equ[nxtL+2];
                    if(pos==n+1)r=n;
                    else r=pos,win+=(s[pos]=='W');
                }
            }
        }
        ans=(ans+(ll)win*num%mod)%mod;
    }
    cout<<ans;
    return 0;
}
        
