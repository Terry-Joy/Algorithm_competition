# TLE的正确率(题解)

两种做法

+ $O(logn)$二分
+ 我们设再提交总次数为$B$，其中正确次数为$A$, 对于$\frac{a+A}{b+B}=\frac {c}{d}$, 由于$c,d$互质，所以显然若有解，存在一个整数$k$, 满足$kc=a+A$, $kd=b+B$, 合法的解必须满足，$0\leq kc-a\leq kd-b$，我们可以发现这两个函数具有单调性，即假如一个$k$不满足，则大于这个$k$的值$k'$也不会满足，所以二分$k$，判断上面的条件是否成立即可，二分的上界也可以由这个式子推导出$k\leq \frac{a-b}{c-d}$，所以二分边界右端点不超过$1e9$,  我们可以稍微扩大这个范围，假如最后落到超过$1e9$的范围，则说明无解



+ $O(1)$推式子

  其实本质和上面的没什么区别，$0\leq kc-a\leq kd-b $，所以可以得出$k\ge max(\lceil\frac{a}{c} \rceil,\lceil\frac{b-a}{d-c}  \rceil)$, 注意这种写法得特判$c$是否为0且$d==c$，

