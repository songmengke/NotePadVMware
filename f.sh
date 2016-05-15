#!/bin/bash
f[0]=1
f[1]=1
for((i=2;i<10;i=i+1))
do
	f[i]=$((f[i-1]+f[i-2]))
done

for((j=0;j<10;j=j+1))
do
	echo -e ${f[j]}" \c"
	if test $(((j+1)%2)) = 0
	then
		echo -e ""
	fi
done
