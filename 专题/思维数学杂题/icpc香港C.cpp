#include<bits/stdc++.h>

using namespace std;
const int maxn=5e4+5;
int n,a[maxn],b[maxn],ansAL[maxn],ansBL[maxn],ansAR[maxn],ansBR[maxn];
int RA,RB,LA,LB,L,R;
double ansL,ansR;
const double K=log(3)/log(2);
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>n;
    RA=RB=-2000;
    LA=LB=-RA;
    ansL=1e9;
    ansR=-1e9;
    for(int i=1;i<=n;++i){ 
        cin>>a[i]>>b[i];
        RA=max(RA,a[i]);
        RB=max(RB,b[i]);
        LA=min(LA,a[i]);
        LB=min(LB,b[i]);
        double tmp=a[i]+K*b[i];
        if(ansL>tmp)ansL=tmp,L=i;
        if(ansR<tmp)ansR=tmp,R=i;
    }
    for(int i=0,j=n-1;i<=n-1;++i,--j){ 
        if(!i)cout<<RA<<" "<<RB<<" "<<RA<<" "<<RB<<endl;
        else if(!j)cout<<LA<<" "<<LB<<" "<<LA<<" "<<LB<<endl;
        else{ 
            cout<<((j==1)?a[R]:RA)<<" "<<((j==1)?b[R]:RB)<<" "<<((i==1)?a[L]:LA)<<" "<<((i==1)?b[L]:LB)<<endl;
        }
    }
    return 0;
}
