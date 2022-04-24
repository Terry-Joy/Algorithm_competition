#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n;
char s[310][310];
int main(){
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%s",s[i]+1);
        int ans0=0,ans1=0,ans2=0;
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=n;++j){ 
                if(s[i][j]=='X'){ 
                    if((i+j)%3==0)ans0++;
                    else if((i+j)%3==1)ans1++;
                    else if((i+j)%3==2)ans2++;
                }
            }
        }
        int flag=-1;
        if(ans0<=ans1&&ans0<=ans2)flag=0;
        else if(ans1<=ans0&&ans1<=ans2)flag=1;
        else if(ans2<=ans0&&ans2<=ans1)flag=2;
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=n;++j){ 
                if(s[i][j]=='X'){ 
                    if(!flag){ 
                        if((i+j)%3==0)s[i][j]='O';
                    }else if(flag==1){ 
                        if((i+j)%3==1)s[i][j]='O';
                    }else if(flag==2){ 
                        if((i+j)%3==2)s[i][j]='O';
                    }
                }
            }
        }
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=n;++j){ 
                cout<<s[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
