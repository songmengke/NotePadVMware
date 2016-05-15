#!/bin/bash
read n
num=$((n-2))

if test $num = 0
then
	echo -e "@@\n@@"
else 
	echo -e  "@\c"
	for((i=0;i<$num;i=i+1))
	do
		echo -e "+\c"
	done
	echo  "@"

	for((j=0;j<$num;j=j+1))
	do
		echo -e "&\c"
		for((i=0;i<$num;i=i+1))
		do
			echo -e " \c"
		done
		echo "&"
	done
	echo -e "@\c"
	for((i=0;i<$num;i=i+1))
	do
		echo -e "+\c"
	done
	echo -e "@\n"
fi
