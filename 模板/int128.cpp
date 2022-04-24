void print(__int128 A){ 
    if(A<0)putchar('-'),A=-A;
    if(A>=10)print(A/10);
    putchar(A%10+48);
}
__int128 read(){ 
    char c=getchar();__int128 x=0;
    while(c<'0'||c>'9'){ c=getchar();}
    while(c>='0'&&c<='9'){ x=x*10+c-'0';c=getchar();}
    return x;
}