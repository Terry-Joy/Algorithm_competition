#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char s[11000002];
char s_new[21000002];//存添加字符后的字符串 
int p[21000002];

int Init() {//形成新的字符串 
    int len=strlen(s);//len是输入字符串的长度
    s_new[0]='$';//处理边界，防止越界 
    s_new[1]='#';
    int j=2; 
    for(int i=0;i<len;i++) {
        s_new[j++]=s[i];
        s_new[j++]='#';
    } 
    s_new[j]='\0';//处理边界，防止越界（容易忘记） 
    return j;// 返回s_new的长度 
}

int Manacher() {//返回最长回文串 
    int len=Init();//取得新字符串的长度， 完成向s_new的转换
    int max_len=-1;//最长回文长度
    int id;
    int mx=0;
    for(int i=1;i<=len;i++) {
        if(i<mx)
            p[i]=min(p[2*id-i],mx-i);//上面图片就是这里的讲解 
        else p[i]=1;
        while(s_new[i-p[i]]==s_new[i+p[i]])//不需边界判断，因为左有'$'，右有'\0'标记；
            p[i]++;//mx对此回文中点的贡献已经结束，现在是正常寻找扩大半径
        if(mx<i+p[i]) {//每走移动一个回文中点，都要和mx比较，使mx是最大，提高p[i]=min(p[2*id-i],mx-i)效率 
            id=i;//更新id 
            mx=i+p[i];//更新mx 
        }
        max_len=max(max_len,p[i]-1); 
    } 
    return max_len; 
}
 
int main()
{
    scanf("%s",&s);
    printf("%d",Manacher());
    return 0;
}
