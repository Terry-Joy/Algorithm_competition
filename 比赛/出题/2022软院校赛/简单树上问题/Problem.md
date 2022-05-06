# 简单树上问题

### Description

给定一颗$n$个点的树，树上有$n - 1$条边，每条边上都有边权, 现在定义树上$i$和$j$两点的$f(i, j)$为$i$点和$j$点最短路径权值上的最大值，树上某点$i$的幸福度$g(i) = \sum\limits_ {j = 1} ^ {n} f(i, j)$,  $ TLE$想知道，树上每个点的$g(i)$到底是多少，你能帮$TLE$解决这个简单的问题吗？

### Input Description

输入第一行包括一个整数$n$, $1 \leq n \leq 2\times10^5$, 表示给定树的节点数。
接下来$n-1$行每行三个整数$u_i$和$v_i$和$w_i$，表示树上点$u_i$和$v_i$之间有一条权值为$w_i$的边，$1 \leq u_i, v_i, \leq n, u_i\neq v_i, 1 \leq w_i \leq 10^6$。


### Output Description

输出包括$n$行，每行包括一个整数$a_i$，表示第$i$个节点对应的$g(i)$值。

### Input Sample

6<br>1 2 1<br>1 3 3<br>2 4 2<br>3 5 2<br>3 6 2

### Output Sample

12<br>12<br>13<br>13<br>13<br>13

