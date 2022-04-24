# TLE的正确率

### Description

众所周知，TLE是全集训队最菜的选手，交题的正确率一直都是全队最低的，假如现在他的正确率是$a/b$的话，他希望自己的正确率能够达到$c/d$, 他至少要再交几次才能使得自己的正确率**恰好**为$c/d$呢, 请你帮帮$TLE$。

### Input Description

输入第一行数据组数$T$ $1\leq T\leq100000$,

接下来$T$行，每一行有4个整数$a$,$b$,$c$,$d$，$0 \leq a \leq b \leq 10^9$, $0 \leq c \leq d\leq 10^9$，保证$b>0$且$d>0$且$c/d$是最简分式。

### Output Description

输出包括$T$行，每一行包括一个整数，表示

最少提交的次数，假如正确率无法恰好为$c/d$, 输出$-1$。

### Input Sample

2<br>3 4 1 1<br>3 10 1 2

### Output Sample

-1<br>4

