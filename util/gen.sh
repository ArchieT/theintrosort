#!/bin/bash
for i in $(seq $2);
do 
	echo $RANDOM >> $1;
	if ! (( i % 2048 )); 
	then
		echo $i $(( $2 - $i ));
	fi;
done
