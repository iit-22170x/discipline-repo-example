#!/bin/bash

rm $2
touch $2

for file in $1/*.txt
do
	echo cd $(basename $file) >> $2
done

sort $2

echo New file has been created