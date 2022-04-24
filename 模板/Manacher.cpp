#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char s[11000002];
char s_new[21000002];//������ַ�����ַ��� 
int p[21000002];

int Init() {//�γ��µ��ַ��� 
    int len=strlen(s);//len�������ַ����ĳ���
    s_new[0]='$';//����߽磬��ֹԽ�� 
    s_new[1]='#';
    int j=2; 
    for(int i=0;i<len;i++) {
        s_new[j++]=s[i];
        s_new[j++]='#';
    } 
    s_new[j]='\0';//����߽磬��ֹԽ�磨�������ǣ� 
    return j;// ����s_new�ĳ��� 
}

int Manacher() {//��������Ĵ� 
    int len=Init();//ȡ�����ַ����ĳ��ȣ� �����s_new��ת��
    int max_len=-1;//����ĳ���
    int id;
    int mx=0;
    for(int i=1;i<=len;i++) {
        if(i<mx)
            p[i]=min(p[2*id-i],mx-i);//����ͼƬ��������Ľ��� 
        else p[i]=1;
        while(s_new[i-p[i]]==s_new[i+p[i]])//����߽��жϣ���Ϊ����'$'������'\0'��ǣ�
            p[i]++;//mx�Դ˻����е�Ĺ����Ѿ�����������������Ѱ������뾶
        if(mx<i+p[i]) {//ÿ���ƶ�һ�������е㣬��Ҫ��mx�Ƚϣ�ʹmx��������p[i]=min(p[2*id-i],mx-i)Ч�� 
            id=i;//����id 
            mx=i+p[i];//����mx 
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
