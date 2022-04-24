
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x1,y1,z1,x2,y2,z2;
        scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
        int ans=0;
        ans+=2*min(z1,y2);
        if(z1>min(z1,y2))z1-=min(z1,y2);
        else z1=0;
        if(z2==0||y1==0)cout<<ans<<endl;
        else{
            z2=z2-z1-x1;
            if(z2>0)ans-=2*min(z2,y1);
            cout<<ans<<endl;
        }
    }
    return 0;
}