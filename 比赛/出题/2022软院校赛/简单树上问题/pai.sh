#!/bin/bash
a=100
cnt=0
for ((i = 1; i <= a; i++));
do
	./r > data.in 
	./std < data.in > std.out
	./bao < data.in > baoli.out
	if diff baoli.out std.out; then 
		printf "AC\n"
		cnt=cnt+1
	else 
		printf "Wa\n"
		exit 0 
	fi
done
printf("%d组, 正确的有%d ", a, cnt)