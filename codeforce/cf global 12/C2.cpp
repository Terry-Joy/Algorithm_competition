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
        int num0=0,num1=0,num2=0;
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=n;++j){ 
                if(s[i][j]=='X'){ 
                    if((i+j)%3==0)ans0++;
                    else if((i+j)%3==1)ans1++;
                    else if((i+j)%3==2)ans2++;
                }else if(s[i][j]=='O'){ 
                    if((i+j)%3==0)num0++;
                    else if((i+j)%3==1)num1++;
                    else if((i+j)%3==2)num2++;
                }
            }
        }
        int flag=-1,k=-1;
        int a1=ans0+num1,a2=ans0+num2,a3=ans1+num0,a4=ans1+num2;
        int a5=ans2+num0,a6=ans2+num1;
        if(a1<=a2&&a1<=a3&&a1<=a4&&a1<=a5&&a1<=a6)flag=1;
        else if(a2<=a1&&a2<=a3&&a2<=a4&&a2<=a5&&a2<=a6)flag=2;
        else if(a3<=a1&&a3<=a2&&a3<=a4&&a3<=a5&&a3<=a6)flag=3;
        else if(a4<=a1&&a4<=a2&&a4<=a3&&a4<=a5&&a4<=a6)flag=4;
        else if(a5<=a1&&a5<=a2&&a5<=a3&&a5<=a4&&a5<=a6)flag=5;
        else if(a6<=a1&&a6<=a2&&a6<=a3&&a6<=a4&&a6<=a5)flag=6;
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=n;++j){ 
                if(s[i][j]=='X'){ 
                    if(flag==1){ 
                        if((i+j)%3==0)s[i][j]='O';
                    }else if(flag==2){ 
                        if((i+j)%3==0)s[i][j]='O';
                    }else if(flag==3){ 
                        if((i+j)%3==1)s[i][j]='O';
                    }else if(flag==4){ 
                        if((i+j)%3==1)s[i][j]='O';
                    }else if(flag==5){ 
                        if((i+j)%3==2)s[i][j]='O';
                    }else if(flag==6){ 
                        if((i+j)%3==2)s[i][j]='O';
                    }
                }
                else if(s[i][j]=='O'){ 
                    if(flag==1){ 
                        if((i+j)%3==1)s[i][j]='X';
                    }else if(flag==2){ 
                        if((i+j)%3==2)s[i][j]='X';
                    }else if(flag==3){ 
                        if((i+j)%3==0)s[i][j]='X';
                    }else if(flag==4){ 
                        if((i+j)%3==2)s[i][j]='X';
                    }else if(flag==5){ 
                        if((i+j)%3==0)s[i][j]='X';
                    }else if(flag==6){ 
                        if((i+j)%3==1)s[i][j]='X';
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
