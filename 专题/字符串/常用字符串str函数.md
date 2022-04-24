+ strcpy(s1,s2)   

  s2复制到s1（覆盖）

+ strncpy(s1,s2,n) 

  将字符串str2中的前n个字符复制到字符串str1的前n个字符中,不覆盖

+ strcat(s1,s2)  

  将s2的尾部添加到s1的尾部

  strncat(s1,s2,n)

  将s2前n个加到s1尾部

  strcmp(s1,s2)

  相等返回0，大于正，小于负数，若一直相同，长度长的大

  strncmp(s1,s2)

  比较s1s2前n个字符

  strchr(s1,c)

  从前往后首次出现c

  strrchr(s1,c)

  从后往前首次出现c

  

  strstr(s1,s2)

  s1中找s2中首次出现位置，找到返回指针，否则NULL

  ```cpp
  char s1[maxn]="0helloword",s2[maxn]="word"  
  char *d=strstr(s1+1,s2);
      cout<<d-s1<<"\n";
  找到下标
  ```

  不要自己传自己一堆bug，还有要注意里面的起点到底是s1+1,还是s1

  